# very simple makefile
# top down 

rationalNumExample : RationalNum.o main.o 
	g++ -o rationalNumExample main.o RationalNum.o

RationalNum.o : RationalNum.cpp
	g++ -c -std=c++0x -Wall RationalNum.cpp

main.o : main.cpp
	g++ -c -std=c++0x -Wall main.cpp

clean:
	rm *.o rationalNumExample


