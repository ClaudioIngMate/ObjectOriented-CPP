//
// Created by Danilo Ardagna on 2019-09-28.
//

#include "Library.h"


/* YOUR CODE GOES HERE */
int Library::find(const string &author, const string &title) const {
    int return_index=-1;
    bool book_found = false;
    for (size_t i=0; i<books.size() && (book_found== false); i++){ //equivalent !book_found (NOT book_found)
        // PSEUDOCODE:
        // if (title of current book = title) AND (author of the current book ==author)
        // --> save the current index and Exit the loop
        // ELSE do not do anything


        // if(books[i].getTitle() == title && books[i].getAuthor()==author){
        // --> ho il metodo EQUAL_TO di book

        if( books[i].equal_to(author, title) ){ // evita quello che c'è scritto 3 righe sopra

            return_index=i;
            book_found=true;
        }
    }

    return return_index;
}

int Library::findAvailableBook(const string &author, const string &title) const {

    int return_index=-1;
    bool book_found = false;
    for (size_t i=0; i<books.size() && (!book_found); i++){ //

        if( books[i].equal_to(author, title) && books[i].isAvailable() ){ // uso la GETTER isAvailable --> è la differenza con il semplice find; ometto ==true.

            return_index=i;
            book_found=true;
        }
    }

    return return_index;

}

void Library::addBook(const Book &book) {
    books.push_back(book);
}

void Library::print() const {

    for (size_t i=0; i<books.size(); i++){
        books[i].print();
    }
}

int Library::rentBook(const string &author, const string &title) {

    int index= findAvailableBook(author,title); //returns me the index of the book in the library if it is available, 0 otherwise

    // se noleggio un libro, devo settare available a FALSE!! (sto rimuovendo l'oggetto fisico dalla generica Library)

    // se non è disponibile stampa un messaggio di errore:
    if(index ==-1){
        std::cerr <<" The book is not available, sorry!! :( ";
        return -1;
    }
    // altrimenti indexx mi dà la posizione del libro nel vettore books. da cui devo ricavare il codice
    else{
        books[index].setAvailable(false); // se lo noleggio, poi non è piu disponibile!!
        return books[index].getCode();
    }

}

bool Library::returnBook(unsigned int code) {

    bool book_found= false;

    for (size_t i=0; i<books.size(); i++){
        if(books[i].getCode()==code && books[i].isAvailable()==false ){// se effettivamente è stato noleggiato...
            books[i].setAvailable(true);
            book_found = true;
        }
    }

    if(!book_found){  // EQUIVALENTE if (book_found ==false)
        cerr<< "Book is not available or not found";
    }
    return book_found;

}

void Library::printOldest() const {

    unsigned index_oldest=0;
    for (size_t i=0; i<books.size(); i++){
        if(books[i].getYear() < books[index_oldest].getYear()){
            index_oldest=i;
        }
    }
    cout << " Now I display all the features of the oldest book:" << endl;
    books[index_oldest].print();

}
