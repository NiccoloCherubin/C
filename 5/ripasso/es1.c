#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGHT 10 // lunghezza array


// funzione che riempie l'array con numeri casuali
void fillArray(int *vett) {

  srand(time(NULL));
  for (int i = 0; i < LENGHT; i++) {
    vett[i] = rand() % 101; // da 0 a 100
  }
}
void printArray(int *vett) {
  for (int i = 0; i < LENGHT; i++) {
    printf("%d ", vett[i]);
  }
}
int *swapArray(int *originale, int *copia) {  
  for (int i = LENGHT; i >= 0; i--) {
    copia[LENGHT-i-1] = originale[i];
  }
  return copia;
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

int main(int argc, char *argv[]) {

  // popolo l'array
  int vett[LENGHT]; // creazione del vettore

  int temp[LENGHT]; // creazione array temporaneo per lo swap

  int scelta;
  int swap = 0; // per capire se lo swap è stato fatto o meno
  int *arrayInvertito; // puntatore ad intero per l'array invertito

  fillArray(vett);

  do {
    scelta = menu(0);
    switch (scelta) {
    case 1:
      // stampa contenuto array
      printf("Contenuto array: \n");
      printArray(vett);
      break;
    case 2:
      // array invertito
      arrayInvertito = swapArray(vett,temp);
      printArray(arrayInvertito);
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
    printf("\n===================\n");
  } while (scelta > 0);

  printf("Programma finito");
}