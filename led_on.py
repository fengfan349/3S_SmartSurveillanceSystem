# -*- coding: utf-8-*-
# 开灯插件

import logging
import sys
import time
import RPi.GPIO as GPIO  
import subprocess


reload(sys)
sys.setdefaultencoding('utf8')

WORDS = ["KAIDENG"]
SLUG = "led_on"

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(11, GPIO.OUT) 

def handle(text, mic, profile, wxbot=None):
	logger = logging.getLogger(__name__)
	try:
		with open("/home/pi/Alarm/led_status.txt", "r+") as fo:
			fo.seek(0, 0)
			status = fo.read(1)
		fo.closed
		if (status == "0"):
			with open("/home/pi/Alarm/led_status.txt", "r+") as fo:
				fo.seek(0, 0)
				fo.write("1")
			fo.closed
			mic.say('好的，我知道了')
			GPIO.output(11, GPIO.HIGH)
			print("led on") 
			mic.say('灯已打开')
		else:
			mic.say('灯开着呢，逗逼')
	except Exception, e:
		logger.error(e)
		mic.say('抱歉，开灯失败')

def isValid(text):
	return any(word in text for word in [u"开灯", u"打开灯泡"])
