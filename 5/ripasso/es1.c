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

void printArray(int *vett) {
  for (int i = 0; i < LENGHT; i++) {
    printf("%d ", vett[i]);
  }
}
void swapArray(int *originale) {  
  for (int i = LENGHT; i >= 0; i--) {
    printf("%d ",originale[LENGHT-i-1]);
  }
}

int somma(int *vett)
{
  int somma = 0;
  for (int i = 0; i < LENGHT; i++) {
    somma += vett[i];
    }
    return somma;
}

void evenOrOdd(int* vett,short choice)
{
  for (int i = 0; i < LENGHT; i++) {
    if(vett[i]%2 == choice)
    {
      printf("%d ", vett[i]);
    }
  }
}

int main(int argc, char *argv[]) {

  // popolo l'array
  int vett[LENGHT]; // creazione del vettore

  int scelta;
  int swap = 0; // per capire se lo swap è stato fatto o meno
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
      swapArray(vett);
      break;
    case 3:
      //somma e media
      printf("Somma: %d, media:%2.f \n",somma(vett), (float)somma(vett)/LENGHT);
      break;
    case 4:
      //visualizza numeri pari
      evenOrOdd(vett, 0);
      break;
    case 5:
      //visualizza numeri dispari
      evenOrOdd(vett, 1);
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

  printf("Programma finito \n");
}