#name:		universal makefile
#author:	liangzsh
#data:		2010-11-29
#version:	v0.1
#input:		null
#output:	all object file and main(the executable file)
#description:
	#put this file to a floder, and this floder has only
	#one project, which means this floder will generate
	#only one executable file, and have and only have one
	#main funtion. type "make" to generate the executable
	#file.


CC := gcc
AR := ar
#CC := gcc
LINT := splint

WARN    := -W -Wall
SSDKFLAG:= -DIN_ACL -DIN_FDB -DIN_IGMP -DIN_LEAKY -DIN_LED -DIN_MIB -DIN_MIRROR -DIN_MISC -DIN_PORTCONTROL -DIN_PORTVLAN -DIN_QOS -DIN_RATE -DIN_STP -DIN_VLAN -DIN_COSMAP -DIN_IP -DIN_NAT -DIN_TRUNK -DIN_SEC -DIN_INTERFACECONTROL -DHSL_STANDALONG -DUK_IF -DUK_NL_PROT= -DUK_MINOR_DEV=254 -pthread -Wall -DVERSION=\"1.0.8.36\" -DBUILD_DATE=\"2014-04-21-00:32:26\" -DCPU=\"mips\" -DOS=\"linux\" -DISIS -DGCCV4 -DKVER26 -static -DUSER_MODE -DE1_MODULE
SSDKINCLUDE:=-I ./include/lib -I ./include/
INCLUDE	:=  -I ./  -I ./include -I ./multicast/h -I ./rstp/h -pthread -DLINUX -DDEBUG -DPPC -DEBUG \
   -DBOARD_TYPE=BOARD_SOC4E_EB \
   -I ./include -pthread -I ./soc4e-compact -I ./soc4e-compact/drv_soc4e -I ./soc4e-compact/msg_h\
   -I ./timer
   #-I ./spi_reg/ 
  

CFLAGS  := ${WARN} $(SSDKFLAG) ${INCLUDE} $(SSDKINCLUDE) 
LIBS=-lssdk_us_um
#LINTFLAGS = -weak +posixlib

SRC :=$(wildcard *.c)
SRC+=$(wildcard ./lib/*.c) 

dir=$(notdir $(SRC))

EXEC	:= cgi.cgi
OBJS    := ${patsubst %.c, %.o, $(SRC)}

all:clean $(EXEC) libc

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	
clean:
	rm -fr $(OBJS) $(EXEC) *.bak *.a
	
libc:
	$(AR) -rsv liblink.a ./lib/*.o
	#powerpc-linux-strip --remove-section=.note --remove-section=.comment mscom
	cp cgi.cgi /home/pi/thttpd/web/cgi-bin/
