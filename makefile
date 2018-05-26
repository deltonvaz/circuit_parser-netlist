#
# Makefile ESQUELETO
#
# OBRIGATÓRIO ter uma regra "all" para geração da biblioteca e de uma
# regra "clean" para remover todos os objetos gerados.
#
# NECESSARIO adaptar este esqueleto de makefile para suas necessidades.
#  1. Cuidado com a regra "clean" para não apagar o "fila2.o"
#
# OBSERVAR que as variáveis de ambiente consideram que o Makefile está no diretótio "cthread"
# 

CC=gcc
CXX=g++

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



