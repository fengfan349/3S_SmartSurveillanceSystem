#ifndef _SED_PAGE_H
#define _SED_PAGE_H
#include "type.h"
#include "main.h"
#include "ipc.h"
#define SED "/bin/sed"
int sed_to_html(int epscnt,char*expression[],char *file);
int send_html();
int send_fail_html();

#endif
