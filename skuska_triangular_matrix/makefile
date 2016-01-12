BOOST = -IC:/boost_1_60_0/
EIGEN = -IC:/_Peto/programing/eigen/

all: main

main: main.o
	g++ main.o -o main.exe

#use -v for more info in compiling

main.o: main.cpp
	g++ -c $(EIGEN) main.cpp 2> error_log.txt

clean:
	rm *.o  || echo "No *.o files. Continuing clean"
	rm main.exe || echo "No main.exe file. Continuing clean"