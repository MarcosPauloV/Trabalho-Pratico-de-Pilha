#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
//Pilha 1
typedef char TipoDado1; //Define o tipo de dado que será armazenado na Pilha

//Estrutura onde serão armanzenados os itens da pilha
struct TipoCelula1
{
    TipoDado1 Item1;
    TipoCelula1 *Prox1;
};

//Constroi a Pilha
void Pilha1_Construtor();

//Libera a memoria utilizada pela pilha dinamica
void Pilha1_Destrutor();

//Função para identificar se a pilha está cheia ou não
bool Pilha1_Vazia();

//Função para retornar a quantidade de elementos armazenados na Pilha
int Pilha1_Tamanho();

//Função para colocar um item na pilha, se o valor não for alocado ele retorna falso
bool Pilha1_Empilhar(TipoDado1 Elemento1);

//Função para retirar itens da pilha
bool Pilha1_Desempilhar(TipoDado1 &Elemento1);

//Função para retornar o valor que está no topo
bool Pilha1_Topo(TipoDado1 &Elemento1);

//Pilha 2
typedef char TipoDado2; //Define o tipo de dado que será armazenado na Pilha

//Estrutura onde serão armanzenados os itens da pilha
struct TipoCelula2
{
    TipoDado2 Item2;
    TipoCelula2 *Prox2;
};

//Constroi a Pilha
void Pilha2_Construtor();

//Libera a memoria utilizada pela pilha dinamica
void Pilha2_Destrutor();

//Função para identificar se a pilha está cheia ou não
bool Pilha2_Vazia();

//Função para retornar a quantidade de elementos armazenados na Pilha
int Pilha2_Tamanho();

//Função para colocar um item na pilha, se o valor não for alocado ele retorna falso
bool Pilha2_Empilhar(TipoDado2 Elemento2);

//Função para retirar itens da pilha
bool Pilha2_Desempilhar(TipoDado2 &Elemento2);

//Função para retornar o valor que está no topo
bool Pilha2_Topo(TipoDado2 &Elemento2);

//Pilha 3
typedef char TipoDado3; //Define o tipo de dado que será armazenado na Pilha

//Estrutura onde serão armanzenados os itens da pilha
struct TipoCelula3
{
    TipoDado3 Item3;
    TipoCelula3 *Prox3;
};

//Constroi a Pilha
void Pilha3_Construtor();

//Libera a memoria utilizada pela pilha dinamica
void Pilha3_Destrutor();

//Função para identificar se a pilha está cheia ou não
bool Pilha3_Vazia();

//Função para retornar a quantidade de elementos armazenados na Pilha
int Pilha3_Tamanho();

//Função para colocar um item na pilha, se o valor não for alocado ele retorna falso
bool Pilha3_Empilhar(TipoDado3 Elemento3);

//Função para retirar itens da pilha
bool Pilha3_Desempilhar(TipoDado3 &Elemento3);

//Função para retornar o valor que está no topo
bool Pilha3_Topo(TipoDado3 &Elemento3);

#endif // PILHA_H_INCLUDED
