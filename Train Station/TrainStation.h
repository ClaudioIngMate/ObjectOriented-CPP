//
// Created by Clod on 09/12/2021.
//

#ifndef TRAINS_TRAINSTATION_H
#define TRAINS_TRAINSTATION_H

#include "Train.h"

#include <map>
#include <list>

// convention from direction: (front of the list) N----S (back of the list)


class TrainStation {

private:
    std::map<unsigned, std::list<Train>> station;
public:

    // Train t arrives in platform 'plat' and from direction 'dir'. Suppose the train is not already present.
    // Observation: Train is passed as NON CONST reference since when it arrives, I set its new platform where it stays!
    void Arrives(Train&t, unsigned plat, char dir);

    // Train t leaves from the station in dirction 'dir'. Check whether the direction for the train is free!
    // Observation: Train is passed as NON CONST reference since when it leaves, I set its platform = NaN;
    void Leaves(Train&t, char dir);

    void print_platform(unsigned platform) const;

    unsigned HowManyBefore(const Train& t, char dir) const;

};


#endif //TRAINS_TRAINSTATION_H
