/*
____________________________________________________________________________________________________
Nome: Marcos Paulo Vimieiro Silva
OBJ:O programa tem como objetivo, alimentar duas pilhas com numeros digitados pelo usuário,
somalos e com o valor da soma gerar uma terceira pilha, com o total da soma efetuada.
O programa gera o resultado da soma das duas pilhas, para que o sistema possa imprimir na tela
do usuário o valor da soma.

A entrada de dados deve ser feita pelo usuário, inserindo os tamanhos dos números e posteriormente
os valores a serem somados.

O resultado no final é a soma dos dois valores.
____________________________________________________________________________________________________
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

using namespace std;

//Função para alimentar o vetor de char
void Alimenta(char *vNum, int Indice)
{
    cout<<endl<<"Digite o " <<Indice<<" Numero: ";
    fflush(stdin);
    gets(vNum);
}

//Função para alimentar a pilha 1
void Alimenta_Pilha1(int vTamanho1, char *vNum1)
{
//For para empilhar os itens da pilha 1
    for(int vI=0; vI<vTamanho1; vI++)
    {
        if(!Pilha1_Empilhar(vNum1[vI]))
            cout<<endl<<"Erro ao empilhar!!";
        else
            cout<<endl<<"Item empilhado com sucesso!!";
    }
}

//Função para alimentar a pilha 2
void Alimenta_Pilha2(int vTamanho2, char *vNum2)
{
//For para empilhar os itens da pilha 2
    for(int vI=0; vI<vTamanho2; vI++)
    {
        if(!Pilha2_Empilhar(vNum2[vI]))
            cout<<endl<<"Erro ao empilhar!!";
        else
            cout<<endl<<"Item empilhado com sucesso!!";
    }
}

//Função para retornar o valor do maior numero
void PegaTamanhoMaior(int vTamanho1, int vTamanho2, int &vTamanho3)
{
    if(vTamanho1<vTamanho2)
    {
        vTamanho3=vTamanho2;
    }
    else if(vTamanho2<vTamanho1)
    {
        vTamanho3=vTamanho1;
    }
    else
        vTamanho3=vTamanho1;
}

//Função para retirar os itens da pilha 1 para somar
void Desempilha_P1(int vTamanho3, int *vetConvert1, char vNum)
{
//For para desempilhar os itens da pilha 1
    for(int vI=0; vI<vTamanho3; vI++)
    {
        if(!Pilha1_Desempilhar(vNum))
        {
            cout<<endl<<"Erro ao Desempilhar!!";
            vetConvert1[vI]=0;
        }
        else
        {
            cout<<endl<<"Item Desempilhado com sucesso!!";
            vetConvert1[vI]=vNum-48;
        }
    }
}

//Função para retirar os itens da pilha 2 para somar
void Desempilha_P2(int vTamanho3, int *vetConvert2, char vNum)
{
//For para desempilhar os itens da pilha 2
    for(int vI=0; vI<vTamanho3; vI++)
    {
        if(!Pilha2_Desempilhar(vNum))
        {
            cout<<endl<<"Erro ao Desempilhar!!";
            vetConvert2[vI]=0;
        }
        else
        {
            cout<<endl<<"Item Desempilhado com sucesso!!";
            vetConvert2[vI]=vNum-48;
        }
    }
}

//Função para alimentar a pilha 3 com a soma dos dois vetores
void Alimenta_Pilha3(int &vTamanho3, int *vetConvert1, int *vetConvert2, int vResto,char vNum, int vNumIn)
{
//for para a soma e para empilhar os valores da 3° pilha
    for(int vI=0; vI<vTamanho3; vI++)
    {
        vetConvert1[vI]+=vResto;
        vResto=0;
        if(vetConvert1[vI]+ vetConvert2[vI]>=10)
        {
            vNumIn=(vetConvert1[vI]+ vetConvert2[vI]);
            vNumIn-=10;
            vResto=1;
            vNum=vNumIn+48;

        }
        else
        {
            vNumIn=(vetConvert1[vI]+ vetConvert2[vI]);
            vNum=vNumIn+48;
        }
        if(!Pilha3_Empilhar(vNum))
            cout<<endl<<"Erro ao empilhar!!";
        else
            cout<<endl<<"Item empilhado com sucesso!!";
    }
//Checagem para ter certeza de que mesmo que a função tenha acabado não há um vai um não armazenado
//que seria o estouro do vetor
    if(vResto==1)
    {
        vNum=vResto+48;
        if(!Pilha3_Empilhar(vNum))
            cout<<endl<<"Erro ao empilhar!!";
        else
        {
            cout<<endl<<"Item empilhado com sucesso!!";
            vTamanho3+=1;
        }
    }
}

//Função para imprimir o numero gerado pelo soma dos dois primeiros
void ImprimeSoma(char vNum, int vTamanho3)
{
    cout<<endl<<endl<<endl;
    cout<<"A soma dos numeros e: ";
//For para desempilhar os itens da pilha 3 e imprimir
    for(int vI=0; vI<vTamanho3; vI++)
    {
        Pilha3_Desempilhar(vNum);
        cout<<vNum;
    }
}

int main()
{
    int vTamanho1;//Tamanho do primeiro numero
    int vTamanho2; //Tamanho do segundo numero
    int vTamanho3; //Tamanho maior para criar os vetores de soma do mesmo tamanho
    int *vetConvert1; //Vetor da conversão de char para inteiro
    int *vetConvert2; //Vetor da conversão de char para inteiro
    int *vetConvert3; //Ponteiro para criar um vetor da soma da conversão 1 e da conversão 2
    int vResto=0; //vai 1 da soma para evitar que a pilha possua um valor >9
    int vNumIn; //O valor inteiro para a conversão para char

    cout<<"Digite o tamnaho do 1 numero: ";
    cin>>vTamanho1;
    cout<<"Digite o tamnaho do 2 numero: ";
    cin>>vTamanho2;

    char *vNum1; //Ponteiro para criar um vetor e armazenar os numeros digitados pelo usuario
    char  *vNum2;//Ponteiro para criar um vetor e armazenar os numeros digitados pelo usuario
    char   vNum; //variavel para converter o valor do vetor inteiro e empilhar

    //Criação dos vetores de char para pegar os dois valores

    if((vNum1 = (char *) malloc(sizeof(char)*vTamanho1))==NULL)
    {
        cout<<endl<<"Erro ao alocar a memoria";
    }
    else
    {
        cout<<endl<<"Alocacao de memoria bem sucedida!!";
    }

    if((vNum2 = (char *) malloc(sizeof(char)*vTamanho2))==NULL)
    {
        cout<<endl<<"Erro ao alocar a memoria";
    }
    else
    {
        cout<<endl<<"Alocacao de memoria bem sucedida!!";
    }

//Funções para alimentar os dois numeros
    Alimenta(vNum1, 1);
    Alimenta(vNum2, 2);

//Construção das 3 pilhas
    Pilha1_Construtor();
    Pilha2_Construtor();
    Pilha3_Construtor();

//Funções para alimentar as duas pilhas com o numero
    Alimenta_Pilha1(vTamanho1, vNum1);
    Alimenta_Pilha2(vTamanho2, vNum2);
//Função para liberar o espaço de memoria utilizado pelos dois numeros da pilha
    free(vNum1);
    free(vNum2);

// para pegar o tamanho maior para criar os dois vetores de soma e a comparação do for
//de alimentação da 3° pilha
    PegaTamanhoMaior(vTamanho1, vTamanho2, vTamanho3);

//Criando os vetores para a soma
    if((vetConvert1= (int *) malloc(sizeof(int)*vTamanho3))==NULL)
    {
        cout<<endl<<"Erro ao alocar a memoria";
    }
    else
    {
        cout<<endl<<"Alocacao de memoria bem sucedida!!";
    };

    if((vetConvert2= (int *) malloc(sizeof(int)*vTamanho3))==NULL)
    {
        cout<<endl<<"Erro ao alocar a memoria";
    }
    else
    {
        cout<<endl<<"Alocacao de memoria bem sucedida!!";
    }

//Funções para desempilhar os itens da pilha 1 e 2 e armazenalos em um vetor de inteiros
    Desempilha_P1(vTamanho3,vetConvert1,vNum);
    Desempilha_P2(vTamanho3,vetConvert2,vNum);

//Função para alimentar a pilha 3
    Alimenta_Pilha3(vTamanho3,vetConvert1, vetConvert2,vResto,vNum,vNumIn);

//Função para libar o espaço de memoria usados pelos vetores de conversão
    free(vetConvert1);
    free(vetConvert2);

//Função para imrpimir a soma dos numeros
    ImprimeSoma(vNum,vTamanho3);
//Função para destruir as pilhas
    Pilha1_Destrutor();
    Pilha2_Destrutor();
    Pilha3_Destrutor();

    cout<<endl<<endl<<endl;

    return 0;
}
