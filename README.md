#Union Find

Este projeto realiza um estudo sobre operações em conjuntos disjuntos. Para uma análise teórica e comportamental verifique o relatório disponível na raiz do projeto.

## Compilando e executando o projeto

O projeto foi desenvolvido em linguagem C++, sendo assim será necessário a utilização
do compilador g++. Tente executar o g++ pelo terminal, caso este não seja localizado
será necessário instala-lo. Nas distribuições derivadas do Debian (por ex:Ubuntu), a
instalação pode ser realizada através do comando:

sudo apt-get install g++

Com o compilador instalado o projeto pode ser compilado com o comando make
dentro do diretório src do projeto.

make

O comando irá gerar o binário unionfindapp dentro do diretório src. Para executa-lo utilize
o comando:

./unionfindapp 

Para eliminar todos os arquivos binários gerados no processo de compilação execute o comando:

make clear

## Parâmetros de Execução
Você pode obter a lista de parâmetros executando o programa sem qualquer argumento, ou seja, chamando apenas ./unionfindapp . Você também pode ver esta lista e como foi respondido cada item do laboratório no relatório. Veja as seções "Interface de usuário" e "Resposta dos Itens".

## Hierarquia de diretórios
O código fonte do projeto está disponível no diretóio src. A documentação das classes pode ser acessadas em doc/index.html.

## Documentação
Foi gerada a documentação da API pública das classes de conjuntos disjuntos. Você pode visualiza-la em doc/index.html . Existe a possibilidade de consulta-la diretamente nos headers contidos em src/setlib e src. 

