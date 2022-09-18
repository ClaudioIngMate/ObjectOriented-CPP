//
// Created by Clod on 08/12/2021.
//

#include "WeddingAgency.h"
#include <iostream>

void WeddingAgency::AddClient(const Person& p){
    clients.insert(p);
}

void WeddingAgency::printClients() const{
    std::cout << " *** These are the clients of the wedding agency: *** " << std::endl;
    for(auto i=clients.cbegin(); i!=clients.cend(); i++){
        i->print();
    }
}

void WeddingAgency::AddOption(const Person& p1, const Person& p2){

    // check if p1 has already expressed a preference; in this case I delete the old preference
    if (options.find(p1)!=options.end()){
        options.erase(p1);
    }
    // check: different sex
    if(p1.getIsMale()!=p2.getIsMale()){
        options.insert(std::make_pair(p1,p2));
    }
    else{
        std::cout << " No possible match for people of the same gender. \n This is not a LBGTQI+ friendly wedding agency ! " << std::endl;
    }
}

void WeddingAgency::printOptions() const{
    std::cout << " *** These are the preferences :  *** " << std::endl;
    for (auto i=options.cbegin(); i!=options.cend(); i++) {
        std::cout << " Preference of ";
        (i->first).print();
        std::cout << " is : ";
        (i->second).print();
    }
}

std::vector<Person> WeddingAgency::CreatedCouples() const {

    std::vector<Person> result;
    for (auto iter=options.cbegin(); iter!=options.cend(); iter++){
        Person p1=iter->first;
        Person p2=iter->second;

        if((options.find(p1))->second ==p2 && (options.find(p2))->second ==p1 ){
            if(!find_person(result,p1) && !find_person(result,p2)){ // if not added yet in the std::vector 'result'
                std::cout << " couple found: " << p1.getName() << " will marry " << p2.getName() << " . Congratulations !" << std::endl;
                if(p1.getIsMale()){ // first I have to add the female
                    result.push_back(p2);
                    result.push_back(p1);
                }
                else{
                    result.push_back(p1);
                    result.push_back(p2);
                }
            }
        }
    }
    return result;
}

bool find_person(const std::vector<Person>& people, const Person& p){
    bool found=false;
    for (unsigned i=0; i<people.size(); i++){
        if(people[i]==p){
            found=true;
        }
    }
    return found;
}