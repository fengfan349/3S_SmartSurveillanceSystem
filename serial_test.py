# -*- coding: utf-8-*-

import serial  
from time import sleep  
status=''
ser = serial.Serial('/dev/ttyAMA0', 115200, timeout=0.5)   
def recv(serial):    
    while True:    
        data =serial.read(60)    
        if data == '':    
            continue  
        else:  
            break  
        sleep(60)   
    return data    
while True:    
    data =recv(ser) 
    #print data.decode("gbk","ignore").encode("utf-8")
    with open("/home/pi/Alarm/zigbee_tem.txt", "r+") as fo:
	    fo.seek(0, 0)
	    fo.write(data.decode("gbk","ignore").encode("utf-8"))
    fo.closed