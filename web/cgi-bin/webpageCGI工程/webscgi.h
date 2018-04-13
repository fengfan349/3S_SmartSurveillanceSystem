#ifndef _WEBSCGI_H
#define _WEBSCGI_H
#include "web_request.h"
#include "get_info.h"

#define GET_REP_TO_WEB(msg_snd,msg_rcv) \
{\
	msg_snd.type = MSG_WEB_TO_MAIN;\
	msgsnd(msg_web_fd,(void*)&msg_snd,sizeof(msg_data_struct),0);\
	msgrcv(msg_web_fd,(void*)&msg_rcv,sizeof(msg_data_struct),MSG_MAIN_TO_WEB,0);\
	if(msg_rcv.data.msg_data_buf[0]== MSG_REP_OK)\
	{\
		send_html();\
	}\
	else\
		send_fail_html();\
}

char name_en[32];
char name_ch[32];
char owner_name[32];
char neteasyaccount[32];
char neteasypassword[32];
char netmusicaccount[32];
char netmusicpassword[32];
int cgi_pi_info();
int cgi_stu_info();
int cgi_vlan_status();
int cgi_lan_info();
#endif