# Fortran Compiler (GNU)
FC=gfortran

# Compilation flags
FFLAGS=-Wall

saxpy_serial.exe: saxpy_serial.o
	$(FC) -o $@ $^

saxpy_serial.o: saxpy_serial.f90
	$(FC) ${FFLAGS} -c $<

clean:
	rm -r *.o *.exe