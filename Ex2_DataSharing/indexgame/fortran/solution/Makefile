# Fortran Compiler (GNU)
FC=gfortran

# Compilation flags
FFLAGS=-fopenmp

indexgame_omp.exe: indexgame_omp.o
	$(FC) ${FFLAGS} -o $@ $^

indexgame_omp.o: indexgame_omp.f90
	$(FC) ${FFLAGS} -c $<

clean:
	rm -r *.o *.exe