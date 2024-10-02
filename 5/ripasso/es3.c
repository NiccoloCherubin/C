#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define N_CARS 5

typedef struct {
  char ModelloAuto[50];
  char marca[50];
  int cilindrata;
  int anno_immatricolazione;
  float prezzo;
} Auto;

Auto findMax(Auto macchine[]) {
  int max = INT_MIN;
  int index = 0;

  for (int i = 0; i < N_CARS; i++) {
    if (macchine[i].prezzo > max) {
      max = macchine[i].prezzo;
      index = i;
    }
  }
  return macchine[index];
}
Auto findMin(Auto macchine[]) {
  int min = INT_MAX;
  int index = 0;

  for (int i = 0; i < N_CARS; i++) {
    if (macchine[i].prezzo < min) {
      min = macchine[i].prezzo;
      index = i;
    }
  }
  return macchine[index];
}
void ordinamentoAuto(Auto *vett) {
  // utilizzo bubble sort
  for (int i = 0; i < N_CARS - 1; i++) {
    for (int j = 0; j < N_CARS - i - 1; j++) {
      if (vett[j].anno_immatricolazione > vett[j + 1].anno_immatricolazione) {
        // Scambia gli elementi
        Auto temp = vett[j];
        vett[j] = vett[j + 1];
        vett[j + 1] = temp;
      }
    }
  }
}
void printArr(Auto *array,int lunghezza) {
  for (int i = 0; i < lunghezza; i++) {
    printf("modello %s \n", array[i].ModelloAuto);
    printf("marca %s \n", array[i].marca);
    printf("cilindrata %i \n", array[i].cilindrata);
    printf("anna immatricolazione %i \n", array[i].anno_immatricolazione);
    printf("prezzo %f \n", array[i].prezzo);
  }
}
int findIndex(Auto *array, int prezzo) {
  for (int i = 0; i < N_CARS; i++) {
    if (array[i].prezzo == prezzo) {
      return i;
    }
  }
  return -1;
}
void visualizzAutoPerPrezzo(Auto *array, int prezzo) {

  int index = findIndex(array, prezzo);

  if(index == -1)
  {
    printf("Non esiste nessun auto con prezzo %i\n", prezzo);
    exit(-1);
  }

  Auto supp[N_CARS - index];
  int cont = 0;

  for (int i = index; i < N_CARS; i++) {
    supp[cont] = array[i];
    cont++;
  }
  printArr(supp, (N_CARS-index));
}
int main(int argc, char **argv) {

  int prezzo;
  // definizione array di auto
  Auto macchine[N_CARS] = {
      "Modello0", "marca0", 50, 2024, 50000,
      "Modello1", "marca1", 51, 2021, 50001,
      "Modello2", "marca2", 52, 2022, 50002,
      "Modello3", "marca3", 53, 2023, 50003,
      "Modello4", "marca4", 54, 2020, 50004,
  };

  // trovo macchine più e meno costose
  printf("Macchina più costosa: %s con costo: %f \n",
         findMax(macchine).ModelloAuto, findMax(macchine).prezzo);
  printf("Macchina meno costosa: %s con costo: %f \n",
         findMin(macchine).ModelloAuto, findMin(macchine).prezzo);

  // ordino le auto in base all'anno di matricolazione
  ordinamentoAuto(macchine);
  printf("Macchine ordinate \n");
  printArr(macchine,N_CARS);
  printf("==============================\n");

  printf("Inserire prezzo dal quale visualizzare le auto \n");

  scanf("%d", &prezzo);

  visualizzAutoPerPrezzo(macchine, prezzo);

  return 0;
}