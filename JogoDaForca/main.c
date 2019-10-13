#include <stdio.h>
#include <stdlib.h>
#include "forca.h"
#include<string.h>
#include<locale.h>
int main()
{
setlocale(LC_ALL,"");
copyright();
int ID = 0;
char nome[50];
int escolha;

printf("Informe seu nome de usuário:");
scanf("%s",nome);



NoSecreto * lstSecreta = inicializaListaSecreta();
PalavraAleatoria * noPalavraAleatoria = inicializaListaPalavraAleatoria();
 carregaListaArquivo(&lstSecreta,"F:\\2° ano\\JogoDaForca\\palavras.dat");

printf("1 -Digite 1 para começar o jogo:\n");
printf("2- Digite 0 para encerrar o jogo\n");
scanf("%d",&escolha);


     do
     {
         printf("\n");
        switch(escolha)
        {

            case 1:
                imprimeListaSecreta(lstSecreta);
                gerarPalavraAleatoria(lstSecreta,noPalavraAleatoria,ID);



            break;

            case 2:
            exit(-1);
            break;
        }
            printf("\n1 -Digite 1 para começar o jogo:\n");
            printf("\n2 - Digite 0 para encerrar o jogo\n");
            scanf("%d",&escolha);

     }while(escolha==1);

}
