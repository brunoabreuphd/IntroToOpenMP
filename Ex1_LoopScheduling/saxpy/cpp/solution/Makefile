# C++ Compiler (GNU)
CC=g++

# Compilation flags
CFLAGS=-Wall -fopenmp

saxpy_omp.exe: saxpy_omp.o
	$(CC) ${CFLAGS} -o $@ $^

saxpy_omp.o: saxpy_omp.cpp
	$(CC) ${CFLAGS} -c $<

clean:
	rm -r *.o *.exe