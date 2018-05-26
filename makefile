all: trabTopicos

trabTopicos: main.o Command.o Comment.o Element.o Object.o
	g++ -o trabTopicos main.o Command.o Comment.o Element.o Object.o

main.o: main.cpp
	g++ -c main.cpp -std=c++11

Command.o: Command.cpp Command.h
	g++ -c Command.cpp -std=c++11

Comment.o: Comment.cpp Comment.h
	g++ -c Comment.cpp -std=c++11

Element.o: Element.cpp Element.h
	g++ -c Element.cpp -std=c++11

Object.o: Object.cpp Object.h
	g++ -c Object.cpp -std=c++11

clean:
	rm -rf *~ *.o



