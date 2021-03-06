/**
 *	Conjunto utilizado pela implementa��o de listas encadeadas.
 * 
 * 	@author Gabriel Nobgrega de Lima
 * 	@version 1.0
 * 	
 */ 

#ifndef SET_H
#define SET_H

// Evita inclus�o circular de headers
class LinkedNode;

class Set{
public:
	
	/** Cabe�a da lista */
	LinkedNode *head; 
	/** Cauda da lista */
	LinkedNode *tail; 
	/** Indice do n�. */
	int nodeIndex; // Fins did�ticos, permite impress�o do indice do representante
	/** Tamanho da lista */
	int size; 
	
};


#endif