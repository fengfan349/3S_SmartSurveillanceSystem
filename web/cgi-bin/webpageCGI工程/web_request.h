#ifndef _WEB_REQUEST_H
#define _WEB_REQUEST_H
#include "main.h"

#include "getform.h"
#include "webshtm.h"
#include "webscgi.h"

typedef struct html_file_entry
{
	char *path;
	int ((*func)(void)); //函数指针变量，指向函数入口的指针变量
	int ((*func_cgi)(void));//同上
	int size;
}HTML_FILE_ENTRY;


int webreq_config();
int webreq_refresh();

#endif
