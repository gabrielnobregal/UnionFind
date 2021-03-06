/**
 *	Interface para as estruturas de conjuntos disjuntos.
 * 
 * 	@author Gabriel Nobgrega de Lima
 * 	@version 1.0
 * 	
 */ 

#ifndef SETMANAGER_H
#define SETMANAGER_H

#include <iostream>

using namespace std;

class SetManager{
public:
  
	/**
	 * Cria conjunto n.
	 * @param n Número do conjunto.
	 * @return Verdadeiro caso sucesso e falso caso ocorra um erro.
	 */
	virtual bool makeSet(int n) = 0;
	
	/**
	 * Procura o representante de conjunto do elemento n.
	 * @param n Número do elemento.
	 * @return -1 caso nao encontre.
	 */	
	virtual int findSet(int n) = 0;
	
	/**
	 * União de x em y.
	 * @param x Número de elemento.
	 * @param y Número de elemento.
	 * @return Verdadeiro caso sucesso e falso caso ocorra um erro.
	 */	
	virtual bool unionSet(int x, int y) = 0;
	
	/**
	 * Obtêm os representantes de conjunto de cada elemento.
	 * @return Representantes de conjunto para cada elemento.
	 */	
	virtual string state() = 0;
	
	/**
	 * Obtêm a heurística utilizada.
	 * @return Heurística.
	 */	
	virtual int getHeuristic() = 0;
	
	/**
	 * Define a heurística utilizada.
	 * @param type Heurística.
	 */	
	virtual void setHeuristic(int type) = 0;
	
	/**
	 * Libera memória, automáticamente chamado pelo destrutor.
	 */	
	virtual void release() = 0;
	
	/**
	 * Obtêm o número de operações de ponteiro das uniões.
	 * @return Operações de ponteiro das uniões.
	 */
	virtual unsigned long getPointerOperationsState() = 0;
	
	/**
	 * Define as operações de ponteiro para 0. Utilizado quando
	 * se deseja analisar apenas uma pequena poção de operações.
	 */
	virtual void clearPointerOperations() = 0;
	
	/**
	 * Destrutor padrão.
	 */
	virtual ~SetManager(){
	}
};

#endif