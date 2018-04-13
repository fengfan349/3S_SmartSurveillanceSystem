#ifndef _WEBSHTM_H
#define _WEBSHTM_H
//#include "main.h"
#include "web_request.h"
#include "get_info.h"
#include "sed_page.h"
#define GET_MODE(port_status,mode){\
	if((port_status.speed_status) == SPEED_AUTO)\
	{\
		mode = 1;\
	}\
	else if((port_status.speed_status) == SPEED_100M)\
	{\
		if((port_status.duplex_status) == DUPLEX_FULL)\
			mode = 2;\
		else\
			mode = 3;\
	}\
	else\
	{\
		if((port_status.duplex_status) == DUPLEX_FULL)\
			mode = 4;\
		else\
			mode = 5;\
	}\
}
int html_pi_info();

int html_stu_info();
int html_navigation();
int html_vlan_status();
int html_lan();
int html_lan_status();

#endif
