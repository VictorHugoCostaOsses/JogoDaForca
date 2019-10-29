#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "forca.c"
#include "forca.h"
#include <locale.h>

void copyright(){
    system("clear");
    printf("=============================================================\n\n");
    printf("JOGO DA FORCA\n");
    printf("Desenvolvido por: \n\tVictor Hugo Costa Osses 18152\n");
    printf("\tGustavo Massayoshi Ferreira Tawara 18134\n");
    printf("=============================================================\n\n");
}

int limpaTela()
{
puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
return 0;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    NoSecreto * lstSecreta = inicializaListaSecreta();
    NoSecreto * lstRetira = inicializaListaSecreta();
    NoSecreto * noLetra  = inicializaListaSecreta();

    char fNameArq[255];
    NoSecreto * sorteada;
    int posSorteada=0;
    int tamanhoLista=0;
    char letra;
    int n=0;
    int x =0;
    int z =1;
    int k=0;

    strcpy(fNameArq,"palavras.dat");

    if(argc>1){
      strcpy(fNameArq,argv[1]);
    }

    printf("Arquivo de dados: %s\n\n",fNameArq);

    copyright();
    system("pause");
    lstSecreta = carregaListaArquivo(lstSecreta,fNameArq);

    tamanhoLista = tamanhoListaSecreta(lstSecreta);

    do{
        CLEAR_SCREEN;
        imprimeListaSecreta(lstSecreta);
        sorteada = sorteiaPalavra(lstSecreta,lstRetira);
        if(sorteada!=NULL)
            {
            printf("%s", sorteada->palavra);
            lstSecreta = retiraLista(lstSecreta,lstRetira,sorteada->palavra);

            x = tamanhoListaSecreta(sorteada);
            printf("\n");

          /* do{
                letra = getch();
                n = jogoDaForca(sorteada,letra,x,k);

               if(n==6)
                {
                    k=0;
                    z=0;
                    printf("Parabéns! Você acertou a palavra");
                    break;
                }


                 else if(z==x+3)
                 {
                 z=0;
                 n=0;
                 printf("Parabéns! Você errou a palavra");
                 break;
                 }
                 z++;

              }while(letra!='0');*/
            }
           else
        {
            printf("Não tem palavra disponível!\n\n");
        }

    }while(getchar()!='f');




    return 0;
}




