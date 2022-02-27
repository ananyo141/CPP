CXX=g++

client.out: client.o wineCont.o wineInh.o ../StudentClass/studcont.hpp
	$(CXX) -o client.out client.o wineCont.o wineInh.o ../StudentClass/studcont.cpp

wineCont.o: wineCont.cpp wineCont.hpp
	$(CXX) -c wineCont.cpp

wineInh.o: wineInh.cpp wineInh.hpp
	$(CXX) -c wineInh.cpp

clean:
	rm *.o

build:
	make && make clean

