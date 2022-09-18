//
// Created by Clod on 08/12/2021.
//

#ifndef WEDDINGAGENCY_WEDDINGAGENCY_H
#define WEDDINGAGENCY_WEDDINGAGENCY_H

#include "Person.h"
#include <set>
#include <map>
#include <vector>

class WeddingAgency {

private:
    // set of clients and set of preferences
    std::set<Person> clients; // Person and corresponding sex
    std::map<Person,Person> options; // Preferences of the clients (1st(key) expresses desire on 2nd (mapped))

public:
    // does not need the constructor...

    // Insert a client: a Person becomes client of the agency: if already present, no effect
    void AddClient(const Person& p);

    // Adds an option: each person can select only 1 person; so the eventual previous preference is deleted
    // Remark: p1 and p2 must be clients and must be of opposite sex!
    void AddOption(const Person& p1, const Person& p2);

    // Returns a vector of Person(s) containing all couples who selected one the other
    // Vector contains in i=0,2,4,... females (and in i+1 all the males...)
    std::vector<Person> CreatedCouples() const ;

    void printClients() const;
    void printOptions() const;
};

bool find_person(const std::vector<Person>& people, const Person& p);

#endif //WEDDINGAGENCY_WEDDINGAGENCY_H
