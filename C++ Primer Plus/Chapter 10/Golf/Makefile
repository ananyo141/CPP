COMPILER=g++

client.out: client.o golf.o
			$(COMPILER) -o client.out client.o golf.o
client.o:   client.cpp golf.h
			$(COMPILER) -c client.cpp
golf.o:     golf.cpp golf.h
			$(COMPILER) -c golf.cpp

clean:
		rm -v *.o

