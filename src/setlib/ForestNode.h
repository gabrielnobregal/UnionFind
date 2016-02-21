/**
* Nó de árvore utilizado pela implementação de conjuntos
* disjuntos considerando uma floresta. * 
* 
* @author Gabriel Nobgrega de Lima
* @version 1.0
* 	
 */ 

#ifndef FORESTNODE_H
#define FORESTNODE_H

#include <iostream>

class ForestNode{

public:
	/** Nó mais próximo da raiz/representante. */
	ForestNode *next; // Próximo nó da árvore
	/** Número de nós da árvore. */
	int rank; // Número de nós na árvore
	/** Indice do vetor de nós da árvore*/
	int nodeIndex; // Grava o indice no vetor. Usado apenas para satisfazer os requisitos de impressão dos exercício
	
	ForestNode();
};

#endif