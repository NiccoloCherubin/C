#include <stdio.h>
// Definizione della struttura per rappresentare un punto
struct Punto
{
    int x;
    int y;
    int z;
};

// Funzione per stampare le coordinate di un punto
void stampa_punto(struct Punto p)
{
    printf("Coordinate del punto: (%d, %d, %d)\n", p.x, p.y, p.z);
}

// Funzione per creare un nuovo punto con coordinate incrementate di una unità rispetto al punto fornito
struct Punto punto_modificato(struct Punto p)
{
    struct Punto nuovo_punto;
    nuovo_punto.x = p.x + 1;
    nuovo_punto.y = p.y + 1;
    nuovo_punto.z = p.z + 1;
    return nuovo_punto;
}

int main()
{
    struct Punto punto1 = {0, 1, 2};

    // Stampiamo il punto1
    printf("Punto 1:\n");
    stampa_punto(punto1);

    // Creiamo un nuovo punto con coordinate incrementate
    struct Punto punto2 = punto_modificato(punto1);

    // Stampiamo il nuovo punto (punto2)
    printf("Nuovo Punto (punto2):\n");
    stampa_punto(punto2);

    return 0;
}