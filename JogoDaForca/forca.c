#include <stdio.h>
#include "forca.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int n=0;
int ID=0;
int z=0;

struct noSecreto
{
    int ID;
    int status;
    char palavra[31];
    char assunto[100];
    NoSecreto * prox;
};

struct palavraAleatoria
{
    int status;
    int ID;
    char pAleatoria[1];
    char assunto[100];
    PalavraAleatoria * prox;
};

void copyright()
{
    system("cls");
    printf("JOGO DA FORCA\n\n");
    printf("Desenvolvido por:\n\nVictor Hugo Costa Osses 18152\n\n\t\t&&\n\nGustavo Massayoshi Ferreira Tawara 18134\n\n\n\n");
}

NoSecreto * inicializaListaSecreta(){
    return NULL;
}

PalavraAleatoria * inicializaListaPalavraAleatoria(){
    return NULL;
}

void inserePalavraSecreta(NoSecreto ** l,char word[31],char subject[100])
{

     NoSecreto * novo;
     novo = (NoSecreto*) malloc(sizeof(NoSecreto));
     novo->status = 0;
     strcpy(novo->assunto,subject);
     strcpy(novo->palavra,word);

     if(*l==NULL)
     {
         novo->prox = novo;
     }

     else
     {
        novo->prox=(*l)->prox;
        (*l)->prox = novo;

     }

     *l = novo;
}

void imprimeListaSecreta(NoSecreto *l)
{
    NoSecreto *p = l->prox;

    do
    {

    printf("%0d | %30s |%30s\n",p->status,p->palavra,p->assunto);
    p=p->prox;

    }while(p != l->prox);
}

void carregaListaArquivo(NoSecreto ** l,char nomeArq[255])
{
    FILE * fWords;
    char palavra[31];
    char assunto[100];
    fWords = fopen(nomeArq,"r");

    if(fWords==NULL)
    {
      printf("Falha ao acessar base de dados!!!\n\n");
      exit(0);
    }

    while(!feof(fWords))
    {
      if(fscanf(fWords,"%s%s",palavra,assunto))
      {
       inserePalavraSecreta(l,palavra,assunto);
       ID++;
      }
    }
    fclose(fWords);
}

void gerarPalavraAleatoria(NoSecreto * l,PalavraAleatoria * p,int ID )
{
        srand(time(NULL));
        char palavraAleatoria[50];
        /*char assunto[100];*/
        NoSecreto * aux = l;
        l->ID=ID;
        aux->ID=ID;

           for(int y=0; y<=rand() % 20; y++)
           {
            aux = aux->prox;
           }

           if(aux->status==1)
           {
            gerarPalavraAleatoria(l,p,ID);
           }
          /* int Id=l->ID;
           int Id2=aux->ID;

           do{
              if(Id==Id2)
           }while(Id!=Id2)
*/
        aux->status=1;

        printf("\n\n%s e %s\n\n",aux->palavra,aux->assunto);
        strcpy(palavraAleatoria,aux->palavra);

        inserirLetrasPalavra(palavraAleatoria,p,n);
}

char inserirLetrasPalavra(char recebe[50],PalavraAleatoria * p,int n)
{

    PalavraAleatoria * novo;
    novo = (PalavraAleatoria *) malloc(sizeof(PalavraAleatoria));
    novo->pAleatoria[0] = recebe[n];
    novo->status = 0;

    if(p==NULL)
    {
         novo->prox = novo;
    }

    else
    {
    novo->prox=p->prox;
    p->prox = novo;
    }

    p = novo;

    printf("%c\t",novo->pAleatoria[0]);
    printf("\n");

    z++;
    for(recebe=recebe; recebe[z]!='\0'; z=z)
    {
    n++;
    inserirLetrasPalavra(recebe,p,n);
    }

return recebe[50];
}


