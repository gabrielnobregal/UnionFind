/**
* N� de �rvore utilizado pela implementa��o de conjuntos
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
	/** N� mais pr�ximo da raiz/representante. */
	ForestNode *next; // Pr�ximo n� da �rvore
	/** N�mero de n�s da �rvore. */
	int rank; // N�mero de n�s na �rvore
	/** Indice do vetor de n�s da �rvore*/
	int nodeIndex; // Grava o indice no vetor. Usado apenas para satisfazer os requisitos de impress�o dos exerc�cio
	
	ForestNode();
};

#endif