//
// Created by Danilo Ardagna on 2019-09-28.
//

#include "Book.h"


/* YOUR CODE GOES HERE */

Book::Book(unsigned int code, unsigned int year, unsigned int pages, const string &author, const string &title,
           bool available) : code(code), year(year), pages(pages), author(author), title(title), available(available) {};

Book::Book(unsigned int code, unsigned int year, unsigned int pages, const string &author, const string &title) :
            code(code), year(year), pages(pages), author(author), title(title) {
    available=true;
}

void Book::print() const {

    cout<< code << "\n" << year << "\n" << pages << "\n" << author << "\n" ;
    if(available==true){
        cout<<"Available";
    }
    else{
        cout << "Not available";
    }
    cout << endl;

}

unsigned int Book::getCode() const {
    return code;
}

unsigned int Book::getYear() const {
    return year;
}

unsigned int Book::getPages() const {
    return pages;
}

const string &Book::getAuthor() const {
    return author;
}

const string &Book::getTitle() const {
    return title;
}

bool Book::isAvailable() const {
    return available;
}

void Book::setAvailable(bool avail) {
    Book::available = avail;
}

// implementazione del metodo equal_to di book
bool Book::equal_to(const string &a, const string &t) const {
    return (author==a) && (title)==t;
}


