#include "ipc_init.h"

int ipc_init()
{
	share_mem=(share_data_struct*)shm_creat(IPC_SHM_KEY,0666,sizeof(share_data_struct));//共享内存初始化，得到共享内存首地址
	
	msg_web_fd=msg_creat(IPC_MSG_KEY,0666);// 消息队列初始化，得到消息队列描述符

	sem_fd=sem_create(IPC_SEM_KEY,IPC_SEM_MAX,0666);// 信号量初始化
	//sem_initialize(sem_fd,IPC_SEM_MAX,1);

	return 0;
}

