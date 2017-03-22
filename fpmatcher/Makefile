#*************************************************************
#*
#* Author :      SecuGen Corporation
#* Description : FPMatcher Makefile
#* Copyright(c): 2004 SecuGen Corporation, All rights reserved
#* History : 
#* date        person   comments
#* ======================================================
#*
#*
#*************************************************************
PORT = linux
CPP=g++
#GTK1.0##########################
#CFLAGS = -D__LINUX
#INCPATH = -I./ -I../include `gtk-config --cflags`
#LIBS =  -L../lib/$(PORT) `gtk-config --libs`
#################################
#GTK1.2##########################
CFLAGS = -D__LINUX -D__GTK12
INCPATH = -I./ -I../include `pkg-config --cflags gtk+-2.0`
LIBS =  -L../lib/$(PORT) `pkg-config --libs gtk+-2.0`
#################################



OBJS=	main.o \
	interface.o \
	callbacks.o \
	configure.o

SRCS = main.cpp \
	interface.cpp \
	callbacks.cpp \
	configure.cpp


FDU03_TARGET = ../bin/$(PORT)/fpmatcher_fdu03
FDU04_TARGET = ../bin/$(PORT)/fpmatcher_fdu04
FDU05_TARGET = ../bin/$(PORT)/fpmatcher_fdu05

all : $(FDU05_TARGET) $(FDU04_TARGET) $(FDU03_TARGET)

$(FDU05_TARGET) : $(OBJS)
	$(CPP) -lsgfpamx -lsgfplib -lusb -lpthread -lsgfdu05 -o $@ $(OBJS) $(LIBS)

$(FDU04_TARGET) : $(OBJS)
	$(CPP) -lsgfpamx -lsgfplib -lusb -lpthread -lsgfdu04 -o $@ $(OBJS) $(LIBS)

$(FDU03_TARGET) : $(OBJS)
	$(CPP) -lsgfpamx -lsgfplib -lusb -lpthread -lsgfdu03 -o $@ $(OBJS) $(LIBS)

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
