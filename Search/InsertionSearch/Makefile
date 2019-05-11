CC        =g++
CFLAGS    =-std=c++11 -Wall
OBJS      =InsertionSearch.o main.o
HEADFILES =../search.hpp ../test.hpp
SRCS      =InsertionSearch.cpp main.cpp
PROGRAM   =main.out

$(PROGRAM) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM)

$(OBJS) : $(SRCS) $(HEADFILES)
	$(CC) $(CFLAGS) $(SRCS) -c

clean :
	rm *.o *.out
