# C++ Compiler (GNU)
CC=g++

# Compilation flags
CFLAGS=-Wall

saxpy_serial.exe: saxpy_serial.o
	$(CC) -o $@ $^

saxpy_serial.o: saxpy_serial.cpp
	$(CC) ${CFLAGS} -c $<

clean:
	rm -r *.o *.exe