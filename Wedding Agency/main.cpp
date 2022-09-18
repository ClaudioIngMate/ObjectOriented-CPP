/* Text of the exercise:
 *
 * We want to create a C++ class to manage a wedding agency. The agency has a name and it is described by the following operations:
 * --> AddClient(p): a new person is becomes client of the wedding agency. If the person is still a client, nothing happens
 * --> AddOption(p1,p2): person p1 declares to the agency the interest for person p2; each person can select 1 person only,
 * so the eventual previous choice is deleted; p1 and p2 must be clients and of different gender
 * --> CreatedCouples(): returns a vector of Person(s) containing all the couples that chose one the other... . In location i (i=0,2,4...)
 * vector contains females, the males are in positions i+1 (1,3,5...)
 *
 *  *** IMPLEMENT THE WeddingAgency class (both cpp and hpp files) ***
 *
 */


#include <iostream>

#include "Person.h"
#include "WeddingAgency.h"

int main() {

    Person p1("Claudio",23,true);
    Person p2("Valentina", 23,false);
    Person p3("Andrea", 23,true);
    Person p4("Matteo", 23,true);
    Person p5("Martina", 22,false);
    Person p6("Rachele", 23,false);

    WeddingAgency wa;
    // Add the clients to the wedding agency
    wa.AddClient(p1); wa.AddClient(p2); wa.AddClient(p3); wa.AddClient(p4); wa.AddClient(p5); wa.AddClient(p6);
    wa.printClients();

    // Add the preferences to the wedding agency
    wa.AddOption(p1,p2); // Claudio chooses Valentina
    wa.AddOption(p2,p1); // Valentina chooses Claudio
    wa.AddOption(p4,p6); // Matteo chooses Rachele
    wa.AddOption(p6,p4); // Rachele chooses Matteo

    wa.printOptions();

    std::cout << " \n *** Created couples: *** " << std::endl;
    std::vector<Person> couples;
    couples= wa.CreatedCouples();

    std::cout << " Print the vector of couples returned as output of the previous call: " << std::endl;
    for (unsigned i=0; i<couples.size(); i++){
        std::cout << couples[i].getName() << " -- " ;
    }
    // I correctly inserted in the vector first the females, then the  males !

    return 0;

}