#include <ctype.h> // Per la funzione tolower
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Controlla se una stringa contiene solo lettere
int justLetters(char stringa[]) {
  for (int i = 0; i < strlen(stringa); i++) {
    if (!((stringa[i] >= 'A' && stringa[i] <= 'Z') ||
          (stringa[i] >= 'a' && stringa[i] <= 'z'))) {
      return 0;
    }
  }
  return 1;
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

// Verifica doppie lettere
int doubleLetters(char string[]) {
  for (int i = 0; i < strlen(string) - 1; i++) {
    if (string[i] == string[i + 1]) {
      return 1;
    }
  }
  return 0;
}

// Restituisce una nuova stringa con i caratteri in posizioni pari o dispari
char *evenOrOddString(char string[], int choice) {
  char *str = (char *)malloc((strlen(string) / 2 + 1) * sizeof(char));
  if (str == NULL) {
    printf("Errore di allocazione della memoria\n");
    return NULL;
  }
  int k = 0;
  for (int i = choice; i < strlen(string); i += 2) {
    str[k++] = string[i];
  }
  str[k] = '\0'; // Termino la stringa con il carattere terminatore
  return str;
}

// Trova lettere comuni tra due stringhe
char *identicalLetters(char string1[], char string2[]) {
  int k = 0;
  char *letters = (char *)malloc(100 * sizeof(char));
  if (letters == NULL) {
    printf("Errore di allocazione della memoria\n");
    return NULL;
  }
  if (strlen(string1) <= strlen(string2)) {
    for (int i = 0; i < strlen(string1); i++) {
      for (int j = 0; j < strlen(string2); j++) {
        if (string1[i] == string2[j]) {
          letters[k] = string1[i];
          k++;
          break;
        }
      }
    }
  } else {
    for (int i = 0; i < strlen(string2); i++) {
      for (int j = 0; j < strlen(string1); j++) {
        if (string2[i] == string1[j]) {
          letters[k] = string2[i];
          k++;
          break;
        }
      }
    }
  }
  letters[k] = '\0';
  return letters;
}

// Controlla se un carattere è una vocale
int isVowel(char ch) {
  ch = tolower(ch);
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Conta il numero di vocali
int countVowels(char string[]) {
  int count = 0;
  for (int i = 0; i < strlen(string); i++) {
    if (isVowel(string[i])) {
      count++;
    }
  }
  return count;
}

// Controlla se un carattere è una consonante
int isConsonant(char ch) {
  ch = tolower(ch);
  return ((ch >= 'a' && ch <= 'z') && !isVowel(ch));
}

// Conta il numero di consonanti
int countConsonants(char string[]) {
  int count = 0;
  for (int i = 0; i < strlen(string); i++) {
    if (isConsonant(string[i])) {
      count++;
    }
  }
  return count;
}

int main(int argc, char **argv) {
  char string1[100];
  char string2[100];
  char letter;

  printf("Inserire stringa \n");
  scanf("%s", string1);

  printf("Stringa inserita: %s \n", string1);
  getchar(); // Consumo il newline rimasto nel buffer

  if (!justLetters(string1)) {
    printf("La stringa non contiene solo lettere \n");
  } else {
    printf("La stringa contiene solo lettere \n");
  }

  printf("Digitare una lettera per verificarne la presenza: \n");
  scanf("%c", &letter);
  getchar(); // Consumo il newline

  if (verificaPresenza(letter, string1)) {
    printf("La lettera inserita è presente \n");
  } else {
    printf("La lettera inserita non è presente \n");
  }

  char *evenStr = evenOrOddString(string1, 0);
  printf("Stringa con i caratteri in posizione pari: %s\n", evenStr);
  char *oddStr = evenOrOddString(string1, 1);
  printf("Stringa con i caratteri in posizione dispari: %s\n", oddStr);

  free(evenStr);
  free(oddStr);

  if (doubleLetters(string1)) {
    printf("La stringa contiene delle doppie \n");
  } else {
    printf("La stringa non contiene delle doppie \n");
  }

  printf("Inserisci una seconda stringa: \n");
  scanf("%s", string2);
  getchar();

  if (strlen(string1) > strlen(string2)) {
    printf("La stringa %s ha più caratteri della stringa %s\n", string1,
           string2);
  } else if (strlen(string1) < strlen(string2)) {
    printf("La stringa %s ha più caratteri della stringa %s\n", string2,
           string1);
  } else {
    printf("Le stringhe hanno lo stesso numero di caratteri \n");
  }

  char *letters = identicalLetters(string1, string2);

  if (letters[0] != '\0') {
    printf("Le lettere in comune tra le due stringhe inserite sono: %s \n",
           letters);
  } else {
    printf("Le stringhe non hanno lettere in comune \n");
  }

  free(letters);

  return 0;
}
