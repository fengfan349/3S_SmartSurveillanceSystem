#include "port_map.h"
int lan_to_port(int *buf,int i)
{
	int map[4];
	memset(map,0,sizeof(map));
	map[0]=((buf[i]&0x1)<<1);
	map[1]=((buf[i]&0x2)<<2);
	map[2]=((buf[i]&0x4)>>2);
	map[3]=((buf[i]&0x8)>>1);
	buf[i]=((map[0]|map[1]|map[2]|map[3])<<1)|0x61;

	return 0;
}

int port_to_lan(int *buf,int i)
{	
	int map[4];
	memset(map,0,sizeof(map));
	buf[i]=(buf[i]&0x1f)>>1;
	//debug("buf[%d]::0x%x\r\n",i,buf[i]);
	map[0]=((buf[i]&0x1)<<2);
	map[1]=((buf[i]&0x2)>>1);
	map[2]=((buf[i]&0x4)<<1);
	map[3]=((buf[i]&0x8)>>2);
	buf[i]=(map[0]|map[1]|map[2]|map[3]);
	debug("buf[%d]::0x%x\r\n",i,buf[i]);
	return 0;
}
