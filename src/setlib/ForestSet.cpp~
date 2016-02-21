#include "ForestSet.h"


int ForestSet::getTreeRoot(int n){
	ForestNode *p = &node[n];

	// Percorre a árvore até encontrar a raiz/representante
	while( !(p == p->next) ){
		p = p->next;
	}

	return p->nodeIndex;
}

int ForestSet::internalFindSet(int n){
	ForestNode *p = &node[n];
	
	
	
	while( !(p == p->next) ){
		p = p->next;		
		// 1 percorrimento
		incPointerOp(1);		
	}
	
	// O ultimo ou primeiro percorrimento do whille encontra a raiz e não entra(ele é computado aqui)
	incPointerOp(1);
	
	return p->nodeIndex;
}

int ForestSet::internalCompressedFindSet(int n){
	int treeRoot = -1;
	
	// Percorre um ponteiro (Vai para o próximo ponteiro)
	incPointerOp(1);
	
	if(node[n].nodeIndex != node[n].next->nodeIndex){// ou &node[n] != node[n].next){
		treeRoot = internalCompressedFindSet(node[n].next->nodeIndex);
	}else{
		// Chegou na raiz
		return node[n].nodeIndex;
	}

	// Aponta diretamente para o representante(Raiz da árvore)	
	node[n].next = &node[treeRoot];	
	// Atualização do ponteiro next
	incPointerOp(1);
	
		
	return treeRoot;
}

ForestSet::ForestSet(int size):nElements(size),ptrOperations(0){
	node = new ForestNode[size];
}

ForestSet::~ForestSet(){
	release();
}

void ForestSet::setHeuristic(int type){
	unionType = type;
}

int ForestSet::getHeuristic(){
	return unionType;
}

int ForestSet::size(){
	return nElements;
}

bool ForestSet::makeSet(int n){
	if( n>=size() ){
		return false;
	}

	// Atualiza nó
	node[n].nodeIndex = n;
	node[n].next = &node[n];
	node[n].rank = 1;

	return true;
}

int ForestSet::findSet(int n){

	// Se o elemento é maior que o número total de elementos
	if( n>=size() ){
		return -1;
	}

	int setIndex = -1;

	// Chama o findSet apropriado para a heurística utilizada  
	if(getHeuristic() == this->COMPRESS_AND_WEIGHTED_HEURISTIC){
		setIndex = this->internalCompressedFindSet(n);
	}else
	if(getHeuristic() == this->DEFAULT_HEURISTIC){
		setIndex = this->internalFindSet(n);
	}

	
	return setIndex;
}

bool ForestSet::unionSet(int x, int y){
	if( x>=size() || y>=size() ){
		return false;
	}	

	// Ponteiro do representante da floresta x tem seu ponteiro "next" apontado para a raiz da floresta de y
	int yRoot = findSet(y);
	int xRoot = findSet(x);
		
	// Pertencem ao mesmo conjunto, nada deve ocorrer
	if(yRoot == xRoot){
		return true;
	}
	

	if(getHeuristic() == this->COMPRESS_AND_WEIGHTED_HEURISTIC){
		// União ponderada
		if(node[xRoot].rank > node[yRoot].rank ){
			node[yRoot].next = &node[xRoot];
			node[xRoot].rank += node[yRoot].rank;
			// 1 op. atualiza ptr next
			incPointerOp(1);
			return true;
		}

	}		

	// Caso a heuristica seja this->DEFAULT_HEURISTIC ou o rank de y é maior ou igual que o de x
	node[yRoot].rank += node[xRoot].rank;
	node[xRoot].next = &node[yRoot];
	// 1 op. atualiza ptr next
	incPointerOp(1);
	
	return true;
}

string ForestSet::state(){
	stringstream ss;
	
	for(int i=0;i<size();i++){
		ss<<this->getTreeRoot(i)<<" ";
	}
	
	return ss.str();
}

unsigned long ForestSet::getPointerOperationsState(){
	return ptrOperations;  
}

void ForestSet::incPointerOp(int heuristic, int n){
	if(this->getHeuristic() == heuristic){
		ptrOperations+=n;
	}
}

void ForestSet::incPointerOp(int n){
	ptrOperations+=n;
}

void ForestSet::clearPointerOperations(){
	ptrOperations = 0;  
}
void ForestSet::release(){
	delete [] node;
}
