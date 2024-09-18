#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGHT 50 // lunghezza array

int vett[LENGHT]; // creazione del vettore

// funzione che riempie l'array con numeri casuali

void FillArray() {

  srand(time(NULL));
  for (int i = 0; i < LENGHT; i++) 
  {
    vett[i] =  rand() % 101; // da 0 a 100
  }
}

// funzione che stampa il menù e ritorna la scelta effettuata dall'utente

int menu(int scelta) {
  printf("\n[1] Visualizza elementi array \n");
  printf("[2] Visualizza elementi invertiti array \n");
  printf("[3] Visualizza somma e media elementi array \n");
  printf("[4] Visualizza elementi pari array \n");
  printf("[5] Visualizza elementi dispari array \n");
  printf("[6] Visualizza elemento ricercato array \n");
  printf("[7] Elimina un elementlo dell'array \n");
  printf("[8] Alterna posizioni array \n");
  printf("[9] Ordina vettore \n");

  printf("inserire opzione desiderata (scegliere -1 per uscire):");
  scanf("%d", &scelta);

  return scelta;
}

void PrintArray()
{
    for(int i = 0; i < LENGHT; i++)
    {
        printf("Elemento %d: %d",i,vett[i]);
    }
}

int main(int argc, char *argv[]) {

  FillArray();

  int scelta;
  do {
    scelta = menu(0);
    printf("\n  scelta: %d", scelta);
    switch (scelta) {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      break;
    }

  } while (scelta > 0);

  printf("Programma finito");
}