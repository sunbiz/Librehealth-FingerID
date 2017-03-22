#*************************************************************
#*
#* Author :      SecuGen Corporation
#* Description : FPLibTest Makefile
#* Copyright(c): 2009 SecuGen Corporation, All rights reserved
#* date        person   comments
#* ======================================================
#* 12/10/2009  driley   initial release
#*
#*************************************************************

PORT = linux
CFLAGS = -D__cplusplus -Wall -O
CPP=g++
CC=gcc
INCPATH = -I./ -I../include
LIBS =  -L../lib/$(PORT)

OBJS=	main.o 

SRCS=	main.cpp 

FDU03_TARGET = ../bin/$(PORT)/sgfplibtest_fdu03
FDU04_TARGET = ../bin/$(PORT)/sgfplibtest_fdu04
FDU05_TARGET = ../bin/$(PORT)/sgfplibtest_fdu05

all : $(FDU05_TARGET) $(FDU04_TARGET) $(FDU03_TARGET)

$(FDU05_TARGET) : $(OBJS)
	$(CPP) -lusb -lpthread -lsgfpamx -lsgfdu05 -lsgfplib -o $@ $(OBJS) $(LIBS)

$(FDU04_TARGET) : $(OBJS)
	$(CPP) -lusb -lpthread -lsgfpamx -lsgfdu04 -lsgfplib -o $@ $(OBJS) $(LIBS)

$(FDU03_TARGET) : $(OBJS)
	$(CPP) -lusb -lpthread -lsgfpamx -lsgfdu03 -lsgfplib -o $@ $(OBJS) $(LIBS)

.cc.o :
	$(CPP) $(FLAGS) $(INCPATH) -c $<

.c.o :
	$(CPP) $(FLAGS) $(INCPATH) -c $<

.cpp.o :
	$(CPP) $(FLAGS) $(INCPATH) -c $<

dep :
	gccmakedep $(INCPATH) $(SRCS)

clean :
	rm -rf *.raw *.min $(OBJS) $(FDU04_TARGET) $(FDU03_TARGET)  core
	rm -rf $(PORT)
	mkdir $(PORT)

