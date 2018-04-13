#include "get_info.h"

int get_student_info(user_info_struct *info)
{
	memset(info,0,sizeof(*info));
	sem_take(sem_fd,USER_INFO_SEM);
	memcpy(info,&share_mem->user_info,sizeof(*info));
	debug("I am here get student info finish\r\n");

	sem_give(sem_fd,USER_INFO_SEM);
	
	return 0;
}

int get_portvlan_member(int* member)
{
	int i;
	sem_take(sem_fd,PORTVLAN_INFO_SEM);
	
	debug("Lan member :0x%x\r\n",share_mem->portvlan_info.lan_member[2]);
    for(i=VLAN_PORT_START;i<=VLAN_PORT_END;i++)
    {
		member[i]=share_mem->portvlan_info.lan_member[i];
	}
	
	debug("Lan member :0x%x\r\n",member[1]);

	sem_give(sem_fd,PORTVLAN_INFO_SEM);
	return 0;
	
}

int get_lan_info(port_status_struct *port_status,int lan_id)
{	
	debug("lan_id is %d\r\n",lan_id);
	
	sem_take(sem_fd,PORT_INFO_SEM);
	memcpy(port_status,&share_mem->port_info[lan_id],sizeof(*port_status));
	sem_give(sem_fd,PORT_INFO_SEM);
	debug("port 1 speed %d \r\n",port_status->speed_status);

}

int get_lan_status_info(all_lan_struct *all_lan)
{	
	sem_take(sem_fd,PORT_INFO_SEM);
	
	memcpy(all_lan,&share_mem->all_lan,sizeof(*all_lan));
	sem_give(sem_fd,PORT_INFO_SEM);
	//debug("port 1 speed %d \r\n",share_mem->port_info[1].speed_status);

}


