/**
 *	Implementacao de conjuntos disjuntos para a disciplina 
 *      Algoritmo e Estrutura de Dados II.
 *  
 * 	@author Gabriel Nobgrega de Lima
 * 	@version 1.0
 * 	
 */ 

#include <iostream>
#include "UnionFindApp.h"
#include <string.h>
#include <stdlib.h>

using namespace std;

void inputFile(const char* inputFile,  UnionFindApp &app){
	//Verificar se arquivo existe...
	app.setInputDataFile(inputFile);	
}

void outputFile(const char* inputFile,  UnionFindApp &app){
	//Verificar se arquivo existe...
	app.setOutputDataFile(inputFile);	
}
void error(string msg){
	cout<<msg<<endl;	
	exit(EXIT_FAILURE);
}
void helpScreen(){
cout<<endl<<endl;
cout<<"Parâmetros"<<endl;
cout<<"-i: Define o arquivo de entrada com as operações de união."<<endl;
cout<<"\t ex: ./unionfindapp -i uf2.txt"<<endl<<endl<<endl;

cout<<"-o: Define o arquivo de saída, onde sao imprimidos os estados de cada conjunto."<<endl; 
cout<<"\t ex: ./unionfindapp -i uf2.txt -o saida.txt"<<endl<<endl<<endl;

cout<<"-t: Tipo de estrutura de dados."<<endl; 
cout<<"\t linkedlist: Implementa a estrutura union-find com listas encadeadas."<<endl;
cout<<"\t\tex: ./unionfindapp -i uf2.txt -o saida.txt -t linkedlist"<<endl;
cout<<"\t forest: Implementa a estrutura union-find com florestas."<<endl;
cout<<"\t\tex: ./unionfindapp -i uf2.txt -o saida.txt -t forest"<<endl<<endl<<endl;

cout<<"-h: Heuristica utilizada."<<endl; 
cout<<"\t Para listas encadeadas(-t linkedlist):"<<endl;
cout<<"\t\t default: Sem heuristica (padrao)."<<endl;
cout<<"\t\t weighted: Uniao ponderada."<<endl;
cout<<"\t\t\tex: ./unionfindapp -i uf2.txt -o saida.txt -t linkedlist -h weighted"<<endl<<endl;

cout<<"\t Para listas encadeadas(-t forest):"<<endl;
cout<<"\t\t default: Sem heuristica (padrao)"<<endl;
cout<<"\t\t compweighted: Uniao ponderada e compressao de caminhos."<<endl;
cout<<"\t\t\tex: ./unionfindapp -i uf2.txt -o saida.txt -t forest -h compweighted"<<endl<<endl<<endl;


cout<<"Controle da captura de estados"<<endl;
cout<<"\t\t -sstart: Iteração inicial de captura."<<endl;
cout<<"\t\t -sinc: Incremento de captura."<<endl;
cout<<"\t\t -ssize: Número total de capturas."<<endl;
cout<<"\t\t\t./unionfindapp -t forest -h compweighted -i uf1.txt -sstart 1000 -sinc 1000 -ssize 20"<<endl<<endl<<endl;



cout<<"\t -statistics: Imprime em arquivo as atualizações de ponteiro a cada 1000 operações de união."<<endl;
cout<<"\t\t./unionfindapp -t forest -h compweighted -i uf1.txt -statistics statUF2LinkedListDefault.txt -sstart 1000 -sinc 1000 -ssize 20"<<endl<<endl<<endl;

}

int main( int argc, const char* argv[] ){
	UnionFindApp app;
	
	if(argc<=2){
		helpScreen();
		return 1; 
	}
	
	
	for(int i=1;i<argc;i++){
			
		// Arquivo de entrada
		if(strcmp(argv[i], "-i") == 0){
			if( (i+1) < argc){
				inputFile(argv[i+1], app);			
			}
			i++;continue;
		}
		
		// Arquivo de saída
		if(strcmp(argv[i], "-o") == 0){
			if( (i+1) < argc){
				outputFile(argv[i+1], app);			
			}
			i++;continue;
		}
		
		// Tipo de estrutura de dados
		if(strcmp(argv[i], "-t") == 0){
			if( (i+1) < argc){
				if(strcmp(argv[i+1],"linkedlist") == 0)
					app.setDataStructureType(UnionFindApp::LINKEDLIST_DATA_STRUCTURE);else
				if(strcmp(argv[i+1],"forest") == 0){
					app.setDataStructureType(UnionFindApp::FOREST_DATA_STRUCTURE);}else	
				error("Informe um tipo de estrutura de dados válido para o parâmetro -t");			
			}else{
				error("Informe um tipo de de estrutura valida para o parâmetro -t");			  
			}
			  
			i++;continue;
			
		}
		
		// Tipo de heurística
		if(strcmp(argv[i], "-h") == 0){
			if( (i+1) < argc){
				if(strcmp(argv[i+1],"default") == 0)
					app.setHeuristic(UnionFindApp::DEFAULT_HEURISTIC);else
				if(strcmp(argv[i+1],"weighted") == 0)
					app.setHeuristic(UnionFindApp::WEIGHTED_UNION_HEURISTIC);else
				if(strcmp(argv[i+1],"compweighted") == 0)
					app.setHeuristic(UnionFindApp::COMPRESS_AND_WEIGHTED_HEURISTIC);else{				
					error("Informe um tipo de heuristica valida para o parâmetro -h");		
				}
			}else{
				error("Informe uma heuristica valida para o parâmetro -h");			  
			}
			
			i++;continue;		  
			
		}
		
		// União inicial
		if(strcmp(argv[i], "-sstart") == 0){
			if( (i+1) < argc){
				app.setViewStateStart(atoi(argv[i+1]));				
			}else{
				error("Sem argumento para -sstart");
			}
			i++;continue;		  
		}
		
		// Incremento de união
		if(strcmp(argv[i], "-sinc") == 0){
			if( (i+1) < argc){
				app.setViewStateInc(atoi(argv[i+1]));				
			}else{
				error("Sem argumento para -sinc");
			}
			i++;continue;		  
		}
		
		// Número de uniões a serem capturadas
		if(strcmp(argv[i], "-ssize") == 0){
			if( (i+1) < argc){
				app.setViewStateSize(atoi(argv[i+1]));				
			}else{
				error("Sem argumento para -ssize");
			}
			i++;continue;		  
		}

		// Ativa captura do número de operações de ponteiro a cada 1000 uniões
		if(strcmp(argv[i], "-statistics") == 0){
			if( (i+1) < argc){
				app.setStatisticMode(true, argv[i+1]);				
			}else{
				error("Sem argumento para -statistics");
			}
			i++;continue;		  
		}
	}	
	
	
	
	// Inicia aplicação
	app.start();
	
	cout<<"Numero de operacoes de ponteiro:"<<app.getPointerOperationsState()<<endl;
	return 0;
}
