//
// Created by Danilo Ardagna on 2019-09-28.
//

#ifndef LIBRARYINITIALCODE_BOOK_H
#define LIBRARYINITIALCODE_BOOK_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Book {
private:
    unsigned code;
    unsigned year;
    unsigned pages;
    string author;
    string title;
    bool available;

public: // constructor
    Book(unsigned int code, unsigned int year, unsigned int pages, const string &author, const string &title,
         bool available);
    // constructor con available=true sempre!!!
    Book(unsigned int code, unsigned int year, unsigned int pages, const string &author, const string &title);

public: // declarations of the GETTERS

    unsigned int getCode() const;

    unsigned int getYear() const;

    unsigned int getPages() const;

    const string &getAuthor() const;

    const string &getTitle() const;

    bool isAvailable() const;

public: // declaration of the SETTER of available

    void setAvailable(bool available);

public:

    // metodo equal_to di book per controllare l'uguaglianza
    bool equal_to (const string & author, const string & title) const;


    /* YOUR CODE GOES HERE */
    void print() const;
};


#endif //LIBRARYINITIALCODE_BOOK_H
