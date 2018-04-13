#!/usr/bin/env python  
# -*- coding: utf-8 -*-  
import requests  
 
import RPi.GPIO as GPIO  
import time  
# 打开 /dev/i2c-1  
#bus = smbus.SMBus(1)  
# 设备URI  
apiurl = 'http://api.yeelink.net/v1.0/device/1****8/sensor/410337/datapoints'  
# 用户密码  
apiheaders = {'U-ApiKey': '10e3db583be98e******cfa5bdb62bd', 'content-type': 'application/json'}  
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(6, GPIO.OUT) 
while True:  
  #发送请求  
	r = requests.get(apiurl,headers=apiheaders)
	# 错误403（云网站拒绝访问）处理
	if r.status_code == 403:
		print('Connection refused!')
		time.sleep(2)
		continue
	led = r.json() 
	# {'value':x} x=1打开状态，x=0关闭状态  
	if led['value'] == 1:  
		GPIO.output(6, GPIO.HIGH)
		print("风扇 开")  
	else:   
		GPIO.output(6, GPIO.LOW)
		print("风扇 关")   
	time.sleep(1)  