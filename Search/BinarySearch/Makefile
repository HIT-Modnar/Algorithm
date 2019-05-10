CC        =g++
CFLAGS    =-std=c++11 -Wall
OBJS      =BinarySearch.o main.o
HEADFILES =../search.hpp ../test.hpp
SRCS      =BinarySearch.cpp main.cpp
PROGRAM   =main.out

$(PROGRAM) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM)

$(OBJS) : $(SRCS) $(HEADFILES)
	$(CC) $(CFLAGS) $(SRCS) -c

clean :
	rm *.o *.out
