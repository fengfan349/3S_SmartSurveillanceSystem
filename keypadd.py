
import RPi.GPIO as GPIO
import time
import subprocess
 
class keypad():  
    KEYPAD = [
    [1,2,3],
    [4,5,6],
    [7,8,2],
    ["*",0,"#"]
    ]
     
    ROW         = [27,23,24,25]
    COLUMN      = [4,17,22]
     
    def __init__(self):
        GPIO.setmode(GPIO.BCM)
     
    def getKey(self):
        for j in range(len(self.COLUMN)):
            GPIO.setup(self.COLUMN[j], GPIO.OUT)
            GPIO.output(self.COLUMN[j], GPIO.LOW)
        for i in range(len(self.ROW)):
            GPIO.setup(self.ROW[i], GPIO.IN, pull_up_down=GPIO.PUD_UP)
        rowVal = -1
        for i in range(len(self.ROW)):
            tmpRead = GPIO.input(self.ROW[i])
            if tmpRead == 0:
                rowVal = i
        if rowVal < 0 or rowVal > 3:
            self.exit()
            return
        for j in range(len(self.COLUMN)):
                GPIO.setup(self.COLUMN[j], GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

        GPIO.setup(self.ROW[rowVal], GPIO.OUT)
        GPIO.output(self.ROW[rowVal], GPIO.HIGH)
        colVal = -1
        for j in range(len(self.COLUMN)):
            tmpRead = GPIO.input(self.COLUMN[j])
            if tmpRead == 1:
                colVal=j
        if colVal < 0 or colVal > 2:
            self.exit()
            return
        self.exit()
        return self.KEYPAD[rowVal][colVal]
         
    def exit(self):
        for i in range(len(self.ROW)):
                GPIO.setup(self.ROW[i], GPIO.IN, pull_up_down=GPIO.PUD_UP) 
        for j in range(len(self.COLUMN)):
                GPIO.setup(self.COLUMN[j], GPIO.IN, pull_up_down=GPIO.PUD_UP)
         
if __name__ == '__main__':
	kp = keypad()
	attempt = "0000"
	passcode ="1993"
	haltcode ="5775"
	with open("/home/pi/Alarm/armed.txt", "r+") as fo:
		fo.seek(0, 0)
		fo.write("0")
	fo.closed
	
	GPIO.setwarnings(False)
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(10, GPIO.OUT) 
	GPIO.output(10, GPIO.HIGH)
	GPIO.setup(9, GPIO.OUT) 
	GPIO.output(9, GPIO.LOW)
	subprocess.call("sudo aplay /home/pi/Alarm/ready.wav", shell=True)

	while True:
		digit = None
		while digit == None:
			digit = kp.getKey()
	 
		print digit
		attempt = (attempt[1:] + str(digit))  
		print attempt

		if (attempt == passcode):
			with open("/home/pi/Alarm/armed.txt", "r+") as fo:
				fo.seek(0, 0)
				status = fo.read(1)
			fo.closed
			if (status == "1"):
				with open("/home/pi/Alarm/armed.txt", "r+") as fo:
					fo.seek(0, 0)
					fo.write("0")
				fo.closed
				GPIO.output(10, GPIO.HIGH) 
				GPIO.output(9, GPIO.LOW) 
				GPIO.output(7, GPIO.LOW)
				subprocess.call("aplay /home/pi/Alarm/disarm.wav", shell=True)
			else:
				GPIO.output(10, GPIO.LOW)
				GPIO.output(9, GPIO.HIGH)
				subprocess.call("sudo aplay /home/pi/Alarm/armed.wav", shell=True)
				time.sleep(10)
				with open("/home/pi/Alarm/armed.txt", "r+") as fo:
					fo.seek(0, 0)
					fo.write("1")
				fo.closed
		elif (attempt == haltcode):
			subprocess.call("sudo aplay /home/pi/Alarm/shutdown.wav", shell=True)
			subprocess.call("halt", shell=True)
		
		time.sleep(0.5)
