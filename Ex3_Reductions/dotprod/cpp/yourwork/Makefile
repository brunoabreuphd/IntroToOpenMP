# C++ Compiler (GNU)
CC=g++
# Compilation flags
CFLAGS=-fopenmp

dotprod_yourwork.exe: dotprod_yourwork.o
	$(CC) ${CFLAGS} -o $@ $^

dotprod_yourwork.o: dotprod_yourwork.cpp
	$(CC) ${CFLAGS} -c $<

clean:
	rm -r *.o *.exe