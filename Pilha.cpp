#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

//Pilha1

TipoCelula1 *Topo1; //Variável para controlar  a pilha, quue aponta para o item do topo

int Contador1;  //Variável para contar o número de elementos armazenados na Pilha

//Função para construir a pilha
void Pilha1_Construtor()
{
    Topo1 = NULL;  //Inicializando o ponteiro como nulo para evitar que ele aponte para lixo de memoria
    Contador1 = 0;  //Inicia a variável para indicar a quantidade de elementos armazenados na Pilha
}

//Metodo para liberar o espaço alocado para a pilha
void Pilha1_Destrutor()
{
    TipoCelula1 *Temp1;  //Ponteiro temporário utilizado para desalocar a memória

    while(Topo1 != NULL)  //Enquanto Topo não chegar em Nulo (Enquanto a Pilha não estiver vazia)
    {
        Temp1 = Topo1;  //o ponteiro temporário deve apontar para o mesmo endereço que Topo
        Topo1 = Topo1 -> Prox1; //Topo avança para a célula seguinte

        Temp1->Prox1 = NULL; //Para quebrar o vínculo que existia entre as células da Pilha (segurança)
        free(Temp1);  //desaloca o espaço de memória (célula) apontado por Temp
    }

    Contador1 = 0;
}

//Função para indicar se a Pilha está ou não vazia
bool Pilha1_Vazia()
{
    return Topo1 == NULL;   /*Se o resultado for verdadeiro, significa que a pilha está vazia se retornar
                           falso, Significa que ainda existem itens na pilha*/
}

//Função para retornar a quantidade de elementos armazenados na Pilha
int Pilha1_Tamanho()
{
    return Contador1; //É retornado o contador de elementos, manipulado nos métodos de Empilhar e Desempilhar
}

//Função para adicionar elementos do topo da Pilha
bool Pilha1_Empilhar(TipoDado1 Elemento1)
{
    TipoCelula1 *Nova1;  //Ponteiro temporário utilizado para apontar para a nova célula a ser criada

    if((Nova1 = (TipoCelula1 *) malloc(sizeof(TipoCelula1)))==NULL)  //tenta alocar dinâmicamente na memória umam nova célula da Pilha
    {
        //e Nova deve apontar para esse endereço de memória

        //caso não for possível alocar mais uma célula na memória (Nova aponta para NULL e torna a condição do if verdadeira)
        //Retona falso, indicando que nenhum elemento foi empilhado (não foi possível alocar mais memória)
        return false;
    }
    else
    {
        Nova1->Item1 = Elemento1;  //Como Nova aponta para um espaço de memória disponível, guardamos o Elemento a ser armazenado nesse espaço
        Nova1->Prox1 = Topo1;      //Para fazer a ligação entre as células da Pilha, o novo espaço de memória reservado
        //e apontado por Nova possui um ponteiro Prox que deve apontar para célua seguinte
        //Nesse caso, o ponteiro Prox deve apontar para o mesmo endereço que Topo aponta
        //Resumindo: O Prox do Nova aponta agora para Topo

        Topo1 = Nova1;            //Como a Pilha possui agora um novo topo apontado por Nova e o ponteiro Topo está um nível abaixo
        //deve-se fazer com que Topo aponte para a nova célula criada

        Contador1++;             //Como foi armazenado um novo Elemento, o contador deve ser incrementado

        return true;            //Retorna verdadeiro, indicando que o elemento foi empilhado (inserido na Pilha)
    }
}

