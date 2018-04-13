#ifndef _GETFORM_H
#define _GETFORM_H
#include "type.h"
#include "main.h"
#include "ipc.h"

char get_char_para(char*environ,char*paraname,char *path);
char get_int_para(char * environ,char * paraname,char *buf);

#endif