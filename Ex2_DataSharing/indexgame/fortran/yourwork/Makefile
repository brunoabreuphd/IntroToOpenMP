# Fortran Compiler (GNU)
FC=gfortran

# Compilation flags
FFLAGS=-fopenmp

indexgame_yourwork.exe: indexgame_yourwork.o
	$(FC) ${FFLAGS} -o $@ $^

indexgame_yourwork.o: indexgame_yourwork.f90
	$(FC) ${FFLAGS} -c $<

clean:
	rm -r *.o *.exe