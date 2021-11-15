COMPILER=g++

# output bin
client.out: client.o stack.o
			$(COMPILER) -o client.out client.o stack.o
client.o: 	client.cpp stack.h
			$(COMPILER) -c client.cpp
stack.o: 	stack.cpp stack.h
			$(COMPILER) -c stack.cpp

clean: 
		rm -v *.o
build: 
		make && make clean