//Função para retirar itens do topo da pilha
bool Pilha1_Desempilhar(TipoDado1 &Elemento1)
{

    if(!Pilha1_Vazia())  //primeiro deve-se conferir se a Pilha não está vazia
    {

        TipoCelula1 *Temp1 = Topo1;  //Cria um ponteiro temporário (Temp) e faz apontar para o mesmo endereço de Topo
        //Essa célula será excluída da Pilha

        Topo1 = Topo1->Prox1; //Faz o topo apontar para a célula seguinte
        //Esse procedimento define a célula eleita como topo da Pilha

        Elemento1 = Temp1->Item1;  //O Elemento a ser retornado está na célula que será excluída
        //Esse elemento é o último que foi empilhado (inserido na Pilha)

        Temp1->Prox1 = NULL;  //Remove a ligação entre a célula a ser excluída e a célula de topo da Pilha (segurança)

        free(Temp1);         //Desaloca o espaço de memória reservado pela célula apontada por Temp
        //(devolve esse espaço de memória ao sistema)

        Contador1--;          //Como foi removido um Elemento, o contador deve ser decrementado

        return true;        //Retona verdadeiro, indicando que o elemento foi removido
    }
    else  //caso a Pilha esteja vazia
        return false;      //Retona falso, indicando que nenhum elemento foi removido (Não há Elemento para ser removido, a Pilha está vazia)
}


//Função que retorna o valor do topo da pilha sem removelo
bool Pilha1_Topo(TipoDado1 &Elemento1)
{

    if(!Pilha1_Vazia())  //primeiro deve-se conferir se a Pilha não está vazia
    {
        Elemento1 = Topo1->Item1;  //Topo aponta uma célula com o último elemento empilhado

        return true;  //retorna verdadeiro indicando que o último elemento da Pilha foi retornado (mas não desempilhado)
    }
    else //caso a Pilha esteja vazia
        return false;  //retorna falso, indicando que não foi possível retornar o elemento
}

//Pilha2

TipoCelula2 *Topo2; //Variável para controlar  a pilha, quue aponta para o item do topo

int Contador2;  //Variável para contar o número de elementos armazenados na Pilha

//Função para construir a pilha
void Pilha2_Construtor()
{
    Topo2 = NULL;  //Inicializando o ponteiro como nulo para evitar que ele aponte para lixo de memoria
    Contador2 = 0;  //Inicia a variável para indicar a quantidade de elementos armazenados na Pilha
}

//Metodo para liberar o espaço alocado para a pilha
void Pilha2_Destrutor()
{
    TipoCelula2 *Temp2;  //Ponteiro temporário utilizado para desalocar a memória

    while(Topo2 != NULL)  //Enquanto Topo não chegar em Nulo (Enquanto a Pilha não estiver vazia)
    {
        Temp2 = Topo2;  //o ponteiro temporário deve apontar para o mesmo endereço que Topo
        Topo2 = Topo2 -> Prox2; //Topo avança para a célula seguinte

        Temp2->Prox2 = NULL; //Para quebrar o vínculo que existia entre as células da Pilha (segurança)
        free(Temp2);  //desaloca o espaço de memória (célula) apontado por Temp
    }

    Contador2 = 0;
}

//Função para indicar se a Pilha está ou não vazia
bool Pilha2_Vazia()
{
    return Topo2 == NULL;   /*Se o resultado for verdadeiro, significa que a pilha está vazia se retornar
                           falso, Significa que ainda existem itens na pilha*/
}

//Função para retornar a quantidade de elementos armazenados na Pilha
int Pilha2_Tamanho()
{
    return Contador2; //É retornado o contador de elementos, manipulado nos métodos de Empilhar e Desempilhar
}

//Função para adicionar elementos do topo da Pilha
bool Pilha2_Empilhar(TipoDado2 Elemento2)
{
    TipoCelula2 *Nova2;  //Ponteiro temporário utilizado para apontar para a nova célula a ser criada

    if((Nova2 = (TipoCelula2 *) malloc(sizeof(TipoCelula2)))==NULL)  //tenta alocar dinâmicamente na memória umam nova célula da Pilha
    {
        //e Nova deve apontar para esse endereço de memória

        //caso não for possível alocar mais uma célula na memória (Nova aponta para NULL e torna a condição do if verdadeira)
        //Retona falso, indicando que nenhum elemento foi empilhado (não foi possível alocar mais memória)
        return false;
    }
    else
    {
        Nova2->Item2 = Elemento2;  //Como Nova aponta para um espaço de memória disponível, guardamos o Elemento a ser armazenado nesse espaço
        Nova2->Prox2 = Topo2;      //Para fazer a ligação entre as células da Pilha, o novo espaço de memória reservado
        //e apontado por Nova possui um ponteiro Prox que deve apontar para célua seguinte
        //Nesse caso, o ponteiro Prox deve apontar para o mesmo endereço que Topo aponta
        //Resumindo: O Prox do Nova aponta agora para Topo

        Topo2 = Nova2;            //Como a Pilha possui agora um novo topo apontado por Nova e o ponteiro Topo está um nível abaixo
        //deve-se fazer com que Topo aponte para a nova célula criada

        Contador2++;             //Como foi armazenado um novo Elemento, o contador deve ser incrementado

        return true;            //Retorna verdadeiro, indicando que o elemento foi empilhado (inserido na Pilha)
    }
}

