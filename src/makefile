#Makefile para a construção do projeto Lab02
#Criado por: Gabriel Nobrega de Lima
#Disciplina: Algoritmo e Estrutura de Dados II
#Data: 9/10/2012

SETLIB=setlib/

CC=g++

all: main
	$(CC) main.o UnionFindApp.o LinkedListSet.o ForestSet.o LinkedNode.o ForestNode.o -o unionfindapp

main:UnionFindApp
	$(CC) -c main.cpp

UnionFindApp:LinkedListSet ForestSet
	$(CC)  -std=c++0x -c UnionFindApp.cpp

LinkedListSet:LinkedNode
	$(CC) -c $(SETLIB)LinkedListSet.cpp

ForestSet:ForestNode
	$(CC) -c $(SETLIB)ForestSet.cpp

LinkedNode:
	$(CC) -c $(SETLIB)LinkedNode.cpp

ForestNode:
	$(CC) -c $(SETLIB)ForestNode.cpp

clear:
	rm *.o unionfindapp
