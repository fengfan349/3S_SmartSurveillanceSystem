
#include "ipc.h"
#include "main.h"
static key_t get_key( int id)
{	
	key_t key;
	
	key = ftok(".",id);
	if(-1 == key)
	{
		perror("get key: ftok");
		return -1;
	}
	
	return key;
}


int msg_creat(int id,int flag)
{
    int msgid;
	key_t msg_key;
	msg_key=get_key(id);
	//debug("msg_key is::%d\r\n",msg_key);
	if(msg_key == -1)
	{
		perror("msg get key error!!\n");
		return -1;
	}
	msgid=msgget(msg_key,flag);
    if(msgid == -1)
    {
		perror("msg get fd error!!\n");
		return -1;
	}
	
	return msgid;
	
}
int msg_delete(int id,int flag)
{
	if((msgctl(id,IPC_RMID,NULL))==-1)
	{
		perror("msg delete error!!\n");
		return -1;
	}
	return 0;
}
/*
	创建共享内存，成功则返回地址；
*/
void* shm_creat(int id, int shmflag, int shmsize)
{
	int shmid;
	void *shm=NULL;
	key_t key;
	key=get_key(id);
	//debug("shm_key is::%d\r\n",key);
	shmid = shmget(key,shmsize,shmflag);
	if(shmid == -1)
	{
		perror("shm get fd error!!\n");
		return -1;
	}
    if((shm = shmat(shmid,(void*)NULL,0))==-1)
    {
		perror("shm get mem error!!\n");
		return -1;
	}
	return shm;
	
}

int shm_delete(void* addr){
	shmdt(addr);
	return 0;
}


/*sem creat 创建信号量*/
int sem_create(int id, int num, int sem_flag)
{
	key_t sem_key;
	int sem_id;
	
	sem_key = get_key(id);
	//debug("sen_key is::%d\r\n",sem_key);
	sem_id = semget(sem_key, num, sem_flag);
	if(sem_id < 0)
	{
		perror("sem_create: semget");
		return -1;
	}	
	return sem_id;
}

int sem_initialize(int sem, int num, int val)
{
	union semun{
		int val;
		struct semid_ds *buf;
		unsigned short int * arrary;
	}arg;
	int i;
	
	for(i=0; i<num; i++)
	{
		arg.val = val;
		semctl(sem, i, SETVAL, arg);
	}

	return 0;
}

int sem_take(int sem, int index)
{
	struct sembuf operation;
	
	operation.sem_op = -1;
	operation.sem_num = index;
	operation.sem_flg = IPC_WAIT;
	
	if(semop(sem, &operation, 1) < 0)
	{
		perror("sem_take: semop");
		printf("errno=%d\n",errno);
		return -1;
	}

	return 0;
}

int sem_give(int sem, int index)
{
	struct sembuf operation;
	
	operation.sem_op = 1;
	operation.sem_num = index;
	operation.sem_flg = IPC_NOWAIT;

	if(semop(sem, &operation, 1) < 0)
	{
		perror("sem_give: semop");
		return -1;
	}

	return 0;
}

