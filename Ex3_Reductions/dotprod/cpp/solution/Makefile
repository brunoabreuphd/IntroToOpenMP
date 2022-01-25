# C++ Compiler (GNU)
CC=g++-11

# Compilation flags
CFLAGS=-fopenmp

dotprod_omp.exe: dotprod_omp.o
	$(CC) ${CFLAGS} -o $@ $^

dotprod_omp.o: dotprod_omp.cpp
	$(CC) ${CFLAGS} -c $<

clean:
	rm -r *.o *.exe