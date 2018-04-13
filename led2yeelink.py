#!/usr/bin/env python  
# -*- coding: utf-8 -*-  
import requests  
#import smbus  
import RPi.GPIO as GPIO  
import time  
# 打开 /dev/i2c-1  
#bus = smbus.SMBus(1)  
# 设备URI  
apiurl = 'http://api.yeelink.net/v1.0/device/19**58/sensor/35231/datapoints'  
# 用户密码  
apiheaders = {'U-ApiKey': '10e3db583be98***248c30cfa5bdb62bd', 'content-type': 'application/json', 'user-agent': 'Mozilla/5.0 (Windows NT 6.2; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.87 Safari/537.36'}  
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(11, GPIO.OUT) 
while True:  
  #发送请求  
	r = requests.get(apiurl,headers=apiheaders)  
	# print(r.status_code)
	if r.status_code == 403:
		print('Connection refused!')
		time.sleep(2)
		continue
	led = r.json() 
	# {'value':x} x=1打开状态，x=0关闭状态  
	if led['value'] == 1:  
		GPIO.output(11, GPIO.HIGH)
		#print("led on 亮")  
	else:   
		GPIO.output(11, GPIO.LOW)
		#print("led off 灭")   
	time.sleep(1)  