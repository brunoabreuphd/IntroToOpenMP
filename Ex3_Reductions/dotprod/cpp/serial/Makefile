# C++ Compiler (GNU)
CC=g++

# Compilation flags
CFLAGS=

dotprod_serial.exe: dotprod_serial.o
	$(CC) -o $@ $^

dotprod_serial.o: dotprod_serial.cpp
	$(CC) ${CFLAGS} -c $<

clean:
	rm -r *.o *.exe