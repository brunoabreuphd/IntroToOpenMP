# C++ Compiler (GNU)
CC=g++

# Compilation flags
CFLAGS=-fopenmp

indexgame_omp.exe: indexgame_omp.o
	$(CC) ${CFLAGS} -o $@ $^

indexgame_omp.o: indexgame_omp.cpp
	$(CC) ${CFLAGS} -c $<

clean:
	rm -r *.o *.exe