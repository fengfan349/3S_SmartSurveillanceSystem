# -*- coding: utf-8-*-
# 温湿度插件

import logging
import sys
import time 
import subprocess


reload(sys)
sys.setdefaultencoding('utf8')

WORDS = ["WENSHIDU"]
SLUG = "WENSHIDUd"


def handle(text, mic, profile, wxbot=None):
	logger = logging.getLogger(__name__)
	try:
		with open("/home/pi/Alarm/zigbee_tem.txt", "r+") as fo:
			fo.seek(0, 0)
			status = fo.read(100)
		fo.closed
		mic.say(status)
	except Exception, e:
		logger.error(e)
		mic.say('抱歉，读取失败')

def isValid(text):
	return any(word in text for word in [u"温湿度", u"室内温湿度"])
