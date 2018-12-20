CC = g++
BINPATH = bin/
SRCS = main.cpp
OBJS = main
EXEC = main
main : 
	$(CC) -o $(BINPATH)$(EXEC) -std=c++17 $(SRCS)
clean:
	rm -rf $(OBJS)
