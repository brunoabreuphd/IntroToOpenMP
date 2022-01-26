# Fortran Compiler (GNU)
FC=gfortran

# Compilation flags
FFLAGS=-fopenmp

dotprod_omp.exe: dotprod_omp.o
	$(FC) ${FFLAGS} -o $@ $^

dotprod_omp.o: dotprod_omp.f90
	$(FC) ${FFLAGS} -c $<

clean:
	rm -r *.o *.exe