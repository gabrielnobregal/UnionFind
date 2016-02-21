/**
 *	Nó utilizado nas listas encadeadas.
 * 
 * 	@author Gabriel Nobgrega de Lima
 * 	@version 1.0
 * 	
 */ 

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include <iostream>
#include "Set.h"

class LinkedNode{
public:

    /** Representa o conjunto do nó. */
    Set *set;

 
    /** Próximo nó. */
    LinkedNode *next; 		 
	
    /**
    *Construtor padrão.
    */
    LinkedNode();

    

};
#endif
