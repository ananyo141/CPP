COMPILER=g++

client.out: client.o list.o
			$(COMPILER) -o client.out client.o list.o
client.o: 	client.cpp list.h
			$(COMPILER) -c client.cpp
list.o: 	list.cpp list.h
			$(COMPILER) -c list.cpp

clean:
		rm -v *.o

