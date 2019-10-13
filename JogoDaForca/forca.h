#ifndef FORCA_H_INCLUDED
#define FORCA_H_INCLUDED

typedef struct noSecreto NoSecreto;
typedef struct palavraAleatoria PalavraAleatoria;


NoSecreto * inicializaListaSecreta();
PalavraAleatoria * inicializaListaPalavraAleatoria();

void copyright();
void carregaListaArquivo(NoSecreto **l,char nomeArq[255]);
void imprimeListaSecreta(NoSecreto *l);
void inserePalavraSecreta(NoSecreto ** l,
                                 char word[31],
                                 char subject[100]
                                       );

void gerarPalavraAleatoria(NoSecreto * l,PalavraAleatoria * p, int ID );
char inserirLetrasPalavra(char recebe[1],PalavraAleatoria * p,int n);


#endif // FORCA_H_INCLUDED
