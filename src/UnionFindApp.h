/**
* Modela a aplica��o de conjuntos disjuntos. 
* 
* @author Gabriel Nobgrega de Lima
* @version 1.0
* 	
 */ 

#ifndef UNIONFINDAPP_H
#define UNIONFINDAPP_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "setlib/LinkedListSet.h"
#include "setlib/ForestSet.h"

using namespace std;

class UnionFindApp{

private:
	SetManager* setManager; // Faz opera��es union-find de lista encadeada e florestas
	int heuristicType; // Tipo de heur�stica
	int dataStructureType; // Tipo de estrutura de dados
	
	string inputFileName; // Arquivo de entrada (por ex: uf1, uf2)
	string outputFileName; // Arquivo de saida com os estados dos conjuntos
	string statisticFileName; // Arquivo csv com n�mero de opera��es de ponteiro
	
	bool statisticMode; // Gravar ou nao as opera��es de ponteiro(o arquivo statisticFileName)
	
	int viewStateInc; // Incremento do estado de captura
	int viewStateStart; // Determina a uni�o inicial para captura de estado
	int viewStateSize; // N�mero m�ximo de captura de estados
	
	int readFileNumOfElements(string fileName); // L� a primeira linha do arquivo de entrada
	bool processDataFile(string fileName, int numOfElements); // Gera arquivo de estados e de opera��es de ponteiro(caso ativo)
	
public:

	// Tipos de estrutura de dados dipon�veis
	/**Conjuntos disjuntos com listas ligadas*/
	static const int LINKEDLIST_DATA_STRUCTURE = 0; // Implementa union-find com listas ligadas
	/**Conjuntos disjuntos com floresta(avores)*/
	static const int FOREST_DATA_STRUCTURE = 1; // Implementa union-find com florestas

	// Tipos de heur�sticas
	/**Conjuntos disjuntos sem heuristica.*/
	static const int DEFAULT_HEURISTIC = 100; // Implementa a estrutura sem qualquer heur�stica(serve para listas ligadas e florestas)
	/**Conjuntos disjuntos com heuristica de uni�o ponderada. Valido apenas para LINKEDLIST_DATA_STRUCTURE.*/
	static const int WEIGHTED_UNION_HEURISTIC = 101; // Suportado apenas pelas listas encadeadas(faz uni�o ponderada)
	
	/**Conjuntos disjuntos com heuristica de uni�o ponderada e compressao de caminhos. Valido apenas para FOREST_DATA_STRUCTURE.*/
	static const int COMPRESS_AND_WEIGHTED_HEURISTIC = 102; // Suportado apenas pelas florestas(aplica uni�o ponderada e compress�o de caminhos)

	/**Construtor padrao.*/
	UnionFindApp();
	
	/**Destrutor padrao.*/
	~UnionFindApp();
	
	/**
	 * Define uma heuristica. Utilize DEFAULT_HEURISTIC, WEIGHTED_UNION_HEURISTIC ou COMPRESS_AND_WEIGHTED_HEURISTIC.
	 * @param heuristicType Tipo de heuristica (DEFAULT_HEURISTIC, WEIGHTED_UNION_HEURISTIC ou COMPRESS_AND_WEIGHTED_HEURISTIC).
	 */
	void setHeuristic(int heuristicType);
	
	/**
	 * Define a estrutura de dados que implementa os conjuntos disjuntos. Utilize LINKEDLIST_DATA_STRUCTURE ou FOREST_DATA_STRUCTURE.
	 * @param dataStructureType Tipo de estrutura (LINKEDLIST_DATA_STRUCTURE ou FOREST_DATA_STRUCTURE).
	 */
	void setDataStructureType(int dataStructureType);
	
	/**
	 * Define arquivo de entrada contendo as opera��es de uni�o.
	 * @param fileName Caminho do arquivo.
	 */
	void setInputDataFile(string fileName);
	
	/**
	 * Define arquivo de sa�da contendo os estados dos conjuntos.
	 * @param fileName Caminho do arquivo.
	 */
	void setOutputDataFile(string fileName);
	
	/**
	 * Define incremento para a proxima captura de estado.
	 * @param incrementor Valor a ser incrementado.
	 */
	void setViewStateInc(int incrementor);
	
	/**
	 * Define a uniao inicial em que se deve capturar o estado e gravar em arquivo.
	 * @param start Uni�o inicial.
	 */
	void setViewStateStart(int start);
	
	/**
	 * Define o numero de estados a serem gravados em arquivo.
	 * @param size Numero de estados.
	 */
	void setViewStateSize(int size);
	
	/**
	 * Ativa/Desativa a gravacao do numero de operacoes de ponteiro nas unioes.
	 * @param active Ativado(true) ou desativado(false).
	 * @param fileName Caminho do arquivo *.csv que deve ser gerado com o numero de operacoes de ponteiro.
	 */
	void setStatisticMode(bool active, string fileName);
	
	/**
	 * Obt�m o incremento de estados.
	 * @return Incremento de estados.
	 */
	int getViewStateInc();
	
	/**
	 * Obt�m a uniao inicial de captura.
	 * @return Uniao inicial de captura.
	 */
	int getViewStateStart();
	
	/**
	 * Obt�m o numero de estados a serem capturados.
	 * @return Estados a serem capturados.
	 */
	int getViewStateSize();
	
	/**
	 * Obt�m o numero de operacoes de ponteiro nas unioes de conjuntos.
	 * @return Numero de operacoes de ponteiro nas unioes de conjuntos.
	 */
	unsigned long getPointerOperationsState();
	
	/**
	 * Obt�m a heuristica definida.
	 * @return Heuristica.
	 */
	int getHeuristic();
	
	/**
	 * Obt�m a estrutura de conjuntos disjuntos utilizada.
	 * @return Estrutura de conjuntos disjuntos.
	 */
	int getDataStructureType();
	
	/**
	 * Obt�m o caminho do arquivo de entrada com as operacoes de uniao.
	 * @return Caminho do arquivo de entrada com as operacoes de uniao.
	 */
	string getInputDataFile();
	
	/**
	 * Obt�m o caminho do arquivo de saida com os estados dos conjuntos.
	 * @return Caminho do arquivo de saida com os estados dos conjuntos.
	 */
	string getOutputDataFile();
	
	/**
	 * Obt�m o caminho do arquivo que grava as operacoes de ponteiro.
	 * @return Caminho do arquivo que grava as operacoes de ponteiro.
	 */
	string getStatisticDataFile();
	
	/**
	 * Inicia o processamento com as configuracoes previamente realizadas.
	 * @return Sucesso(true) ou falha(false).
	 */
	bool start();
	
	/**
	 * Libera memoria. Chamado automaticamente pelo destrutor.
	 */
	void release();

};

#endif
