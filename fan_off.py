# -*- coding: utf-8-*-
# 开灯插件

import logging
import sys
import time
import RPi.GPIO as GPIO  
import subprocess


reload(sys)
sys.setdefaultencoding('utf8')

WORDS = ["GUANFENGSHAN"]
SLUG = "fan_off"

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(6, GPIO.OUT) 

def handle(text, mic, profile, wxbot=None):
	logger = logging.getLogger(__name__)
	try:
		with open("/home/pi/Alarm/fan_status.txt", "r+") as fo:
			fo.seek(0, 0)
			status = fo.read(1)
		fo.closed
		if (status == "1"):
			with open("/home/pi/Alarm/fan_status.txt", "r+") as fo:
				fo.seek(0, 0)
				fo.write("0")
			fo.closed
			mic.say('好的，我知道了')
			GPIO.output(6, GPIO.LOW)
			print("fan off") 
			mic.say('风扇已关闭')
		else:
			mic.say('风扇开着呢，逗逼')
	except Exception, e:
		logger.error(e)
		mic.say('抱歉，失败')

def isValid(text):
	return any(word in text for word in [u"关风扇", u"关闭风扇"])
