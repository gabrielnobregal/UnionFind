#include "UnionFindApp.h"

UnionFindApp::UnionFindApp(){
	this->setHeuristic(DEFAULT_HEURISTIC);
	this->setDataStructureType(LINKEDLIST_DATA_STRUCTURE);
	this->setViewStateStart(1);
	this->setViewStateInc(1);
	this->setViewStateSize(100);
	this->setOutputDataFile("out.txt");
	this->setInputDataFile("uf.txt");
	this->setStatisticMode(false, "statistic.txt");
	setManager = NULL;
}

UnionFindApp::~UnionFindApp(){
	release();
}

void UnionFindApp::setHeuristic(int heuristicType){
	this->heuristicType = heuristicType;
}
	
void UnionFindApp::setDataStructureType(int dataStructureType){
	this->dataStructureType = dataStructureType;
}

void UnionFindApp::setInputDataFile(string fileName){
	this->inputFileName = fileName;
}

void UnionFindApp::setOutputDataFile(string fileName){
	this->outputFileName = fileName;
}

int UnionFindApp::getHeuristic(){
	return this->heuristicType;
}

int UnionFindApp::getDataStructureType(){
	return this->dataStructureType;
}

string UnionFindApp::getInputDataFile(){
	return this->inputFileName;
}

string UnionFindApp::getOutputDataFile(){
	return this->outputFileName;
}

string UnionFindApp::getStatisticDataFile(){
	return this->statisticFileName;  
}

void UnionFindApp::setStatisticMode(bool active, string fileName){
	this->statisticMode = active;
	this->statisticFileName = fileName;  
}

bool UnionFindApp::start(){
	// Carrega primeira linha do arquivo e verifica o n�mero de elementos
	int nElements = this->readFileNumOfElements(getInputDataFile());	

	if(nElements<=0){
		return false;
	}
	
	cout<<"Numero de elementos:"<<nElements<<endl;

	//Configura o conjunto disjunto de acordo com as configura��es do usu�rio	
	if(getDataStructureType() == this->LINKEDLIST_DATA_STRUCTURE){
		setManager = new LinkedListSet(nElements);
		
		cout<<"Estrutura de dados: Lista Encadeada"<<endl;
		
		if(this->getHeuristic() == DEFAULT_HEURISTIC){
			setManager->setHeuristic(LinkedListSet::DEFAULT_UNION);
			cout<<"Heuristica: Padrao"<<endl;		  
		}else
		if(this->getHeuristic() == WEIGHTED_UNION_HEURISTIC){
			setManager->setHeuristic(LinkedListSet::WEIGHTED_UNION);
			cout<<"Heuristica: Uniao Ponderada"<<endl;		  
		}else{
			cout<<"Heuristica: INVALIDA"<<endl;		  
			return false;
		}
	}else
	if(getDataStructureType() == this->FOREST_DATA_STRUCTURE){
		setManager = new ForestSet(nElements);
		
		cout<<"Estrutura de dados: Floresta"<<endl;
		
		if(this->getHeuristic() == DEFAULT_HEURISTIC){
			setManager->setHeuristic(ForestSet::DEFAULT_HEURISTIC);
			cout<<"Heuristica: Padrao"<<endl;		  
		}else
		if(this->getHeuristic() == COMPRESS_AND_WEIGHTED_HEURISTIC){
			setManager->setHeuristic(ForestSet::COMPRESS_AND_WEIGHTED_HEURISTIC);
			cout<<"Heuristica: Uniao Ponderada e Compressao de Arvores"<<endl;	  
		}else{
			cout<<"Heuristica: INVALIDA"<<endl;		
			return false;
		}

	}else{
		cout<<"Estrutura de dados: INVALIDA"<<endl;
		return false;
	}
	
	processDataFile(getInputDataFile(), nElements);

	return true;
}

int UnionFindApp::readFileNumOfElements(string fileName){
	string word;

	// Adiciona as palavras do arquivo na tabela hash
	ifstream inFile (fileName);
	if (inFile.is_open()){			
		getline (inFile, word);
		return atoi(word.c_str());
	}
	
	inFile.close();
	
	return -1;
}

