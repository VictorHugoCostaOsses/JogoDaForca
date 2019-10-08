#include <stdio.h>
#include "forca.h"
#include <stdlib.h>
#include <string.h>

struct noSecreto{
int status;
char palavra[31];
char assunto[100];
struct NoSecreto * prox;
};


void copyright()
{
    system("cls");
    printf("JOGO DA FORCA\n\n");
    printf("Desenvolvido por:\n\nVictor Hugo Costa Osses 18152\n\n\t\t&&\n\nGustavo Massayoshi Ferreira Tawara 18134\n\n\n\n");
    return 0;
}

NoSecreto * inicializaListaSecreta(){
    return NULL;
}

NoSecreto * inserePalavraSecreta(NoSecreto * l,char word[31],char subject[100])
{

 NoSecreto * novo;

 novo = (NoSecreto*) malloc(sizeof(NoSecreto));
 novo->status = 0;
 strcpy(novo->assunto,subject);/*string copy - copiar e colocar no parametro*/
 strcpy(novo->palavra,word);
 novo->prox=l;
 l=novo;
 return l;
}

void imprimeListaSecreta(NoSecreto *l)
{
    for(NoSecreto *p=l; p!=NULL; p=p->prox)
    {
        printf("%0d | %30s |%30s\n",p->status,p->palavra,p->assunto);
    }
}

NoSecreto * carregaListaArquivo(NoSecreto * l,char nomeArq[255])
{
    FILE * fWords;
    int status;
    char palavra[31];
    char assunto[100];

    fWords = fopen(nomeArq,"r");
    if(fWords==NULL){
        printf("Falha ao acessar base de dados!!!\n\n");
        exit(0);
    }
    while(!feof(fWords))
    {
      //fscanf(fWords,"%d;",&status);
      if(fscanf(fWords,"%s%s",palavra,assunto))
      {
      l = inserePalavraSecreta(l,palavra,assunto);
      }

    }
    fclose(fWords);


    return  l;
}

