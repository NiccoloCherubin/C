#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_LENGHT 50
#define AUTHOR_LENGHT 50
#define CATEGORY_LENGHT 50

// definizione della struct Book
typedef struct {
  char title[TITLE_LENGHT];
  char author[AUTHOR_LENGHT];
  int year;
  float price;
} Book;

// definizione della struct Category
typedef struct {
  char categoryName[CATEGORY_LENGHT];
  Book *books;
  int cont; // contatore di libri all'interno della categori
} Category;

int totBooks = 0; // variabile che conta i libri totali presenti nella libreria

void addBook(Book book, Category *categoria) {
    categoria->books = realloc(categoria->books, (categoria->cont + 1) * sizeof(Book)); //rialloco la memoria in modo dinamico ogni volta che viene aggiunto un libro all'intenro della libreria
    categoria->books[categoria->cont] = book; //memorizzo il libro all'interno dell'array
    categoria->cont++; //incremento il contatore di libri all'interno della categoria
}

int main(int argc, char **argv) {

  // inizializzo le categorie che utilizzerò per suddividere i libri
  Category classic = {"Letteratura Classica",NULL,0}; //metto NULL perché non so quanta memoria assegnare all'array. Questa cosa viene gestita grazie al realloc
  Category modernFiction = {"Narrativa Moderna", NULL,0}; //metto NULL perché non so quanta memoria assegnare all'array. Questa cosa viene gestita grazie al realloc
  Category philosophy = {"Filosofia",NULL,0}; //metto NULL perché non so quanta memoria assegnare all'array. Questa cosa viene gestita grazie al realloc
  Category scifi = {"Fantascienza",NULL,0};//metto NULL perché non so quanta memoria assegnare all'array. Questa cosa viene gestita grazie al realloc

  return 0;
}