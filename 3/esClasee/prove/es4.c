/* Su una somma di denaro (relativa all'acquito di un prodotto) si vuole applicare uno sconto in base all'importo inserito seguendo il seguente schema:
            da 0 a 500€ sconto del 10%;
            da 501 a 1000 sconto del 20%;
            oltre i 1001 sconto 30%;
 Il programma dopo aver calcolato e visualizzato a video lo sconto ed il prezzo netto deve permettere di re-inserire
 ulteriori somme di denaro.
 */
#include <stdio.h>
void main()
{
    const float sconto1 = 0.1, sconto2 = 0.2, sconto3 = 0.3;
    float importo, totale, sconto;
    int risposta;
    do
    {
        do
        {
            printf("inserire importo \n");
            scanf("%f", &importo);
        } while (importo <= 0);
        if (importo <= 500)
        {
            sconto = importo * sconto1;
        }
        else if (importo <= 1000)
        {
            sconto = importo * sconto2;
        }
        else if (importo >= 1001)
        {
            sconto = importo * sconto3;
        }
        totale = importo - sconto;
        printf("\n Lo sconto è di %f", sconto);
        printf("\n Il totale è di %f", totale);
        printf("\n Si hanno altro importi da inserire?");
        printf("\n Sì (1) / No (0) \n");
        scanf ("%d" , &risposta);
    } while (risposta != 0);
    printf (" \n Programma finito");
}