# C++ Compiler (GNU)
CC=g++

# Compilation flags
CFLAGS=-fopenmp

saxpy_yourwork.exe: saxpy_yourwork.o
	$(CC) ${CFLAGS} -o $@ $^

saxpy_yourwork.o: saxpy_yourwork.cpp
	$(CC) ${CFLAGS} -c $<

clean:
	rm -r *.o *.exe