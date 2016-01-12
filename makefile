BOOST = -IC:/boost_1_60_0/
EIGEN = -IC:/_Peto/programing/eigen/

all:
	gcc $(EIGEN) main.cpp Tsystem.cpp Tsystem.hpp 

main: main.o Tsystem.o
	g++ main.o -o main.exe

#use -v for more info in compiling

main.o: main.cpp Tsystem.hpp
	g++ -c -v $(EIGEN) main.cpp Tsystem.hpp 

Tsystem.o: Tsystem.hpp
	g++ -c $(EIGEN) Tsystem.hpp

clean:
	rm *.o || echo "No *.o files. Continuing clean"
	rm main.exe || echo "No main.exe file. Continuing clean"