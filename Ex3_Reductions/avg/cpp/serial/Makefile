# C++ Compiler (GNU)
CC=g++-11

# Compilation flags
CFLAGS=

avg_serial.exe: avg_serial.o
	$(CC) -o $@ $^

avg_serial.o: avg_serial.cpp
	$(CC) ${CFLAGS} -c $<

clean:
	rm -r *.o *.exe