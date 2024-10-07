#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50
#define YEAR_LENGTH 5  // Contando il carattere terminatore
#define PRICE_LENGTH 5 // Contando il carattere terminatore
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
// funzione che stampa il menù e ritorna la choice effettuata dall'utente
int menu(int choice) {
  printf("\n[1] Visualizza elementi array \n");  
  printf("[2] Aggiungi un elemento all' array \n");  
  printf("[3] Modifica un elementlo dell'array \n"); 
  printf("[4] Elimina un elementlo dell'array \n"); 
  printf("[5] Salva \n"); 

  printf("inserire opzione desiderata (scegliere -1 per uscire):");
  scanf("%d", &choice);

  return choice;
}

//funzione che stampa a video il contenuto di ogni categoria
void printArr(Category *categories)
{
    for(int i = 0; i <N_CATEGORIES;i++)
    {
        printf("Libri presenti nella categoria %s, %d\n", categories[i].categoryName, categories[i].cont);

        for(int k = 0; k < categories[i].cont; k++)
        {
            printf("Titolo: %s, Autore: %s\n", categories[i].books[k].title,categories[i].books[k].author);
        }
    }
}

//funzione che crea un nuovo libro
Book newBook(Book book)
{
    printf("Inserire titolo del libro \n");
    scanf("%s", book.title);

    printf("Inserire autore del libro \n");
    scanf("%s", book.author);

    printf("Inserire anno di pubblicazione del libro \n");
    scanf("%s", book.year);

    printf("Inserire prezzo del libro \n");
    scanf("%s", book.price);

    return book;

}

int findBook(char *title, Category categoria)
{
    for(int i = 0; i < categoria.cont;i++)
    {        
        if(strcmp(categoria.books[i].title, title) == 0) //confronto i titoli dei libri
        {
            return i; //torno la posizione del libro
        }
        
    }
    return -1; //libro non trovato
}

// funzione che elima elemento dall'array
void deleteBook(Category *categoria, int posizione) {

  // elimino l'elemento
  for (int i = posizione; i < categoria->cont - 1; i++) {
    categoria->books[i] = categoria->books[i + 1]; // Sposto gli elementi a sinistra
  }
  categoria->cont--; //diminuisco il contatore
}
int chooseCategory(Category *categories)
{
    int supp;
    do 
    {
        printf("Scegli la categoria nella quale aggiungere il libro \n");
            for (int i = 0; i < N_CATEGORIES; i++) 
                {
                    printf("[%d] %s \n", i, categories[i].categoryName);
                }
                scanf("%d", &supp);
                
    }while (supp < 0 || supp > N_CATEGORIES); //controlla se ha fatto una scelta valida

    return supp;
}

//funzione che esporta tutto il contenuto dell'array su file
void exportToFile(Category *categories)
{
    FILE *dest;
    //apro il file in modalità scrittura
    dest = fopen("libreria_libri.csv", "w");

    if(dest == NULL)
    {
        printf("Errore apertura del file");
        exit(-1);
    }

    //scrivo l'intestazione del file
    fprintf(dest, "title,author,year,price,category\n");

    for(int i = 0; i < N_CATEGORIES; i++)
    {
        for(int k = 0; k < categories[i].cont;k++)
        {
            Book *supp = &categories[i].books[k];

            fprintf(dest, "%s,%s,%s,%s,%s\n",supp->title, supp->author, supp->year, supp->price, categories[i].categoryName);        
        }
    }

    //chiudo il file
    fclose(dest);
}
int main(int argc, char **argv) {

    int choice; //scelta che effettuerà l'utente nel programma

    //variabili di supporto utili dopo
    int supp;
    Book temp;
    char tempTitle[100];
    int index;



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
        exit(-1);
    }

    // Importo i file all'interno dell'array
    importFromFile(origin, categories);

    // Chiudo il file
    fclose(origin);

    do {
        choice = menu(choice);

        switch (choice) {

            case 1:
                //stampa a video l'array
                printArr(categories);
            break;                
            case 2:
                //crea un nuovo libro e lo aggiunge nella libreria 
                supp = chooseCategory(categories);                               
                addBook(newBook(temp), &categories[supp]);
            

            break;

            case 3:
                //trova e modifica elemento di un libro

                //faccio scegliere all'utente la categoria
                supp = chooseCategory(categories);    
                
                //cerco il libro da modificare
                index = findBook(tempTitle, categories[supp]);

                if(index != -1)
                {
                    //gli cancello il vecchio libro
                    deleteBook(&categories[supp], index);

                    //gli faccio aggiungere il nuovo libro coi dati modificati
                    addBook(newBook(temp), &categories[supp]);

                }
                else{
                    printf("Libro non trovato \n");
                }                           

            break;

            case 4:
            //ricerca di un libro nella libreria e lo elimina            

            printf("inserire titolo del libro da eliminare \n");
            scanf("%s", tempTitle);

            //faccio scegliere all'utente la categoria dalla quale eliminare il libro
            supp = chooseCategory(categories);                               

            //ricerco il libro da eliminare
            index = findBook(tempTitle, categories[supp]);

            if(index != -1)
            {
                // elimino il libro dalla libreria
                deleteBook(&categories[supp], index);
                printf("Libro trovato ed eliminato con successo\n");
            }
            else{
                printf("Libro non trovato \n");
            }
            break;
            
            case 5:
                //esporta il contenuto dell'array su file
                exportToFile(categories);

                printf("Salvataggio avvenuto con successo \n");
            break;
        
        }

    }while (choice >= 1);
    
    // Libero la memoria allocata utilizzando la realloc
    for (int i = 0; i < N_CATEGORIES; i++) {
        free(categories[i].books);
    }

    return 0;
}