bool UnionFindApp::processDataFile(string fileName, int numOfElements){
	
	string word;
	cout<<"Arquivo de Entrada:"<<this->getInputDataFile()<<endl;
	cout<<"Arquivo de Saida:"<<this->getOutputDataFile()<<endl;
	
	if(statisticMode){
		cout<<"Arquivo de Estatistica:"<<this->getStatisticDataFile()<<endl;
	}
	cout<<"Processando..."<<endl;
	// Inicializa os elementos do conjunto
	for(int i=0;i<numOfElements;i++){
		setManager->makeSet(i);
	}
	
	ifstream inFile; // Arquivo de entrada
	inFile.open(this->getInputDataFile());
	
	if(!inFile.good())
	  return false;
	
	ofstream outFile (this->getOutputDataFile()); // Arquivo de sa�da(possui os estados das uni�es)
	
	ofstream statisticFile; // Arquivo de estat�sticas(opera��es de ponteiro)
	
	
	// Caso se deseje obter n�mero de opera��es de ponteiro
	if(statisticMode){
		statisticFile.open(this->getStatisticDataFile());	  
	}
	
	
	
	char dummyLine[255]; // Carrega a primeira linha para deixar o ponteiro na primeira uni�o
	inFile.getline(dummyLine, sizeof(dummyLine));
	int numberOfUnions = 0; // N�mero de uni�es
	int nextRecordedState = this->getViewStateStart(); // Primeiro estado de captura deve ser na uni�o getViewStateStart
	int numOfRecordedState = 0; // N�mero de estados capturados
	
	
	while(inFile.good()){	
		
		char buf[255];
		inFile.getline(buf, sizeof(buf));
		
		//eof s� � atualizado ap�s getline. Isto evita aplicar parser no final do arquivo.
		// A remo��o ir� causar segmentation fault
		if(inFile.eof()){ 
		    break;
		}
		
		const char* xy[2]= {0};
		
		// Obt�m primeiro e segundo elemento da uni�o do arquivo de entrada
		xy[0] = strtok(buf, " ");
		xy[1] = strtok(NULL, " ");
		
		int x = atoi(xy[0]); 
		int y = atoi(xy[1]);
		
		// Realiza uni�o
		setManager->unionSet(x,y);
		numberOfUnions++;
				
		// Escreve n�mero de opera��es de ponteiro caso o modo de estatistica esteja ativado
		if(statisticMode && (numberOfUnions % 1000) ==0 ){
			cout<<"Registrando operacoes de ponteiro para a uniao "<<numberOfUnions<<"..."<<endl;
			statisticFile<<numberOfUnions<<","<<setManager->getPointerOperationsState()<<endl;		  
		}		
				
		
		
		// Caso ainda restem estados a serem gravados na sa�da
		if(numberOfUnions == nextRecordedState && numOfRecordedState<this->getViewStateSize()){
			  outFile<<setManager->state()<<endl;
			  
			  // Atualiza estado de captura
			  nextRecordedState += this->getViewStateInc();
			  numOfRecordedState++;
			  cout<<"Escrevendo o estado "<<numberOfUnions<<"..."<<endl;	
			  
			  if(numOfRecordedState==this->getViewStateSize()){		
				cout<<"A captura de estados foi concluida..."<<endl;
				
				// Caso o modo de estatistica n�o esteja ativo o usu�rio pode querer sair!
				if(!statisticMode){
					int a=-1;
					while(a!=1 && a!=0){
					      cout<<"A captura de operacoes de ponteiro esta desativada. Deseja continuar o processamento?"<<endl<<"Sim(1), Nao(0):";
					      cin>>a;					  
					}
					
					if(a==0){
					      break;
					}
					      
					
				}else
					cout<<"Coletando estatistica restante, por favor aguarde..."<<endl;
				
				
			  }
		}
				
	}
	
	// Fecha os arquivos abertos
	outFile.close();
	inFile.close();
	
	if(statisticMode){
		statisticFile.close();
	}
	
	cout<<"Concluido..."<<endl;
	return true;
}



void UnionFindApp::setViewStateInc(int incrementor){
	this->viewStateInc = incrementor;  
}

void UnionFindApp::setViewStateStart(int start){
	this->viewStateStart = start;  
}

void UnionFindApp::setViewStateSize(int size){
	this->viewStateSize = size;  
}

int UnionFindApp::getViewStateInc(){
	return this->viewStateInc;
}

int UnionFindApp::getViewStateStart(){
	return this->viewStateStart;  
}

int UnionFindApp::getViewStateSize(){
	return this->viewStateSize;  
}

unsigned long UnionFindApp::getPointerOperationsState(){
	return setManager->getPointerOperationsState();
}

void UnionFindApp::release(){
	if(setManager!=NULL){
	  delete setManager;
	  setManager = NULL;
	}
}
