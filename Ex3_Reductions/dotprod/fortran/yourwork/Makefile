# Fortran Compiler (GNU)
FC=gfortran

# Compilation flags
FFLAGS=-fopenmp

dotprod_yourwork.exe: dotprod_yourwork.o
	$(FC) ${FFLAGS} -o $@ $^

dotprod_yourwork.o: dotprod_yourwork.f90
	$(FC) ${FFLAGS} -c $<

clean:
	rm -r *.o *.exe