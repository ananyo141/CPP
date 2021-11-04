# make target binary
COMPILER=g++
client.out: client.o golf.o
	$(COMPILER) -o client.out client.o golf.o

client.o: client.cpp golf.h
	$(COMPILER) -c client.cpp

golf.o:	golf.cpp golf.h
	$(COMPILER) -c golf.cpp

# clean generated object files
clean: 
	rm -v *.o 

# build the binary and clean up obj files
build:
	make && make clean

