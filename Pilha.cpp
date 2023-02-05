#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

//Pilha1

TipoCelula1 *Topo1; //Vari�vel para controlar  a pilha, quue aponta para o item do topo

int Contador1;  //Vari�vel para contar o n�mero de elementos armazenados na Pilha

//Fun��o para construir a pilha
void Pilha1_Construtor()
{
    Topo1 = NULL;  //Inicializando o ponteiro como nulo para evitar que ele aponte para lixo de memoria
    Contador1 = 0;  //Inicia a vari�vel para indicar a quantidade de elementos armazenados na Pilha
}

//Metodo para liberar o espa�o alocado para a pilha
void Pilha1_Destrutor()
{
    TipoCelula1 *Temp1;  //Ponteiro tempor�rio utilizado para desalocar a mem�ria

    while(Topo1 != NULL)  //Enquanto Topo n�o chegar em Nulo (Enquanto a Pilha n�o estiver vazia)
    {
        Temp1 = Topo1;  //o ponteiro tempor�rio deve apontar para o mesmo endere�o que Topo
        Topo1 = Topo1 -> Prox1; //Topo avan�a para a c�lula seguinte

        Temp1->Prox1 = NULL; //Para quebrar o v�nculo que existia entre as c�lulas da Pilha (seguran�a)
        free(Temp1);  //desaloca o espa�o de mem�ria (c�lula) apontado por Temp
    }

    Contador1 = 0;
}

//Fun��o para indicar se a Pilha est� ou n�o vazia
bool Pilha1_Vazia()
{
    return Topo1 == NULL;   /*Se o resultado for verdadeiro, significa que a pilha est� vazia se retornar
                           falso, Significa que ainda existem itens na pilha*/
}

//Fun��o para retornar a quantidade de elementos armazenados na Pilha
int Pilha1_Tamanho()
{
    return Contador1; //� retornado o contador de elementos, manipulado nos m�todos de Empilhar e Desempilhar
}

//Fun��o para adicionar elementos do topo da Pilha
bool Pilha1_Empilhar(TipoDado1 Elemento1)
{
    TipoCelula1 *Nova1;  //Ponteiro tempor�rio utilizado para apontar para a nova c�lula a ser criada

    if((Nova1 = (TipoCelula1 *) malloc(sizeof(TipoCelula1)))==NULL)  //tenta alocar din�micamente na mem�ria umam nova c�lula da Pilha
    {
        //e Nova deve apontar para esse endere�o de mem�ria

        //caso n�o for poss�vel alocar mais uma c�lula na mem�ria (Nova aponta para NULL e torna a condi��o do if verdadeira)
        //Retona falso, indicando que nenhum elemento foi empilhado (n�o foi poss�vel alocar mais mem�ria)
        return false;
    }
    else
    {
        Nova1->Item1 = Elemento1;  //Como Nova aponta para um espa�o de mem�ria dispon�vel, guardamos o Elemento a ser armazenado nesse espa�o
        Nova1->Prox1 = Topo1;      //Para fazer a liga��o entre as c�lulas da Pilha, o novo espa�o de mem�ria reservado
        //e apontado por Nova possui um ponteiro Prox que deve apontar para c�lua seguinte
        //Nesse caso, o ponteiro Prox deve apontar para o mesmo endere�o que Topo aponta
        //Resumindo: O Prox do Nova aponta agora para Topo

        Topo1 = Nova1;            //Como a Pilha possui agora um novo topo apontado por Nova e o ponteiro Topo est� um n�vel abaixo
        //deve-se fazer com que Topo aponte para a nova c�lula criada

        Contador1++;             //Como foi armazenado um novo Elemento, o contador deve ser incrementado

        return true;            //Retorna verdadeiro, indicando que o elemento foi empilhado (inserido na Pilha)
    }
}

