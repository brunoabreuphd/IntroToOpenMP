# C++ Compiler (GNU)
CC=g++-11
# Compilation flags
CFLAGS=-fopenmp

avg_omp1.exe: avg_omp1.o
	$(CC) ${CFLAGS} -o $@ $^

avg_omp1.o: avg_omp1.cpp
	$(CC) ${CFLAGS} -c $<

clean:
	rm -r *.o *.exe