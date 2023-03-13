#include <stdio.h>
void main()
{
    int prodotti, prodotti50 = 0;
    const int min = 50;
    float percentuale, pzInc, somma = 0, media, prezzo, somma50 = 0, media50;
    // controllo che l'utente non possa inserire una quantità minore o uguale a 0 di prodotti
    do
    {
        printf("Quanti prodotti devi inserire? \n");
        scanf("%d", &prodotti);
    } while (prodotti <= 0);

    for (int i = 1; i <= prodotti; i++)
    {
        // controllo che il prezzo inserito non sia minore o uguale a 0
        do
        {
            printf("Inserire il prezzo del prodotto numero %d \n", i);
            scanf("%f", &prezzo);
        } while (prezzo <= 0);
        // controllo che la percentuale non sia minore di 0
        do
        {
            printf("Inserire percentuale di incremento del prezzo\n");
            scanf("%f", &percentuale);
        } while (percentuale < 0);
        pzInc = prezzo * (percentuale / 100) + prezzo;
        printf("Il prezzo incrementato del prodotto numero %d è di %2.f \n", i, pzInc);
        somma = somma + pzInc;
        // verifico quando il prezzo incrementato è maggiore della soglia minima (50) per differenziare i calcoli
        if (pzInc > min)
        {
            // colcoli per fare la media in seguito
            prodotti50++;
            somma50 = pzInc + somma50;
        }
    }
    // calcoli fuori dal ciclo for per non essere rindondanti e far risparmiare lavoro alla CPU
    media50 = somma50 / prodotti50;
    media = somma / prodotti;
    // output dei risultati
    printf("\n la somma totale di tutti i prezzi incrementati equivale a %2.f", somma);
    printf("\n la media totale di tutti i prezzi incrementati equivale a %2.f", media);
    printf("\n la somma totale di tutti i prezzi incrementati superiori a %d equivale a %2.f", min, somma50);
    printf("\n la media totale di tutti i prezzi incrementati superiori a %d equivale a %2.f", min, media50);
}