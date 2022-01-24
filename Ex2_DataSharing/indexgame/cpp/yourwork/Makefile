# C++ Compiler (GNU)
CC=g++

# Compilation flags
CFLAGS=-fopenmp

indexgame_yourwork.exe: indexgame_yourwork.o
	$(CC) ${CFLAGS} -o $@ $^

indexgame_yourwork.o: indexgame_yourwork.cpp
	$(CC) ${CFLAGS} -c $<

clean:
	rm -r *.o *.exe