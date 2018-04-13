#ifndef _GET_INFO_H
#define _GET_INFO_H
#include "web_request.h"

int get_student_info(user_info_struct *info);
int get_portvlan_member(int* member);
int get_lan_info(port_status_struct *port_status,int lan_id);
int get_lan_status_info(all_lan_struct *all_lan);


#endif