//Fun��o para retirar itens do topo da pilha
bool Pilha1_Desempilhar(TipoDado1 &Elemento1)
{

    if(!Pilha1_Vazia())  //primeiro deve-se conferir se a Pilha n�o est� vazia
    {

        TipoCelula1 *Temp1 = Topo1;  //Cria um ponteiro tempor�rio (Temp) e faz apontar para o mesmo endere�o de Topo
        //Essa c�lula ser� exclu�da da Pilha

        Topo1 = Topo1->Prox1; //Faz o topo apontar para a c�lula seguinte
        //Esse procedimento define a c�lula eleita como topo da Pilha

        Elemento1 = Temp1->Item1;  //O Elemento a ser retornado est� na c�lula que ser� exclu�da
        //Esse elemento � o �ltimo que foi empilhado (inserido na Pilha)

        Temp1->Prox1 = NULL;  //Remove a liga��o entre a c�lula a ser exclu�da e a c�lula de topo da Pilha (seguran�a)

        free(Temp1);         //Desaloca o espa�o de mem�ria reservado pela c�lula apontada por Temp
        //(devolve esse espa�o de mem�ria ao sistema)

        Contador1--;          //Como foi removido um Elemento, o contador deve ser decrementado

        return true;        //Retona verdadeiro, indicando que o elemento foi removido
    }
    else  //caso a Pilha esteja vazia
        return false;      //Retona falso, indicando que nenhum elemento foi removido (N�o h� Elemento para ser removido, a Pilha est� vazia)
}


//Fun��o que retorna o valor do topo da pilha sem removelo
bool Pilha1_Topo(TipoDado1 &Elemento1)
{

    if(!Pilha1_Vazia())  //primeiro deve-se conferir se a Pilha n�o est� vazia
    {
        Elemento1 = Topo1->Item1;  //Topo aponta uma c�lula com o �ltimo elemento empilhado

        return true;  //retorna verdadeiro indicando que o �ltimo elemento da Pilha foi retornado (mas n�o desempilhado)
    }
    else //caso a Pilha esteja vazia
        return false;  //retorna falso, indicando que n�o foi poss�vel retornar o elemento
}

//Pilha2

TipoCelula2 *Topo2; //Vari�vel para controlar  a pilha, quue aponta para o item do topo

int Contador2;  //Vari�vel para contar o n�mero de elementos armazenados na Pilha

//Fun��o para construir a pilha
void Pilha2_Construtor()
{
    Topo2 = NULL;  //Inicializando o ponteiro como nulo para evitar que ele aponte para lixo de memoria
    Contador2 = 0;  //Inicia a vari�vel para indicar a quantidade de elementos armazenados na Pilha
}

//Metodo para liberar o espa�o alocado para a pilha
void Pilha2_Destrutor()
{
    TipoCelula2 *Temp2;  //Ponteiro tempor�rio utilizado para desalocar a mem�ria

    while(Topo2 != NULL)  //Enquanto Topo n�o chegar em Nulo (Enquanto a Pilha n�o estiver vazia)
    {
        Temp2 = Topo2;  //o ponteiro tempor�rio deve apontar para o mesmo endere�o que Topo
        Topo2 = Topo2 -> Prox2; //Topo avan�a para a c�lula seguinte

        Temp2->Prox2 = NULL; //Para quebrar o v�nculo que existia entre as c�lulas da Pilha (seguran�a)
        free(Temp2);  //desaloca o espa�o de mem�ria (c�lula) apontado por Temp
    }

    Contador2 = 0;
}

//Fun��o para indicar se a Pilha est� ou n�o vazia
bool Pilha2_Vazia()
{
    return Topo2 == NULL;   /*Se o resultado for verdadeiro, significa que a pilha est� vazia se retornar
                           falso, Significa que ainda existem itens na pilha*/
}

//Fun��o para retornar a quantidade de elementos armazenados na Pilha
int Pilha2_Tamanho()
{
    return Contador2; //� retornado o contador de elementos, manipulado nos m�todos de Empilhar e Desempilhar
}

//Fun��o para adicionar elementos do topo da Pilha
bool Pilha2_Empilhar(TipoDado2 Elemento2)
{
    TipoCelula2 *Nova2;  //Ponteiro tempor�rio utilizado para apontar para a nova c�lula a ser criada

    if((Nova2 = (TipoCelula2 *) malloc(sizeof(TipoCelula2)))==NULL)  //tenta alocar din�micamente na mem�ria umam nova c�lula da Pilha
    {
        //e Nova deve apontar para esse endere�o de mem�ria

        //caso n�o for poss�vel alocar mais uma c�lula na mem�ria (Nova aponta para NULL e torna a condi��o do if verdadeira)
        //Retona falso, indicando que nenhum elemento foi empilhado (n�o foi poss�vel alocar mais mem�ria)
        return false;
    }
    else
    {
        Nova2->Item2 = Elemento2;  //Como Nova aponta para um espa�o de mem�ria dispon�vel, guardamos o Elemento a ser armazenado nesse espa�o
        Nova2->Prox2 = Topo2;      //Para fazer a liga��o entre as c�lulas da Pilha, o novo espa�o de mem�ria reservado
        //e apontado por Nova possui um ponteiro Prox que deve apontar para c�lua seguinte
        //Nesse caso, o ponteiro Prox deve apontar para o mesmo endere�o que Topo aponta
        //Resumindo: O Prox do Nova aponta agora para Topo

        Topo2 = Nova2;            //Como a Pilha possui agora um novo topo apontado por Nova e o ponteiro Topo est� um n�vel abaixo
        //deve-se fazer com que Topo aponte para a nova c�lula criada

        Contador2++;             //Como foi armazenado um novo Elemento, o contador deve ser incrementado

        return true;            //Retorna verdadeiro, indicando que o elemento foi empilhado (inserido na Pilha)
    }
}

