#include <stdio.h>
int main(int argc, char *argv[])
{
    float somma = 0, media, prezzo, max = 0, min = 0, mediaA, sommaA = 0, prodottiA = 0;
    const int al = 2.50, la = 3.50;
    int azioni, prodotti = 0;
    // inserimento numero azioni + controllo
    do
    {
        printf("Quante azione vuoi inserire? \n");
        scanf("%d", &azioni);
    } while (azioni <= 0);
    // inizio ciclo for
    for (int i = 0; i < azioni; i++)
    {
        // calcolo numero prodotti per media dopo
        prodotti++;
        // inserimento prezzo dell'azione
        printf("inserire prezzo dell'azione numero %d \n", i + 1);
        scanf("%f", &prezzo);
        // per dopo
        if (i == 0)
        {
            max = prezzo; 
        }
        
        // calcolo somme
        somma = somma + prezzo;
        // guardo se il prezzo rientra nel range richiesto poi ne calcolo la somma
        if (prezzo > al && prezzo < la)
        {
            sommaA = sommaA + prezzo;
            prodottiA++;
        }
        // verifico azione con prezzo maggiore ed assegno
        if (max > min)
        {
            max = prezzo;
        }
        else
        {
            min = prezzo;
        }
    }
    printf("%2.f \n", max);
    printf("%2.f", min);
    // calcolo medie
    media = somma / prodotti;
    // calcolo media solo se necessario
    if (prodottiA != 0)
    {
        mediaA = sommaA / prodottiA;
    }
    return 0;
}