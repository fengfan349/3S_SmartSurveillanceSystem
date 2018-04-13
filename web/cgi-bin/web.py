#!/usr/bin/python
# -*- coding: UTF-8 -*-

print "Content-type:text/html"
print                               # 空行，告诉服务器结束头部
print '<html>'
print '<head>'
print '<meta charset="utf-8">'
with open("/home/pi/Alarm/zigbee_tem.txt","r")as fo:
	fo.seek(0,0)
	status=fo.read(100)
fo.closed
print '<title>温湿度 </title>' 
print '</head>'
print '<body>'
print '<h2> %s</h2>' % (status)
print '</body>'
print '</html>'