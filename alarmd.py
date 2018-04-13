#!/usr/bin/python
# coding=utf-8
import subprocess
import datetime
import time
import os
import RPi.GPIO as io
import sys
import requests
import smtplib
import socket
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.image import MIMEImage
def send_alarm(image):
	to='921***025@qq.com'
	gmail_user='qw****123@163.com'
	gmail_password='199****0hao'
	smtpserver=smtplib.SMTP('smtp.163.com',25)
	smtpserver.ehlo()
	smtpserver.starttls()
	smtpserver.ehlo()
	smtpserver.login(gmail_user,gmail_password)
	today=datetime.date.today()
	body = """ 
    <h2>监控照片</h2> 
    <img src="cid:image1"/> 
    """  
	msg_content='Alarm detected.'
	msg = MIMEMultipart(msg_content)  
	msg['Subject']='警报事件 on %s'% today
	msg['From']=gmail_user
	msg['To']= to
	msg.attach(MIMEText(body, 'html', 'utf-8'))  
	with open(image, 'rb') as f:  
		msgImage = MIMEImage(f.read())  
	msgImage.add_header('Content-ID', '<image1>')  
	msg.attach(msgImage)  
	smtpserver.sendmail(gmail_user,[to],msg.as_string())
	smtpserver.quit()


io.setwarnings(False)
io.setmode(io.BCM)

pir_pin=19
flashingLight_pin=7

io.setup(pir_pin, io.IN)

previous_pir=0

while True:
	current_pir=io.input(pir_pin)
	time.sleep(3)
	#send_alarm(mailto_list)
	if previous_pir==0 and current_pir==1:
		with open("/home/pi/Alarm/armed.txt","r") as fo:
			fo.seek(0,0)
			status=fo.read(1)
		fo.closed

		if((status =="1")or(status =="0")):
			subprocess.call("aplay /home/pi/Alarm/motiondetect.wav", shell=True)
			time.sleep(10)
			with open("/home/pi/Alarm/armed.txt","r")as fo:
				fo.seek(0,0)
				status=fo.read(1)
			fo.closed
			if((status =="1")or(status =="0")):
			
				print"Correct passcode not entered, emailing picture and sounding alarm."
				
				os.system('sudo kill -9 $(pidof mjpg_streamer)')
				os.popen('sudo fswebcam -r 640x480 -d /dev/video0 -q /home/pi/Alarm/yeelink/yeelink.jpg')
				todays_date=datetime.datetime.today()
				send_alarm('/home/pi/Alarm/yeelink/yeelink.jpg')  
				image_name=todays_date.strftime('%m-%d-%y-%H%M')
				image_path='/home/pi/Alarm/pictures/'+image_name+'.jpg'
				#os.system("cd ")
				os.system("sudo curl --request POST --data-binary @/home/pi/Alarm/yeelink/yeelink.jpg  --header 'U-ApiKey: 10e3db583be98eb248c30c**5bdb62bd' http://api.yeelink.net/v1.0/device/19**58/sensor/34929/photos")
				#os.system('sudo ../automotion.sh &')
				os.system('sudo sh /home/pi/automotion.sh &')
				#send_alarm(mailto_list)
				print"send email successsful!"
				io.output(flashingLight_pin,io.HIGH)
				subprocess.call("aplay /home/pi/Alarm/alarm.wav", shell=True)
				subprocess.call("aplay /home/pi/Alarm/surrender.wav", shell=True)
				subprocess.call("aplay /home/pi/Alarm/alarm.wav", shell=True)
				io.output(flashingLight_pin,io.LOW)
				del_img=subprocess.Popen("sudo rm -rf  "+image_path, shell=True)
				del_img.wait()
	previous_pir=current_pir
	time.sleep(60)