# Fortran Compiler (GNU)
FC=gfortran

# Compilation flags
FFLAGS=-fopenmp

saxpy_yourwork.exe: saxpy_yourwork.o
	$(FC) ${FFLAGS} -o $@ $^

saxpy_yourwork.o: saxpy_yourwork.f90
	$(FC) ${FFLAGS} -c $<

clean:
	rm -r *.o *.exe