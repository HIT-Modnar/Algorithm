CC        =g++
CFLAGS    =-std=c++11 -Wall
OBJS      =main.o Trie.o
HEADFILES =Trie.hpp
SRCS      =main.cpp Trie.cpp
PROGRAM   =main.out

all : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM)

$(OBJS) : $(SRCS) $(HEADFILES)
	$(CC) $(CFLAGS) $(SRCS) -c

clean :
	rm *.o *.out
