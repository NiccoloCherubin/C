// scrivere programma che effettui somma di due numeri interi
// bisogna dichiarare variabili all'inizio
#include <stdio.h> // scrittura e lettura
void main()        // istruzione principale in cui mettere codice
{
    int numero1, numero2, somma, quozInt; // int = intero. Fase intestazione
    float var1, var2, somma2, quozFloat, diff, prodotto;
    numero1 = 50; // assegnazione variabili
    numero2 = 80;
    somma = numero1 + numero2;
    printf("La somma intera e'  %d : \n ", somma); // d = decimal; % dice che tipo di variabile f= float = reale
    var1 = 3.074;
    var2 = 2.05;
    somma2 = var1 + var2;
    printf("La somma reale eì di %.3f :  \n", somma2); // %f = float. .3 per vedere tre decimali
    quozInt  = (float) numero2 / numero1; // (float) diventa reale = casting
    printf ("Il quoziente intero è di : %f \n ", quozInt  ); //mettere %f perchè fatto casting
    quozFloat = var1/var2;
    printf ("Il quoziente reale è di %.3f \n" , quozFloat);
    diff = var2 - var1;
    printf ("La differenza tra reali è di : %f \n", diff);
    prodotto = var1 * var2;
    printf ("Il prodotto è di %f \n" , prodotto);

    }