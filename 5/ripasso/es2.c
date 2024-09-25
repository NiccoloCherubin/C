#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Controlla se una stringa contiene solo lettere
int justLetters(char stringa[]) {
  for (int i = 0; i < strlen(stringa); i++) {
    // Uso il codice ASCII per controllare se è una lettera maiuscola o
    // minuscola
    if (!((stringa[i] >= 'A' && stringa[i] <= 'Z') ||
          (stringa[i] >= 'a' && stringa[i] <= 'z'))) {
      return 0;
    }
  }
  return 1; // true
}

// Controlla la presenza di una lettera nella stringa
int verificaPresenza(char lettera, char stringa[]) {
  for (int i = 0; i < strlen(stringa); i++) {
    if (stringa[i] == lettera) {
      return 1;
    }
  }
  return 0;
}

int doubleLetters(char string[]) {
  for (int i = 0; i < strlen(string) - 1; i++) {
    if (string[i] == string[i + 1]) {
      return 1;
    }
  }
  return 0;
}

// Restituisce una nuova stringa con i caratteri nelle posizioni pari o dispari
char *evenOrOddString(char string[], int choice) {
  char *str = (char *)malloc((strlen(string) / 2 + 1) *
                             sizeof(char)); // Alloco spazio per la stringa
  int k = 0;

  for (int i = choice; i < strlen(str); i += 2) {
    str[k++] = string[i];
  }
  str[k] = '\0'; // Termino la stringa con il carattere terminatore

  return str;
}

int main(int argc, char **argv) {
  char string1[100];
  char string2[100];
  char lettera;

  printf("Inserire stringa \n");
  scanf("%s", string1); // Lettura della stringa

  printf("Stringa inserita: %s \n", string1);

  // Consumo il newline rimasto nel buffer dopo la lettura della stringa
  getchar();

  // Verifico se la stringa contiene solo lettere
  if (!justLetters(string1)) {
    printf("La stringa non contiene solo lettere \n");
  } else {
    printf("La stringa contiene solo lettere \n");
  }

  // Verifico la presenza di una lettera nella stringa
  printf("Digitare una lettera per verificarne la presenza: \n");
  scanf("%c", &lettera);

  if (verificaPresenza(lettera, string1)) {
    printf("La lettera inserita è presente \n");
  } else {
    printf("La lettera inserita non è presente \n");
  }

  // Chiamo la funzione evenString
  char *evenStr = evenOrOddString(string1, 0);
  printf("Stringa con i caratteri in posizione pari: %s\n", evenStr);

  char *oddStr = evenOrOddString(string1, 1);
  printf("Stringa con i caratteri in posizione dispari: %s\n", oddStr);

  free(evenStr); // Libero la memoria allocata
  free(oddStr);  // Libero la memoria allocata

  if (doubleLetters(string1)) {
    printf("La stringa contiene delle doppie \n");
  } else {
    printf("La stringa non contiene delle doppie \n");
  }

  // seconda stringa
  printf("Inserisci una seconda stringa: \n");
  scanf("%s", string2);

  // Consumo il newline rimasto nel buffer dopo la lettura della stringa
  getchar();

  // verifico lunghezza stringhe
  if (strcmp(string1, string2) > 0) {
    printf("La stringa %s ha più caratteri della stringa %s\n", string1,
           string2);
  } else if (strcmp(string1, string2) < 0) {
    printf("La stringa %s ha più caratteri della stringa %s\n", string2,
           string1);
  } else {
    printf("Le stringhe hanno lo stesso numero di caratteri \n");
  }

  return 0;
}
