Example for linking fortran subroutine to a c++(c) main.

You need to
-have the original Fortran
-write an interface to the Fortran common block
-use the fortran code in c++ via the interface (here main.cc).

The Fortran and the interface are compiled into a shared library.
Notice how in the makefile the Fortan compiler was used for creating the lib.

You need to set the LD_LIBRARY_PATH to be able to access the library at runtime.

