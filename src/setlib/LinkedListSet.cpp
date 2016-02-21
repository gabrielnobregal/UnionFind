#include "LinkedListSet.h"

void LinkedListSet::internalUnion(int x, int y){
  
	// Caso sejam elementos do mesmo conjunto nada deve ocorrer
	if(node[x].set == node[y].set){
		return;
	}
	
	LinkedNode *p = node[x].set->head;

	// Adiciona a lista encadeada de x a y
	node[y].set->tail->next = p; // Coloca lista de x no final da lista y
	node[y].set->tail = node[x].set->tail; // Atualiza tail da lista y
	
	// 2 op. de atualização(concatenação das listas e atualização do tail)
	incPointerOp(2);
	
	// Atualiza o tamanho da nova lista (Usado quando a união poderada estiver ativa)
	// Nao é op. de manipulação de ponteiro, por isso não atualiza nro de operações!!
	node[y].set->size += node[x].set->size;
	
	// Remove o conjunto de x da memória(Ele nao é mais representante)
	delete node[x].set; 
	
	// Altera conjunto(representante) da lista encadeada x
	while(p!=NULL){		
		p->set = node[y].set;
			
		p = p->next;
			
		// 1 op. de ponteiro para percorrimento (p=p->next)
		// 1 op. de atualização de conjunto
		incPointerOp(2); 
	}		
}

void LinkedListSet::incPointerOp(int heuristic, int n){
	if(this->getHeuristic() == heuristic){
		ptrOperations+=n;
	}
}

void LinkedListSet::incPointerOp(int n){
	ptrOperations+=n;
}

unsigned long LinkedListSet::getPointerOperationsState(){
	return ptrOperations;  
}

void LinkedListSet::clearPointerOperations(){
	ptrOperations = 0;  
}

LinkedListSet::LinkedListSet(int size):nElements(size), ptrOperations(0){
	node = new LinkedNode[size];
	setHeuristic(DEFAULT_UNION);	
}

LinkedListSet::~LinkedListSet(){
	release();
}

void LinkedListSet::setHeuristic(int type){
	unionType = type;
}

int LinkedListSet::getHeuristic(){
	return unionType;
}

int LinkedListSet::size(){
	return nElements;
}

bool LinkedListSet::makeSet(int n){

	if( n>=size() ){
		return false;
	}

	
	Set *p = new Set();

	// Configurando o novo conjunto
	p->head = &node[n];
	p->tail = &node[n];
	p->size = 1;
	p->nodeIndex = n;
	
	
	// Atualizando ponteiro
	node[n].set = p;
	node[n].next = NULL;
	
	return true;
}

int LinkedListSet::findSet(int n){

	if( n>=size() ){
		return -1;
	}		
	
	return node[n].set->nodeIndex;		
}

bool LinkedListSet::unionSet(int x, int y){
	if(x>=size() || y>=size()){
		return false;
	}
		
	if(getHeuristic() == this->WEIGHTED_UNION){
		if(node[x].set->size > node[y].set->size){
			this->internalUnion(y, x); // Realiza união da menor lista na maior
			return true;
		}
	}
	
	
	// Realiza união normal ou união ponderada quando x é o conjunto com menor número de elementos
	this->internalUnion(x, y);				
	
	return true;
}

string LinkedListSet::state(){
	stringstream ss;
	
	for(int i=0;i<size();i++){
		ss << node[i].set->nodeIndex <<" ";
	}
		
	return ss.str();
}

void LinkedListSet::release(){
  
	// Remove todos os nós de conjunto.
	for(int i=0;i<size();i++){
	  Set *p = node[i].set;
	  if(p!=NULL){
	    delete p; // Deleta conjunto
	    for(int j=i+1; j<size();j++){ // Verifica se um nó a frente aponta para o mesmo conjunto
		  if(node[j].set == p){
		    // Como o nó ja foi previamente deletado é marcado como NULL
		    // evitando que ele seja deletado novamente e um leak de memória seja gerado
		    node[j].set = NULL;
		  }
	    }	   
	  }
	  
	}
	
	// Remove o vetor de nós
	if(node != NULL){
	  delete [] node;
	  node = NULL;
	}
	
	ptrOperations = 0;
}

