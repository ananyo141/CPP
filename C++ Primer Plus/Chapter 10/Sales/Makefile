COMPILER=g++

client.out: client.o sales.o
			$(COMPILER) -o client.out client.o sales.o
client.o:	client.cpp sales.h
			$(COMPILER) -c client.cpp
sales.o:	sales.cpp sales.h
			$(COMPILER) -c sales.cpp