//Função para retirar itens do topo da pilha
bool Pilha2_Desempilhar(TipoDado2 &Elemento2)
{

    if(!Pilha2_Vazia())  //primeiro deve-se conferir se a Pilha não está vazia
    {

        TipoCelula2 *Temp2 = Topo2;  //Cria um ponteiro temporário (Temp) e faz apontar para o mesmo endereço de Topo
        //Essa célula será excluída da Pilha

        Topo2 = Topo2->Prox2; //Faz o topo apontar para a célula seguinte
        //Esse procedimento define a célula eleita como topo da Pilha

        Elemento2 = Temp2->Item2;  //O Elemento a ser retornado está na célula que será excluída
        //Esse elemento é o último que foi empilhado (inserido na Pilha)

        Temp2->Prox2 = NULL;  //Remove a ligação entre a célula a ser excluída e a célula de topo da Pilha (segurança)

        free(Temp2);         //Desaloca o espaço de memória reservado pela célula apontada por Temp
        //(devolve esse espaço de memória ao sistema)

        Contador2--;          //Como foi removido um Elemento, o contador deve ser decrementado

        return true;        //Retona verdadeiro, indicando que o elemento foi removido
    }
    else  //caso a Pilha esteja vazia
        return false;      //Retona falso, indicando que nenhum elemento foi removido (Não há Elemento para ser removido, a Pilha está vazia)
}


//Função que retorna o valor do topo da pilha sem removelo
bool Pilha2_Topo(TipoDado2 &Elemento2)
{

    if(!Pilha2_Vazia())  //primeiro deve-se conferir se a Pilha não está vazia
    {
        Elemento2 = Topo2->Item2;  //Topo aponta uma célula com o último elemento empilhado

        return true;  //retorna verdadeiro indicando que o último elemento da Pilha foi retornado (mas não desempilhado)
    }
    else //caso a Pilha esteja vazia
        return false;  //retorna falso, indicando que não foi possível retornar o elemento
}

//Pilha3

TipoCelula3 *Topo3; //Variável para controlar  a pilha, quue aponta para o item do topo

int Contador3;  //Variável para contar o número de elementos armazenados na Pilha

//Função para construir a pilha
void Pilha3_Construtor()
{
    Topo3 = NULL;  //Inicializando o ponteiro como nulo para evitar que ele aponte para lixo de memoria
    Contador3 = 0;  //Inicia a variável para indicar a quantidade de elementos armazenados na Pilha
}

//Metodo para liberar o espaço alocado para a pilha
void Pilha3_Destrutor()
{
    TipoCelula3 *Temp3;  //Ponteiro temporário utilizado para desalocar a memória

    while(Topo3 != NULL)  //Enquanto Topo não chegar em Nulo (Enquanto a Pilha não estiver vazia)
    {
        Temp3 = Topo3;  //o ponteiro temporário deve apontar para o mesmo endereço que Topo
        Topo3 = Topo3 -> Prox3; //Topo avança para a célula seguinte

        Temp3->Prox3 = NULL; //Para quebrar o vínculo que existia entre as células da Pilha (segurança)
        free(Temp3);  //desaloca o espaço de memória (célula) apontado por Temp
    }

    Contador3 = 0;
}

