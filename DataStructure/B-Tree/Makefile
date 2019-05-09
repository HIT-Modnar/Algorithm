CC        =g++
CFLAGS    =-std=c++11 -Wall
OBJS      =main.o Tree.o
HEADFILES =Tree.hpp 
SRCS      =main.cpp Tree.cpp
PROGRAM   =main.out

all : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM)

$(OBJS) : $(SRCS) $(HEADFILES)
	$(CC) $(CFLAGS) $(SRCS) -c

clean :
	rm *.o *.out
