#*************************************************************
#*
#* Author :      SecuGen Corporation
#* Description : FPLibTest Makefile
#* Copyright(c): 2005 SecuGen Corporation, All rights reserved
#* date        person   comments
#* ======================================================
#*
#*
#*************************************************************
PORT = linux
CFLAGS = -D__cplusplus -Wall -O 
CPP=g++
INCPATH = -I./ -I../include
LIBS =  -L../lib/$(PORT)

OBJS=	main.o 

SRCS=	main.cpp 

TARGET = $(PORT)/test_compatibility_ansi378

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CPP) -lusb -lpthread -lsgfpamx -lsgfdu04 -lsgfplib -o $@ $(OBJS) $(LIBS)
	mv *.o $(PORT)
	cp *.raw $(PORT)
	cp *.ansi378 $(PORT)

.cc.o :
	$(CPP) $(FLAGS) $(INCPATH) -c $<

.c.o :
	$(CPP) $(FLAGS) $(INCPATH) -c $<

.cpp.o :
	$(CPP) $(FLAGS) $(INCPATH) -c $<

dep :
	gccmakedep $(INCPATH) $(SRCS)

clean :
	rm -rf $(OBJS) $(TARGET) core
	rm -rf $(PORT)
	mkdir $(PORT)

