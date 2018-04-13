# -*- coding: utf-8-*-
# 解除警戒模式插件

import logging
import sys
import time
import RPi.GPIO as GPIO  
import subprocess


reload(sys)
sys.setdefaultencoding('utf8')

WORDS = ["ANQUAN"]
SLUG = "disable alarm mode"

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(10, GPIO.OUT) #Green
GPIO.output(10, GPIO.HIGH)
GPIO.setup(9, GPIO.OUT) #Red
GPIO.output(9, GPIO.LOW)


def handle(text, mic, profile, wxbot=None):
	logger = logging.getLogger(__name__)
	try:
		with open("/home/pi/Alarm/armed.txt", "r+") as fo:
			fo.seek(0, 0)
			status = fo.read(1)
		fo.closed
		if (status == "1"):
			mic.say('好的，我知道了 解除警戒模式')
			with open("/home/pi/Alarm/armed.txt", "r+") as fo:
				fo.seek(0, 0)
				fo.write("0")
			fo.closed
			GPIO.output(9, GPIO.LOW) #Green LED Off
			GPIO.output(10, GPIO.HIGH) #Red LED on
			subprocess.call("sudo aplay /home/pi/Alarm/disarm.wav", shell=True)
		else:
			mic.say('已安全')
	except Exception, e:
		logger.error(e)
		mic.say('抱歉，解除警戒模式失败')

def isValid(text):
	return any(word in text for word in [u"安全", u"安全模式"])
