#*************************************************************
#*
#* Author :      SecuGen Corporation
#* Description : SGD2 Makefile
#* Copyright(c): 2004 SecuGen Corporation, All rights reserved
#* History : 
#* date        person   comments
#* ======================================================
#*
#*
#*************************************************************
PORT = linux
CPP=g++
##CFLAGS = -D__LINUX -D__cplusplus -fno-stack-protector
#CFLAGS = -D__LINUX -D__cplusplus -Wall -O 
##INCPATH = -I./ -I../include `gtk-config --cflags`
##LIBS =  -L../lib/$(PORT) `gtk-config --libs`

#GTK1.0##########################
#CFLAGS = -D__LINUX -D__cplusplus -fno-stack-protector
#INCPATH = -I./ -I../include `gtk-config --cflags`
#LIBS =  -L../lib/$(PORT) `gtk-config --libs`
#################################
#GTK1.2##########################
CFLAGS = -D__LINUX -D__GTK12 -D__cplusplus -fno-stack-protector
INCPATH = -I./ -I../include `pkg-config --cflags gtk+-2.0`
LIBS =  -L../lib/$(PORT) `pkg-config --libs gtk+-2.0`
#################################


OBJS=	sgd2.o \
	image.o 

SRCS=	sgd2.cpp \
	image.cpp 

FDU03_TARGET = ../bin/$(PORT)/sgd2_fdu03
FDU04_TARGET = ../bin/$(PORT)/sgd2_fdu04
FDU05_TARGET = ../bin/$(PORT)/sgd2_fdu05

all : $(FDU05_TARGET) $(FDU04_TARGET) $(FDU03_TARGET)

$(FDU05_TARGET) : $(OBJS)
	$(CPP) -lusb -lpthread -lsgfdu05 -lsgfpamx -lsgfplib -o $@ $(OBJS) $(LIBS)

$(FDU04_TARGET) : $(OBJS)
	$(CPP) -lusb -lpthread -lsgfdu04 -lsgfpamx -lsgfplib -o $@ $(OBJS) $(LIBS)

$(FDU03_TARGET) : $(OBJS)
	$(CPP) -lusb -lpthread -lsgfdu03 -lsgfpamx -lsgfplib -o $@ $(OBJS) $(LIBS)


.cc.o :
	$(CPP) $(CFLAGS) $(INCPATH) -c $<

.c.o :
	$(CPP) $(CFLAGS) $(INCPATH) -c $<

.cpp.o :
	$(CPP) $(CFLAGS) $(INCPATH) -c $<

dep :
	gccmakedep $(INCPATH) $(SRCS)

clean :
	rm -rf *.raw *.min $(OBJS) $(FDU04_TARGET) $(FDU03_TARGET) core
	rm -rf $(PORT)
	mkdir $(PORT)

