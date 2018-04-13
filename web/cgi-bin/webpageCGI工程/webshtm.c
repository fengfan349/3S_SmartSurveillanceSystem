#include "webshtm.h"
#include "webscgi.h"
int html_pi_info()
{
	char buf[256]="sudo python config.py ";
	char tmp[256];
	memset(tmp,0,sizeof(tmp));
	memcpy(name_en,strcat(name_en," "),128);
    memcpy(tmp,strcat(buf,name_en),128);

	memcpy(name_ch,strcat(name_ch," "),128);
	memcpy(tmp,strcat(buf,name_ch),128);
	
 
	memcpy(owner_name,strcat(owner_name," "),128);
	memcpy(tmp,strcat(buf,owner_name),128);


	memcpy(neteasyaccount,strcat(neteasyaccount," "),128);
	memcpy(tmp,strcat(buf,neteasyaccount),128);



	memcpy(neteasypassword,strcat(neteasypassword," "),128);
	memcpy(tmp,strcat(buf,neteasypassword),128);

	memcpy(netmusicaccount,strcat(netmusicaccount," "),128);
	memcpy(tmp,strcat(buf,netmusicaccount),128);

	memcpy(netmusicpassword,strcat(netmusicpassword," "),128);
	memcpy(tmp,strcat(buf,netmusicpassword),128);

	

	debug("sudo html path is:%s\n",tmp);
	system(tmp);
}

int html_stu_info()
{
	char buf[100];
	char* expression[64];
	int epscnt=0;
    char tmpbuf[100];
	user_info_struct info;
	
	get_student_info(&info);
	debug("stu_info:%s\r\n",info.name);
	
    memset(tmpbuf,0,100);
    memset(buf,0,100);
    strcat(tmpbuf,"s/var_value/");
    memcpy(buf,info.name,32);
    strcat(tmpbuf,buf);
    strcat(tmpbuf,",");

    memset(buf,0,100);
    memcpy(buf,info.sex,32);
    strcat(tmpbuf,buf);
    strcat(tmpbuf,",");

    memset(buf,0,100);
    sprintf(buf,"%d",info.age);
    strcat(tmpbuf,buf);
    strcat(tmpbuf,",");

    memset(buf,0,100);
    sprintf(buf,"%d",info.stu_id);
    strcat(tmpbuf,buf);
    strcat(tmpbuf,"/");
    
    debug("tmpbuf:%s\n",tmpbuf);
    expression[epscnt]=strdup(tmpbuf);
    epscnt++;
    sed_to_html(epscnt,expression,DATA_DIR DATA_HTML);
    return 0;
}


int html_navigation()
{
	char* expression[64];
	int epscnt=0;
    char tmpbuf[100];
	memset(tmpbuf,0,100);
    strcat(tmpbuf,"s/abc/abc/");
	expression[epscnt]=strdup(tmpbuf);
    epscnt++;
	debug("======I am here navigitong!!!!======\n");
	
	sed_to_html(epscnt,expression,DATA_DIR "/navigation.htm");
	
	return 0;
}

int html_vlan_status()
{
	int i;
	char buf[100];
	char* expression[64];
	int epscnt=0;
    char tmpbuf[100];
	int lan_member[MAX_PORT_NUM];

	memset(lan_member,0,sizeof(lan_member));
	get_portvlan_member(lan_member);
	
	memset(tmpbuf,0,100);
    memset(buf,0,100);
    strcat(tmpbuf,"s/var_value/");
	sprintf(buf,"%d",lan_member[1]);// LAN 1
	strcat(tmpbuf,buf);
    strcat(tmpbuf,",");
	
    memset(buf,0,100);
	sprintf(buf,"%d",lan_member[2]);// LAN 2
	strcat(tmpbuf,buf);
    strcat(tmpbuf,",");
	
    memset(buf,0,100);
	sprintf(buf,"%d",lan_member[3]);// LAN 3
	strcat(tmpbuf,buf);
    strcat(tmpbuf,",");

    memset(buf,0,100);
	sprintf(buf,"%d",lan_member[4]);// LAN 4
	strcat(tmpbuf,buf);
    strcat(tmpbuf,"/");
	
	debug("tmpbuf:%s\n",tmpbuf);
    expression[epscnt]=strdup(tmpbuf);
    epscnt++;
    sed_to_html(epscnt,expression,DATA_DIR "/vlan_status.htm");
	
    return 0;
}

