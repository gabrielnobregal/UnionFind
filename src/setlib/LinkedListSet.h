/** Implementa��o de conjuntos disjuntos com listas encadeadas.
* 
* @author Gabriel Nobgrega de Lima
* @version 1.0
* 	
*/ 


#ifndef LINKEDLISTSET_H
#define LINKEDLISTSET_H

#include <iostream>
#include <sstream>
#include "SetManager.h"
#include "Set.h"
#include "LinkedNode.h"


using namespace std;

class LinkedListSet: public SetManager{
private:
	int nElements; // N�mero de elementos
	LinkedNode *node; // 0..nElements
	int unionType; // Tipo de heur�stica
	unsigned long ptrOperations; // Armazena o n�mero de opera��es de ponteiro
	
	void internalUnion(int x, int y); // Uni�o interna
	
	void incPointerOp(int n);
	void incPointerOp(int heuristic, int n);
	
public:
  
  //**** A documenta��o dos m�todos nao documentados aqui se encontra na interface SetManager ou na documenta��o em .../doc
  
	/**Uni�o sem qualquer heur�stica (Uni sempre x a y)*/
	static const int DEFAULT_UNION = 0; // Uni�o sem qualquer heur�stica (Uni sempre x a y)
	/**Uni�o com heur�stica ponderada (Uni o conjunto de menor n�mero de elementos ao de maior)*/
	static const int WEIGHTED_UNION = 1; // Uni�o com heur�stica ponderada (Uni o conjunto de menor n�mero de elementos ao de maior)
	
	/**Construtor que define o n�mero de elementos*/
	LinkedListSet(int size);
	~LinkedListSet();

	unsigned long getPointerOperationsState();
	void clearPointerOperations();
	void setHeuristic(int type);
	int getHeuristic();
	
	/**N�mero de elementos.*/
	int size();
	
	bool makeSet(int n);
	int findSet(int n);
	bool unionSet(int x, int y);
	string state();
	void release();
};

#endif