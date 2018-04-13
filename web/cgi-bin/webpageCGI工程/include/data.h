#ifndef _DATA_H
#define _DATA_H
#include "type.h"
/*port vlan*/
#define VLAN_PORT_START 1
#define VLAN_PORT_END 4
#define MAX_PORT_NUM 7
#define LAN_ID_CNT 7

#define MAX_MSG_DATA 2048

/*ipc enum define*/
enum msg_rep
{
	MSG_REP_OK=0,
	MSG_REP_FAIL
};


typedef enum set_status
{
	SET_OK = 0, 
	SET_FAIL = -1 
}set_status_enum;

enum ipc_key
{
	IPC_MSG_KEY=1,
	IPC_SHM_KEY,
	IPC_SEM_KEY,
	IPC_KEY
};
enum ipc_sem
{
	USER_INFO_SEM=1,
	PORTVLAN_INFO_SEM,
	PORT_INFO_SEM,
	IPC_SEM_MAX
};

/*============msg data struct define==============*/
typedef enum msg_type
{
	MSG_WEB_TO_MAIN=1,//request
	MSG_MAIN_TO_WEB,//response
	MSG_TYPE
}msg_type_enum;

typedef enum msg_lay0
{
	MSG_USER_INFO=1,
	MSG_PORTVLAN_INFO,
	MSG_PORT_INFO,
	MSG_LAY0
}msg_lay0_enum;

typedef struct msg_data
{
	msg_lay0_enum module;
	u8 msg_data_buf[MAX_MSG_DATA];
}msg_data_struct;

typedef struct msg_queue
{
	long type;
	msg_data_struct data;
	
}msg_queue_struct;


/*==============share memory data struct define===============*/


typedef struct user_info
{
	char name[32];
	char sex[32];
	int age;
	int stu_id;
}user_info_struct;

typedef struct portvlan_info
{
	int lan_status;
	int lan_member[LAN_ID_CNT];
}portvlan_info_struct;

typedef enum port_speed
{
	SPEED_AUTO = 1,
	SPEED_10M = 10,
	SPEED_100M = 100,
	SPEED_1000M = 1000,
}port_speed_enum;

typedef enum port_duplex
{
	DUPLEX_HALF = 0,
	DUPLEX_FULL
}port_duplex_enum;

typedef enum port_link
{
	LINK_OFF = 0,
	LINK_ON
}port_link_enum;
typedef enum lan_num
{
	LAN_0 = 0,
	LAN_1,
	LAN_2,
	LAN_3,
	LAN_4,
	LAN_5,
	LAN_6,
}lan_num_enum;
typedef struct port_status
{
	lan_num_enum lan_id;
	port_link_enum link_status;
	port_duplex_enum duplex_status;
	port_speed_enum speed_status;
}port_status_struct;

typedef struct all_lan
{
	port_status_struct port_info[MAX_PORT_NUM];
}all_lan_struct;

typedef struct share_data
{
	user_info_struct user_info;
	portvlan_info_struct portvlan_info;
	port_status_struct port_info[MAX_PORT_NUM];
	all_lan_struct all_lan;
}share_data_struct;

#endif 