CC        =g++
CFLAGS    =-std=c++11 -Wall
OBJS      =LCS.o main.o
HEADFILES =LCS.hpp
SRCS      =LCS.cpp main.cpp
PROGRAM   =main.out

$(PROGRAM) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM)

$(OBJS) : $(SRCS) $(HEADFILES)
	$(CC) $(CFLAGS) $(SRCS) -c

clean :
	rm *.o *.out