int html_lan()
{
	
	char* expression[64];
	int epscnt=0;
	char* env=NULL;
    char tmpbuf[100];
	char buf[100];
	int lan_id,mode;
	debug("speed %d \r\n",share_mem->port_info[1].speed_status);
	port_status_struct port_status;
	CLEAR_STRUCT(port_status);

	memset(buf,0,100);
	env=getenv("QUERY_STRING");
	get_char_para(env,"PORT=",buf);
	lan_id=atoi(buf);
	debug("Current port is %d\r\n",lan_id);

	memset(tmpbuf,0,100);
	strcat(tmpbuf,"s/var_value/");
	strcat(tmpbuf,buf);
    strcat(tmpbuf,",");
	
	get_lan_info(&port_status,lan_id);
	
	GET_MODE(port_status,mode);

	memset(buf,0,100);
	sprintf(buf,"%d",mode);// LAN 3
	strcat(tmpbuf,buf);
    strcat(tmpbuf,"/");
	
	expression[epscnt]=strdup(tmpbuf);
    epscnt++;
	sed_to_html(epscnt,expression,DATA_DIR "lan.htm");
}

int html_lan_status()
{
	int i;
	debug("I am here for lan status!!!!\r\n");
	char* expression[64];
	int epscnt=0;
	char* env=NULL;
    char tmpbuf[200];
	char buf[100];
	char *link[] = 
	{
		"img\\/led-down.gif",
		"img\\/led-up.gif",
		NULL,
	};
	char *duplex[] = 
	{
		"HALF",
		"FULL",
		NULL,
	};
	char *speed[] = 
	{
		"Auto Mode",
		"1000M",
		"100M",
		"10M",
		NULL,
	};

	all_lan_struct all_lan;
	CLEAR_STRUCT(all_lan);
	
	
	get_lan_status_info(&all_lan);
	
	
	memset(tmpbuf,0,200);
	strcat(tmpbuf,"s/var_value/");
	
	/*link status*/
	for(i=VLAN_PORT_START;i<=VLAN_PORT_END;i++)
	{
	    memset(buf,0,100);
		sprintf(buf,"%s",link[all_lan.port_info[i].link_status]);
		//memcpy(buf,link[all_lan.port_info[i].link_status],sizeof(*link[all_lan.port_info[i].link_status]));
		strcat(tmpbuf,buf);
   	    strcat(tmpbuf,",");
	}

	/*speed status*/
	
	for(i=VLAN_PORT_START;i<=VLAN_PORT_END;i++)
	{
		memset(buf,0,100);
		//debug("port [%d]\r\n",i);
		switch(all_lan.port_info[i].speed_status)
		{
			case 1:
				sprintf(buf,"%s",speed[0]);break;
			case 10:
				sprintf(buf,"%s",speed[3]);break;
			case 100:
				sprintf(buf,"%s",speed[2]);break;
			case 1000:
				sprintf(buf,"%s",speed[1]);break;
			default:
				debug("wrong ------\r\n")break;
		}
		strcat(tmpbuf,buf);
		strcat(tmpbuf,",");
	}

	/*duplex status*/
	for(i=VLAN_PORT_START;i<=VLAN_PORT_END;i++)
	{
	    memset(buf,0,100);
		sprintf(buf,"%s",duplex[all_lan.port_info[i].duplex_status]);
		
		strcat(tmpbuf,buf);
		if(i==VLAN_PORT_END)
   	    	strcat(tmpbuf,"/");
		else
			strcat(tmpbuf,",");
	}
	
    debug("lan status tmpbuf is %s\r\n",tmpbuf);


	expression[epscnt]=strdup(tmpbuf);
    epscnt++;
	sed_to_html(epscnt,expression,DATA_DIR "lan_status.htm");
}

