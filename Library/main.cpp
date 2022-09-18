#include <iostream>
#include "Book.h"
#include "Library.h"

using std::cout;

int main() {

    // I can define books with the ''entire'' constructor
    Book b1(1, 2013, 1399, "S. B. Lippman", "C++ primer", true);


    // I can define books without available, which is = true by default
    Book b2(2, 2013, 1361, "B. Stroustrup", "The C++ programming language");


    // Stampo i libri singolarmente
    b1.print();
    b2.print();



    cout << "*******************************************";

    Library lib; // definisco lib come un oggetto di ''tipo'' (è una classe) Library


    lib.addBook(b1); // aggiungo il libro b1 alla Library 'lib'
    lib.addBook(b2); // aggiungo il libro b2 alla Library 'lib'

    // posso stampare NON i libri singolarmente, BENSI' l'intera Library denominata 'lib',
    // in quanto ho implementato, nella intera classe
    lib.print();  //stampo lo stato dell'intera LIB

    // testo se funziona rentBook, metodo pubblico della classe Library

    int codice=lib.rentBook("S. B. Lippman", "C++ primer");

    lib.print(); // con questa print --> vedo che il Lippman è NON AVAILABLE (infatti l ho noleggiato alla riga sopra)
    cout << "CODICE DEL LIBRO NOLEGGIATO -->" << codice << endl;
    cout << "****************+"<< endl;

    // ora dovrebbe stampare un messaggio di errore
    lib.rentBook("S. B. Lippman", "C++ primer");
    lib.print();
    cout << "****************+"<< endl;


    // Now I try to return book with code 1 twice: first time OK, second time NO!!

    bool ciao=lib.returnBook(1);  // variabile CIAO non necessaria!!! (anche se il metodo restituisce un booleano)
    lib.print();
    cout << "****************+"<< endl;

    lib.returnBook(1);
    lib.print();
    cout << "****************+"<< endl;


    cout << "Oldest book" << endl;

    lib.printOldest();

    return 0;
}