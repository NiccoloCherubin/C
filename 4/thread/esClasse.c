/*la consegna è la seguente: in linguaggio c creare 2 thread, il primo genera
una sequenza di N numeri casuali , con N fornito come argomento della riga di
comando, e li inserisce singolarmente in un ring-buffer , il secondo preleva i
numeri dal ring-buffer condiviso e li visualizza. la codifica dovrà prevedere la
necessaria sincronizzazione fra thread consumatore e thread produttore.*/

#include <pthread.h>
#include <stdio.h>

typedef struct
{
    int numero;
} buffer;

void * generatore(void*arg)
{
    pthread_exit(NULL);
}

void *visualizzatore(void*arg)
{
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("numero argomenti errati");
  }


  return 0;
}