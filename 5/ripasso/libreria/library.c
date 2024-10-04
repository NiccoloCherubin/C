#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50
#define YEAR_LENGTH 5  // Contando il carattere terminatore
#define PRICE_LENGTH 10 // Maggiore per considerare valori decimali
#define CATEGORY_LENGTH 50
#define N_CATEGORIES 4

// Definizione della struct Book
typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    char year[YEAR_LENGTH];
    char price[PRICE_LENGTH];
} Book;

// Definizione della struct Category
typedef struct {
    char categoryName[CATEGORY_LENGTH];
    Book *books;
    int cont; // Contatore di libri all'interno della categoria
} Category;

int totBooks = 0; // Variabile che conta i libri totali presenti nella libreria

// Funzione per aggiungere un libro a una categoria
void addBook(Book book, Category *categoria) {
    categoria->books = realloc(categoria->books, (categoria->cont + 1) * sizeof(Book));
    if (categoria->books == NULL) { // Controllo errore realloc
        perror("Errore durante l'allocazione della memoria");
        exit(EXIT_FAILURE);
    }
    categoria->books[categoria->cont] = book;
    categoria->cont++;
    totBooks++;
}

// Funzione per rimuovere spazi bianchi all'inizio e alla fine di una stringa
void trim(char *str) {
    char *start = str;
    while (isspace((unsigned char)*start)) 
    {
      start++;
    }

    char *end = start + strlen(start) - 1; // meno il carattere terminatore
    while (end > start && isspace((unsigned char)*end))
    {
      end--;
    }

    *(end + 1) = '\0'; // Termina la stringa correttamente

    // Sposta la stringa trimata all'inizio della stringa originale. Si aggiunge 2 perché così si include il carattere terminatore di stringa '\0'.
    memmove(str, start, end - start + 2); 
}

// Funzione per importare i dati da un file CSV
void importFromFile(FILE *origin, Category *categories) {
    char row[500];
    Category *categoria = NULL; // Variabile per memorizzare la categoria corrente
    Book book;
    char category_name[CATEGORY_LENGTH];

    // Salto la prima riga del file con le intestazioni
    fgets(row, sizeof(row), origin);

    while (fgets(row, sizeof(row), origin) != NULL) { // Leggo una riga dal file
        // Leggo i campi separati da virgole e li memorizzo nei campi corrispettivi
        sscanf(row, "%[^,],%[^,],%[^,],%[^,],%[^,\n]", book.title, book.author, book.year, book.price, category_name);

        trim(category_name); // Applica il trimming per evitare errori nel confronto   

        // Verifico il nome della categoria per assegnare quella corretta
        for (int i = 0; i < N_CATEGORIES; i++) {
            if (strcmp(category_name, categories[i].categoryName) == 0) {
                categoria = &categories[i];
                break;
            }
        }

        if (categoria == NULL) {
            printf("Categoria non trovata per il libro '%s': %s\n", book.title, category_name);
            continue; // Salta al prossimo libro senza interrompere il ciclo
        }

        // Aggiungo il libro all'array della categoria corretta
        addBook(book, categoria);
    }
}

int main(int argc, char **argv) {
    // Inizializzo le categorie che utilizzerò per suddividere i libri
    Category categories[N_CATEGORIES] = {
        {"Letteratura Classica", NULL, 0},
        {"Narrativa Moderna", NULL, 0},
        {"Filosofia", NULL, 0},
        {"Fantascienza", NULL, 0}
    };

    FILE *origin = fopen("libreria_libri.csv", "r"); // Apro il file in lettura
    if (origin == NULL) {
        perror("Errore nell'apertura del file");
        exit(EXIT_FAILURE);
    }

    // Importo i file all'interno dell'array
    importFromFile(origin, categories);

    // Chiudo il file
    fclose(origin);

    printf("Programma finito senza problemi, libri totali: %d\n", totBooks);
    
    // Libero la memoria allocata utilizzando la realloc
    for (int i = 0; i < N_CATEGORIES; i++) {
        free(categories[i].books);
    }

    return 0;
}
