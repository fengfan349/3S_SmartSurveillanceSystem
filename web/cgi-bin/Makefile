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


CC := ppc_6xx-gcc
AR :=  ppc_6xx-ar
#CC := gcc
LINT := splint

WARN    := -W -Wall
SSDKFLAG:= -DIN_ACL -DIN_FDB -DIN_IGMP -DIN_LEAKY -DIN_LED -DIN_MIB -DIN_MIRROR -DIN_MISC -DIN_PORTCONTROL -DIN_PORTVLAN -DIN_QOS -DIN_RATE -DIN_STP -DIN_VLAN -DIN_COSMAP -DIN_IP -DIN_NAT -DIN_TRUNK -DIN_SEC -DIN_INTERFACECONTROL -DHSL_STANDALONG -DUK_IF -DUK_NL_PROT= -DUK_MINOR_DEV=254 -pthread -Wall -DVERSION=\"1.0.8.36\" -DBUILD_DATE=\"2014-04-21-00:32:26\" -DCPU=\"mips\" -DOS=\"linux\" -DISIS -DGCCV4 -DKVER26 -static -DUSER_MODE -DE1_MODULE
SSDKINCLUDE:=-I ./ssdk/include -I ./ssdk/include/common -I ./ssdk/include/api -I ./ssdk/include/fal -I ./ssdk/include/hsl -I ./ssdk/include/hsl/phy -I ./ssdk/include/sal/os -I ./ssdk/include/sal/sd -I ./ssdk/include/sal/sd/linux/hydra_howl -I ./ssdk/include/sal/sd/linux/uk_interface -I ./ssdk/include/init -I ./ssdk/src/opconn/h -I ./ssdk/include/hsl/isis 
INCLUDE	:=  -I ./  -I ./include -I ./multicast/h -I ./rstp/h -pthread -DLINUX -DDEBUG -DPPC -DEBUG \
   -DBOARD_TYPE=BOARD_SOC4E_EB \
   -I ./include -pthread -I ./soc4e-compact -I ./soc4e-compact/drv_soc4e -I ./soc4e-compact/msg_h\
   -I ./timer
   #-I ./spi_reg/ 
  
LINTFLAGS=-L ./ssdk/ 
CFLAGS  := ${WARN} $(SSDKFLAG) ${INCLUDE} $(SSDKINCLUDE) ${LINTFLAGS} 
LIBS=-lssdk_us_um
#LINTFLAGS = -weak +posixlib

SRC :=$(wildcard *.c)
SRC+=$(wildcard ./lib/*.c) 
SRC+=$(wildcard ./soc4e-compact/*.c) 
SRC+=$(wildcard ./ssdk/*.c) 
#SRC+=$(wildcard ./spi_reg/*.c) 
SRC+=$(wildcard ./multicast/src/*.c)
SRC+=$(wildcard ./timer/*.c)
SRC+=$(wildcard ./arp/*.c)
SRC+=$(wildcard ./rstp/src/*.c)
dir=$(notdir $(SRC))

EXEC	:= mscom
OBJS    := ${patsubst %.c, %.o, $(SRC)}

all:clean $(EXEC) libc

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	
clean:
	rm -fr $(OBJS) $(EXEC) *.bak *.a
	
libc:
	$(AR) -rsv liblink.a ./lib/*.o
	powerpc-linux-strip --remove-section=.note --remove-section=.comment mscom
	#cp mscom /home/fangmm/task/modify_tc510d/filesystem/ramdisk_4.2/rootfs/usr/sbin/
