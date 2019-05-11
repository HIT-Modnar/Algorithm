CC        =g++
CFLAGS    =-std=c++11 -Wall
OBJS      =StringProcess.o main.o
HEADFILES =StringProcess.hpp
SRCS      =StringProcess.cpp main.cpp
PROGRAM   =main.out

$(PROGRAM) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM)

$(OBJS) : $(SRCS) $(HEADFILES)
	$(CC) $(CFLAGS) $(SRCS) -c

clean :
	rm *.o *.out
