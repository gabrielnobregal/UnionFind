/**
 *	Implementa conjuntos disjuntos como uma floresta.
 * 
 * 	@author Gabriel Nobgrega de Lima
 * 	@version 1.0
 * 	
 */ 

#ifndef FORESTSET_H
#define FORESTSET_H

#include <iostream>
#include <sstream>
#include "SetManager.h"
#include "ForestNode.h"
#include "Set.h"

using namespace std;

class ForestSet: public SetManager{

private:
	int nElements;
	ForestNode *node; // 0..n
	int unionType;
	unsigned long ptrOperations;
	
	
	int getTreeRoot(int n); // Obtêm om representante/raiz da árvore
	int internalFindSet(int n); // FindSet sem heuristica
	int internalCompressedFindSet(int n); // FindSet com heurística de união ponderada e compressão de caminhos
	void incPointerOp(int heuristic, int n); // Incrementa o ponteiro se for uma dada heuristica
	void incPointerOp(int n); // Incrementa operações de ponteiro
	  
public:

  //**** A documentação dos métodos nao documentados aqui se encontra na interface SetManager ou na documentação em .../doc
  
	/** Sem heurística */
	static const int DEFAULT_HEURISTIC = 0;
	/** Heurística de união ponderada e compressão de caminhos. */
	static const int COMPRESS_AND_WEIGHTED_HEURISTIC = 1;
	
	/**Construtor que define o número de elementos*/
	ForestSet(int size);
	~ForestSet();
	unsigned long getPointerOperationsState();
	void clearPointerOperations();
	void setHeuristic(int type);
	int getHeuristic();
	
	/**Número de elementos.*/
	int size();
	bool makeSet(int n);	
	int findSet(int n);
	bool unionSet(int x, int y);	
	string state();
	void release();

	
};


#endif
