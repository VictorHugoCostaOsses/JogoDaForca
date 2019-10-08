#include <stdio.h>
#include <stdlib.h>
#include "forca.h"

int main()
{

  copyright();
   NoSecreto * lstSecreta = inicializaListaSecreta();
   lstSecreta = carregaListaArquivo(lstSecreta,"D:\\2° ano\\JogoDaForca\\palavras.dat");
  /* lstSecreta =   inserePalavraSecreta(lstSecreta,"Tomate","Fruta");
  lstSecreta =   inserePalavraSecreta(lstSecreta,"Arroz","Alimento");
         lstSecreta =   inserePalavraSecreta(lstSecreta,"Mandioca","Raiz");*/
         imprimeListaSecreta(lstSecreta);


}