//Fun��o para retirar itens do topo da pilha
bool Pilha2_Desempilhar(TipoDado2 &Elemento2)
{

    if(!Pilha2_Vazia())  //primeiro deve-se conferir se a Pilha n�o est� vazia
    {

        TipoCelula2 *Temp2 = Topo2;  //Cria um ponteiro tempor�rio (Temp) e faz apontar para o mesmo endere�o de Topo
        //Essa c�lula ser� exclu�da da Pilha

        Topo2 = Topo2->Prox2; //Faz o topo apontar para a c�lula seguinte
        //Esse procedimento define a c�lula eleita como topo da Pilha

        Elemento2 = Temp2->Item2;  //O Elemento a ser retornado est� na c�lula que ser� exclu�da
        //Esse elemento � o �ltimo que foi empilhado (inserido na Pilha)

        Temp2->Prox2 = NULL;  //Remove a liga��o entre a c�lula a ser exclu�da e a c�lula de topo da Pilha (seguran�a)

        free(Temp2);         //Desaloca o espa�o de mem�ria reservado pela c�lula apontada por Temp
        //(devolve esse espa�o de mem�ria ao sistema)

        Contador2--;          //Como foi removido um Elemento, o contador deve ser decrementado

        return true;        //Retona verdadeiro, indicando que o elemento foi removido
    }
    else  //caso a Pilha esteja vazia
        return false;      //Retona falso, indicando que nenhum elemento foi removido (N�o h� Elemento para ser removido, a Pilha est� vazia)
}


//Fun��o que retorna o valor do topo da pilha sem removelo
bool Pilha2_Topo(TipoDado2 &Elemento2)
{

    if(!Pilha2_Vazia())  //primeiro deve-se conferir se a Pilha n�o est� vazia
    {
        Elemento2 = Topo2->Item2;  //Topo aponta uma c�lula com o �ltimo elemento empilhado

        return true;  //retorna verdadeiro indicando que o �ltimo elemento da Pilha foi retornado (mas n�o desempilhado)
    }
    else //caso a Pilha esteja vazia
        return false;  //retorna falso, indicando que n�o foi poss�vel retornar o elemento
}

//Pilha3

TipoCelula3 *Topo3; //Vari�vel para controlar  a pilha, quue aponta para o item do topo

int Contador3;  //Vari�vel para contar o n�mero de elementos armazenados na Pilha

//Fun��o para construir a pilha
void Pilha3_Construtor()
{
    Topo3 = NULL;  //Inicializando o ponteiro como nulo para evitar que ele aponte para lixo de memoria
    Contador3 = 0;  //Inicia a vari�vel para indicar a quantidade de elementos armazenados na Pilha
}

//Metodo para liberar o espa�o alocado para a pilha
void Pilha3_Destrutor()
{
    TipoCelula3 *Temp3;  //Ponteiro tempor�rio utilizado para desalocar a mem�ria

    while(Topo3 != NULL)  //Enquanto Topo n�o chegar em Nulo (Enquanto a Pilha n�o estiver vazia)
    {
        Temp3 = Topo3;  //o ponteiro tempor�rio deve apontar para o mesmo endere�o que Topo
        Topo3 = Topo3 -> Prox3; //Topo avan�a para a c�lula seguinte

        Temp3->Prox3 = NULL; //Para quebrar o v�nculo que existia entre as c�lulas da Pilha (seguran�a)
        free(Temp3);  //desaloca o espa�o de mem�ria (c�lula) apontado por Temp
    }

    Contador3 = 0;
}

