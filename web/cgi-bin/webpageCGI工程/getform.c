/*
    get html form data
*/
#include "getform.h"

char get_char_para(char*environ,char*paraname,char *path)
{
	int paralen;
	char *tmp;
	environ=strstr(environ,paraname);
	environ+=strlen(paraname);
	paralen = strcspn(environ,"&");
	memcpy(path,environ,paralen);
	
	path[paralen] = 0;
	
		tmp = strchr (path, ' ');	/* 去掉字符串后面的空格 */
		if (tmp != NULL)
			*tmp = '\0';
	return 0;
}
#if 0
char get_int_para(char * environ,char * paraname,char *buf)
{
	int paralen;
	environ=strstr(environ,paraname);
	environ+=strlen(paraname);
	paralen = strcspn(environ,"&");
	memcpy(buf,environ,paralen);
	return 0;
}
#endif



