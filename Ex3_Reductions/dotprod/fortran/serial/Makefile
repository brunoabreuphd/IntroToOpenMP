# Fortran Compiler (GNU)
FC=gfortran-11

# Compilation flags
FFLAGS=

dotprod_serial.exe: dotprod_serial.o
	$(FC) -o $@ $^

dotprod_serial.o: dotprod_serial.f90
	$(FC) ${FFLAGS} -c $<

clean:
	rm -r *.o *.exe