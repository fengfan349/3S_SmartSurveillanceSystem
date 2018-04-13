#ifndef _COMM_H
#define _COMM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errno.h"

#define SAFE_FREE(p) do{ free(p); p=NULL; } while(0)

#define CLEAR_ARRAY(p)									memset((void*)p, 0, sizeof(p))
#define CLEAR_MEMORY(p, len)						memset((void*)p, 0, len)
#define CLEAR_STRUCT(o)								memset((void*)(&(o)), 0, sizeof(o))
#define COPY_STRUCT(o_des, o_src)				memcpy((char*)&o_des, (char*)&o_src, sizeof(o_des))
#define COPYTO_STRUCT(o, p_src)					memcpy((char*)&o, (char*)p_src, sizeof(o))
#define COPYFROM_STRUCT(p_src, o)				memcpy((char*)p_src, (char*)&o, sizeof(o))
#define UNEQUAL_STRUCT(o_a, o_b)				memcmp(&o_a, &o_b, sizeof(o_a))

#endif
