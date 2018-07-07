SRC=./testingsetup.cpp  ./test_tommath_compute.cpp  ./test_tommath_io.cpp
INCLUDE= -I./ -I../libtommath
LIBPATH= -L../libtommath -ltommath
LIB=  -lc -lrt -lcurl -lpthread -lboost_unit_test_framework -lboost_program_options -lboost_system
APP= ecc_lib_test
CFLAG=-std=c++11
DEBUG=-g
ecc_lib_test:
	g++ $(CFLAG) $(DEBUG) $(SRC) $(INCLUDE) -o $(APP) $(LIB) $(LIBPATH) 

clean:
	rm -rf $(APP)
