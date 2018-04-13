#ifndef _IPC_H
#define _IPC_H
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errno.h"
#define KEY_DEVICE_NAME "/dev/switch"
#define IPC_WAIT 0

static key_t get_key(int id);

int msg_creat(int id,int flag);

int msg_delete(int id,int flag);
void* shm_creat(int id, int shmflag, int shmsize);

int shm_delete(void * addr);

int sem_create(int id, int num, int sem_flag);
int sem_initialize(int sem, int num, int val);
int sem_take(int sem, int index);
int sem_give(int sem, int index);

#endif

