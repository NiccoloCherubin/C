#include <endian.h>
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

// stampa a video gli array
void printArray(int *vett, int lunghezza) {
  for (int i = 0; i < lunghezza; i++) {
    printf("%d ", vett[i]);
  }
}

// inverte l'ordine degli elementi dell'array
void swapArray(int *originale, int lunghezza) {
  for (int i = lunghezza - 1; i >= 0; i--) {
    printf("%d ", originale[LENGHT - i - 1]);
  }
}

// calcola la somma di tutti gli elementi nell'array
int somma(int *vett, int lunghezza) {
  int somma = 0;
  for (int i = 0; i < lunghezza; i++) {
    somma += vett[i];
  }
  return somma;
}

// verifica se numero è pari o dispari e lo stampa a video
void evenOrOdd(int *vett, short choice, int lunghezza) {
  for (int i = 0; i < lunghezza; i++) {
    if (vett[i] % 2 == choice) {
      printf("%d ", vett[i]);
    }
  }
}

// ricerca elemento nell'array e ne torna la posizione
int ricerca(int *vett, int ricercato, int lunghezza) {
  for (int i = 0; i < lunghezza; i++) {
    if (vett[i] == ricercato) {
      return i;
    }
  }
  return -1;
}

// elima elemento dall'array
void elimina(int *vett, int posizione, int lunghezza) {
  int cont = 0; // contatore usiliario

  // elimino l'elemento
  for (int i = posizione; i < lunghezza - 1; i++) {
    vett[i] = vett[i + 1]; // Sposto gli elementi a sinistra
  }
}

// scambia gli elementi a coppie
void alternare(int *vett, int lunghezza) {
  for (int i = 0; i < lunghezza - 1; i += 2) {
    int temp = vett[i];
    vett[i] = vett[i + 1];
    vett[i + 1] = temp;
  }
}

// ordinamento vettore
void bubblesort(int *vett, int lunghezza) {
  for (int i = 0; i < lunghezza - 1; i++) {
    for (int j = 0; j < lunghezza - i - 1; j++) {
      if (vett[j] > vett[j + 1]) {
        // Scambia gli elementi
        int temp = vett[j];
        vett[j] = vett[j + 1];
        vett[j + 1] = temp;
      }
    }
  }
}

// Funzione per controllare se l'array è ordinato
int isSorted(int *vett, int lunghezza) {
    for (int i = 0; i < lunghezza - 1; i++) {
        if (vett[i] > vett[i + 1]) {
            return 0; // Non ordinato
        }
    }
    return 1; // Ordinato
}

// Funzione per mescolare l'array
void shuffle(int *vett, int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        int randomIndex = rand() % lunghezza;
        // Scambia gli elementi
        int temp = vett[i];
        vett[i] = vett[randomIndex];
        vett[randomIndex] = temp;
    }
}

// Funzione Bogosort
void bogosort(int *vett, int lunghezza) {
    while (!isSorted(vett, lunghezza)) {
        shuffle(vett, lunghezza);
    }
}

int main(int argc, char *argv[]) {

  // popolo l'array
  int vett[LENGHT]; // creazione del vettore

  int scelta;
  int input;
  int posizione;
  int lunghezzaAttuale = LENGHT;
  fillArray(vett);

  do {
    scelta = menu(0);
    switch (scelta) {
    case 1:
      // stampa contenuto array
      printf("Contenuto array: \n");
      printArray(vett, lunghezzaAttuale);
      break;
    case 2:
      // array invertito
      swapArray(vett, lunghezzaAttuale);
      break;
    case 3:
      // somma e media
      printf("Somma: %d, media:%2.f \n", somma(vett, lunghezzaAttuale),
             (float)somma(vett, lunghezzaAttuale) / lunghezzaAttuale);
      break;
    case 4:
      // visualizza numeri pari
      evenOrOdd(vett, 0, lunghezzaAttuale);
      break;
    case 5:
      // visualizza numeri dispari
      evenOrOdd(vett, 1, lunghezzaAttuale);
      break;
    case 6:
      // ricerca numero in input
      printf("Digitare numero da ricercare:");
      scanf("%d", &input);

      posizione = ricerca(vett, input, lunghezzaAttuale);

      if (posizione != -1) {
        // numero trovato
        printf("Numero %d trovato alla posizone %d dell'array", input,
               posizione);
      } else {
        printf("Numero non presente all'interno dell'array");
      }
      break;
    case 7:
      // eliminazione di un elemento
      printf("Digitare numero da eliminare:");
      scanf("%d", &input);

      // verifico la presenza dell'elemento all'interno dell'array
      posizione = ricerca(vett, input, lunghezzaAttuale);

      if (posizione != -1) {
        // elimino l'elemento
        elimina(vett, posizione, lunghezzaAttuale);

        lunghezzaAttuale--; // aggiorno la lunghezza del vettore

        // ristampo il vettore
        printf("Vettore dopo eliminazione: \n");
        printArray(vett, lunghezzaAttuale);

      } else {
        printf("Numero non presente nell'array");
      }
      break;
    case 8:
      // alterna cifre

      printf("Vettore prima dell'alterazione: \n");
      printArray(vett, lunghezzaAttuale);

      alternare(vett, lunghezzaAttuale);

      // stampa vettore con cifre alternate due a due
      printf("\nVettore dopo dell'alterazione: \n");
      printArray(vett, lunghezzaAttuale);
      break;
    case 9:
      // ordinamento di vettore con bubble sort o bogosort
      do {
        printf("[0] bogosort");
        printf("[1] bubble sort");

      } while (scelta != 0 || scelta != -1);

      if (scelta == 0) {
        // bogosort
        bogosort(vett, lunghezzaAttuale);
      } else {
        // bubble sort
        bubblesort(vett, lunghezzaAttuale);
      }

      printf("Vettore ordinato: \n");
      printArray(vett, lunghezzaAttuale);
      break;
    }
    printf("\n===================\n");
  } while (scelta > 0);

  printf("Programma finito \n");
}