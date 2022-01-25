# Fortran Compiler (GNU)
FC=gfortran

# Compilation flags
FFLAGS=

indexgame_serial.exe: indexgame_serial.o
	$(FC) -o $@ $^

indexgame_serial.o: indexgame_serial.f90
	$(FC) ${FFLAGS} -c $<

clean:
	rm -r *.o *.exe