//Fun��o para indicar se a Pilha est� ou n�o vazia
bool Pilha3_Vazia()
{
    return Topo3 == NULL;   /*Se o resultado for verdadeiro, significa que a pilha est� vazia se retornar
                           falso, Significa que ainda existem itens na pilha*/
}

//Fun��o para retornar a quantidade de elementos armazenados na Pilha
int Pilha3_Tamanho()
{
    return Contador3; //� retornado o contador de elementos, manipulado nos m�todos de Empilhar e Desempilhar
}

//Fun��o para adicionar elementos do topo da Pilha
bool Pilha3_Empilhar(TipoDado3 Elemento3)
{
    TipoCelula3 *Nova3;  //Ponteiro tempor�rio utilizado para apontar para a nova c�lula a ser criada

    if((Nova3 = (TipoCelula3 *) malloc(sizeof(TipoCelula3)))==NULL)  //tenta alocar din�micamente na mem�ria umam nova c�lula da Pilha
    {
        //e Nova deve apontar para esse endere�o de mem�ria

        //caso n�o for poss�vel alocar mais uma c�lula na mem�ria (Nova aponta para NULL e torna a condi��o do if verdadeira)
        //Retona falso, indicando que nenhum elemento foi empilhado (n�o foi poss�vel alocar mais mem�ria)
        return false;
    }
    else
    {
        Nova3->Item3 = Elemento3;  //Como Nova aponta para um espa�o de mem�ria dispon�vel, guardamos o Elemento a ser armazenado nesse espa�o
        Nova3->Prox3 = Topo3;      //Para fazer a liga��o entre as c�lulas da Pilha, o novo espa�o de mem�ria reservado
        //e apontado por Nova possui um ponteiro Prox que deve apontar para c�lua seguinte
        //Nesse caso, o ponteiro Prox deve apontar para o mesmo endere�o que Topo aponta
        //Resumindo: O Prox do Nova aponta agora para Topo

        Topo3 = Nova3;            //Como a Pilha possui agora um novo topo apontado por Nova e o ponteiro Topo est� um n�vel abaixo
        //deve-se fazer com que Topo aponte para a nova c�lula criada

        Contador3++;             //Como foi armazenado um novo Elemento, o contador deve ser incrementado

        return true;            //Retorna verdadeiro, indicando que o elemento foi empilhado (inserido na Pilha)
    }
}

//Fun��o para retirar itens do topo da pilha
bool Pilha3_Desempilhar(TipoDado3 &Elemento3)
{

    if(!Pilha3_Vazia())  //primeiro deve-se conferir se a Pilha n�o est� vazia
    {

        TipoCelula3 *Temp3 = Topo3;  //Cria um ponteiro tempor�rio (Temp) e faz apontar para o mesmo endere�o de Topo
        //Essa c�lula ser� exclu�da da Pilha

        Topo3 = Topo3->Prox3; //Faz o topo apontar para a c�lula seguinte
        //Esse procedimento define a c�lula eleita como topo da Pilha

        Elemento3 = Temp3->Item3;  //O Elemento a ser retornado est� na c�lula que ser� exclu�da
        //Esse elemento � o �ltimo que foi empilhado (inserido na Pilha)

        Temp3->Prox3 = NULL;  //Remove a liga��o entre a c�lula a ser exclu�da e a c�lula de topo da Pilha (seguran�a)

        free(Temp3);         //Desaloca o espa�o de mem�ria reservado pela c�lula apontada por Temp
        //(devolve esse espa�o de mem�ria ao sistema)

        Contador3--;          //Como foi removido um Elemento, o contador deve ser decrementado

        return true;        //Retona verdadeiro, indicando que o elemento foi removido
    }
    else  //caso a Pilha esteja vazia
        return false;      //Retona falso, indicando que nenhum elemento foi removido (N�o h� Elemento para ser removido, a Pilha est� vazia)
}


//Fun��o que retorna o valor do topo da pilha sem removelo
bool Pilha3_Topo(TipoDado3 &Elemento3)
{

    if(!Pilha3_Vazia())  //primeiro deve-se conferir se a Pilha n�o est� vazia
    {
        Elemento3 = Topo3->Item3;  //Topo aponta uma c�lula com o �ltimo elemento empilhado

        return true;  //retorna verdadeiro indicando que o �ltimo elemento da Pilha foi retornado (mas n�o desempilhado)
    }
    else //caso a Pilha esteja vazia
        return false;  //retorna falso, indicando que n�o foi poss�vel retornar o elemento
}
