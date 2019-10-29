#ifndef FORCA_H_INCLUDED
#define FORCA_H_INCLUDED

/* definição de uma Macro para limpeza do console */
#ifdef _WIN32
# define CLEAR_SCREEN system ("cls")
#else
# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
#endif

struct noSecreto{
    int status;
    char palavra[31];
    char assunto[101];
    struct noSecreto * prox;
    struct noSecreto * ant;

};

struct noLetra
{
    char letra[31];
    struct noLetra * prox;
    struct noLetra * ant;
};

typedef struct noSecreto NoSecreto;
typedef struct noSorteada NoSorteada;
typedef struct noLetra noLetra;

int geraAleatorio(int maximo);
NoSecreto * inicializaListaSecreta();
NoSecreto * carregaListaArquivo(NoSecreto *l, char nomeArq[255]);
void imprimeListaSecreta(NoSecreto *l);
NoSecreto * inserePalavraSecreta(NoSecreto *l,char word[31],char subject[100]);
NoSecreto * sorteiaPalavra(NoSecreto *l,NoSecreto * lstRetira);
int temPalavraNaoUsada(NoSecreto *l);

//retorna no tamanho da lista, para saber o intervalo de valores para gerar uma posicao
//aleatoria, para sortear uma palavra secreta
int tamanhoListaSecreta(NoSecreto *l);

//retorna a palavra que esteja em uma dada posição na lista de palavras secretas
NoSecreto * retornaPalavraPos(NoSecreto *l, int pos);
NoSecreto * retiraLista(NoSecreto *l, NoSecreto *p,char palavra[31]);
//int jogoDaForca(NoSecreto *p,char letra,int tamanho,int n);
#endif // FORCA_H_INCLUDED