//Função para indicar se a Pilha está ou não vazia
bool Pilha3_Vazia()
{
    return Topo3 == NULL;   /*Se o resultado for verdadeiro, significa que a pilha está vazia se retornar
                           falso, Significa que ainda existem itens na pilha*/
}

//Função para retornar a quantidade de elementos armazenados na Pilha
int Pilha3_Tamanho()
{
    return Contador3; //É retornado o contador de elementos, manipulado nos métodos de Empilhar e Desempilhar
}

//Função para adicionar elementos do topo da Pilha
bool Pilha3_Empilhar(TipoDado3 Elemento3)
{
    TipoCelula3 *Nova3;  //Ponteiro temporário utilizado para apontar para a nova célula a ser criada

    if((Nova3 = (TipoCelula3 *) malloc(sizeof(TipoCelula3)))==NULL)  //tenta alocar dinâmicamente na memória umam nova célula da Pilha
    {
        //e Nova deve apontar para esse endereço de memória

        //caso não for possível alocar mais uma célula na memória (Nova aponta para NULL e torna a condição do if verdadeira)
        //Retona falso, indicando que nenhum elemento foi empilhado (não foi possível alocar mais memória)
        return false;
    }
    else
    {
        Nova3->Item3 = Elemento3;  //Como Nova aponta para um espaço de memória disponível, guardamos o Elemento a ser armazenado nesse espaço
        Nova3->Prox3 = Topo3;      //Para fazer a ligação entre as células da Pilha, o novo espaço de memória reservado
        //e apontado por Nova possui um ponteiro Prox que deve apontar para célua seguinte
        //Nesse caso, o ponteiro Prox deve apontar para o mesmo endereço que Topo aponta
        //Resumindo: O Prox do Nova aponta agora para Topo

        Topo3 = Nova3;            //Como a Pilha possui agora um novo topo apontado por Nova e o ponteiro Topo está um nível abaixo
        //deve-se fazer com que Topo aponte para a nova célula criada

        Contador3++;             //Como foi armazenado um novo Elemento, o contador deve ser incrementado

        return true;            //Retorna verdadeiro, indicando que o elemento foi empilhado (inserido na Pilha)
    }
}

//Função para retirar itens do topo da pilha
bool Pilha3_Desempilhar(TipoDado3 &Elemento3)
{

    if(!Pilha3_Vazia())  //primeiro deve-se conferir se a Pilha não está vazia
    {

        TipoCelula3 *Temp3 = Topo3;  //Cria um ponteiro temporário (Temp) e faz apontar para o mesmo endereço de Topo
        //Essa célula será excluída da Pilha

        Topo3 = Topo3->Prox3; //Faz o topo apontar para a célula seguinte
        //Esse procedimento define a célula eleita como topo da Pilha

        Elemento3 = Temp3->Item3;  //O Elemento a ser retornado está na célula que será excluída
        //Esse elemento é o último que foi empilhado (inserido na Pilha)

        Temp3->Prox3 = NULL;  //Remove a ligação entre a célula a ser excluída e a célula de topo da Pilha (segurança)

        free(Temp3);         //Desaloca o espaço de memória reservado pela célula apontada por Temp
        //(devolve esse espaço de memória ao sistema)

        Contador3--;          //Como foi removido um Elemento, o contador deve ser decrementado

        return true;        //Retona verdadeiro, indicando que o elemento foi removido
    }
    else  //caso a Pilha esteja vazia
        return false;      //Retona falso, indicando que nenhum elemento foi removido (Não há Elemento para ser removido, a Pilha está vazia)
}


//Função que retorna o valor do topo da pilha sem removelo
bool Pilha3_Topo(TipoDado3 &Elemento3)
{

    if(!Pilha3_Vazia())  //primeiro deve-se conferir se a Pilha não está vazia
    {
        Elemento3 = Topo3->Item3;  //Topo aponta uma célula com o último elemento empilhado

        return true;  //retorna verdadeiro indicando que o último elemento da Pilha foi retornado (mas não desempilhado)
    }
    else //caso a Pilha esteja vazia
        return false;  //retorna falso, indicando que não foi possível retornar o elemento
}
