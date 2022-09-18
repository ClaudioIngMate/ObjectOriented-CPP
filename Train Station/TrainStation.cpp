//
// Created by Clod on 09/12/2021.
//

#include "TrainStation.h"
#include <iostream>

void TrainStation::Arrives(Train&t, unsigned plat, char dir){

    if(plat==0){
        std::cout << " The number of the platforms starts from 1: platform 0 does not exist " << std::endl;
    }
    else{

        t.setActualPlatform(plat);

        // check whether the platform is already in the map
        auto iter=station.find(plat);
        if(iter==station.end()){ // if not already there
            std::list<Train> lt;
            lt.push_front(t); // if the first train, no difference between front and back
            station.insert(std::make_pair(plat,lt));
        }
        else{ // if in the platform there is already one train...
            if(dir=='N'){
                (iter->second).push_front(t);
            }
            if(dir=='S'){
                (iter->second).push_back(t);
            }
        }
    }
}

void TrainStation::Leaves(Train& t, char dir){

    unsigned pl=t.get_platform();
    // check whether the train can leave in direction 'dir'
    if(dir=='N' || dir=='S'){
        if(dir=='N'){ // to leave in 'N' direction, the train must be the first in the front
            auto tr_pos=station.find(pl); // tr_pos points to the pair (platform, list of trains in this platform)
            if((tr_pos->second).front() == t ){
                std::cout << " Train '" << t.getName() << "' can leave " << std::endl;
                t.setActualPlatform(std::numeric_limits<unsigned>::quiet_NaN());
                (tr_pos->second).pop_front();
            }
            else{
                std::cout << " Train '" << t.getName() << "' cannot leave because of the presence of other trains " << std::endl;
            }
        }
        if(dir=='S'){
            auto tr_pos=station.find(pl);
            if((tr_pos->second).back() == t ){
                std::cout << " Train '" << t.getName() << "' can leave " << std::endl;
                t.setActualPlatform(std::numeric_limits<unsigned>::quiet_NaN());
                (tr_pos->second).pop_back();
            }
            else{
                std::cout << " Train '" << t.getName() << "' cannot leave because of the presence of other trains " << std::endl;
            }
        }
    }
    else{
        std::cout << " Invalid direction of leave for the train '" << t.getName() << "' "<< std::endl;
    }
}

void TrainStation::print_platform(unsigned platform) const{

    auto iter_pl = station.find(platform); // iterator that points to the pair containing the input key
    std::list<Train> train_list = iter_pl->second;
    for(const Train& train: train_list){
        train.print();
    }

}

unsigned TrainStation::HowManyBefore(const Train& t, char dir) const{

    std::list<Train> train_list;
    unsigned platform = t.get_platform();
    auto iter_pl=station.find(platform); // iterator that points to the train of interest
    train_list=iter_pl->second;
    unsigned num=0;
    bool exit=false;
    for (auto it=train_list.cbegin(); it!=train_list.cend() && !exit; it++){
        if(!(*it == t)){
            num++;
        }
        else{
            exit=true;
        }
    }

    if (dir=='N'|| dir=='S'){
        if(dir=='N'){
            return num;
        }
        else{ // case dir=='S'
            return (train_list.size()-num-1);
        }
    }
    else{
        std::cout << " Invalid direction " << std::endl;
        return std::numeric_limits<unsigned>::quiet_NaN();
    }
}