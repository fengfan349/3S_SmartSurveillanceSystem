#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys


# 接收字段数据
robot_name_en=sys.argv[1]
robot_name_ch=sys.argv[2]
owner_name=sys.argv[3]
neteasyaccount=sys.argv[4]
neteasypasswd=sys.argv[5] 
netmusicaccount=sys.argv[6]
netmusicpassword = sys.argv[7]
 
print "Content-type:text/html"
print
print "<html>"
print "<head>"
print '<meta charset="utf-8">'
print "<link rel=\"stylesheet\" type=\"text/css\" href=\"../cgi-bin/css/default.css\">"
print "<link rel=\"stylesheet\" type=\"text/css\" href=\"../cgi-bin/css/normal.css\">"
print "<meta http-equiv=\"Cache-Control\" content=\"no-cache\">"
print "<meta http-equiv=\"Pragma\" content=\"no-cache\">"
print "</head>"
print "<body bgcolor=\"PaleTurquoise\">"
print "<form method=\"get\" action=\"/cgi-bin/cgi.cgi\">"
print "<input type=\"hidden\" name=\"CUR_FORM\" value=\"student_info.htm\" size=\"20\" />"
print "<table align=\"center\" class=\"display\" width=\"600px\">"
print "<tr class=\"display_header\">"
print "<th colspan=\"2\">配置信息</th>"
print "</tr>"
print "<tr class=\"display_odd\">"
print "<td>机器名(拼音)</td>"
print "<td><input size=12 name=\"robot_name_en\" value=%s></td>" % (robot_name_en)
print " </tr>"
print "<tr class=\"display_even\">"
print "<td>机器名(英文)</td>"
print "<td><input size=12 name=\"robot_name_ch\" value=%s></td>"  % (robot_name_ch)
print "</tr>"
print "<tr class=\"display_odd\">"
print "<td>主人称呼</td>"
print "<td><input size=12 name=\"owner_name\" value=%s></td>" % (owner_name)
print "</tr>"
print "<tr class=\"display_even\">"
print "<td>机器声音</td>"
print "<td>	"
print "<select name=\"dropdown\">	"
print "<option>女声</option>"
print "<option>男声</option>"
print "<option>度逍遥</option>"
print "<option>度丫丫</option>"
print "</select>"
print "</td>"
print "</tr>"
print "<tr class=\"display_odd\">"
print "<td>网易邮箱账户</td>"
print "<td><input size=12 name=\"neteasyaccount\" value=%s></td>" % (neteasyaccount)
print "</tr>"
print "<tr class=\"display_even\">"
print "<td>网易邮箱密码</td>"
print "<td><input size=12 type=\"password\" name=\"neteasypasswd\" value=%s></td>" % (neteasypasswd) 
print "</tr>"
print "<tr class=\"display_odd\">"
print "<td>网易云音乐账户</td>"
print "<td><input size=12 name=\"netmusicaccount\" value=%s></td>" % (netmusicaccount)
print "</tr>"
print "<tr class=\"display_even\">"
print "<td>网易云音乐密码</td>"
print "<td><input size=12 type=\"password\" name=\"netmusicpassword\" value=%s></td>" %(netmusicpassword)
print "</tr>"
print "<tr class=\"display_odd\">"
print "<td colspan=2><input type=\"submit\" name=\"Submit\" value=\"应用\"></a></td>"
print "</tr>"
print "</table>"
print "</form>"
print "</body>"
print "</html>"