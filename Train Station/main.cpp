#include <iostream>

#include "Train.h"
#include "TrainStation.h"

int main() {

    Train t1("Italo", 1980, 20);
    Train t2("Frecciarossa", 2005, 30);
    Train t3("Regionale", 1997, 16);
    Train t4("TILO", 2004,20);
    Train t5("Malpensa Express", 2020,15);

    TrainStation ts;
    ts.Arrives(t1,3,'N');
    ts.Arrives(t2,2,'S');
    ts.Arrives(t3,2,'N');
    ts.Arrives(t4,2,'S');
    ts.Arrives(t5,2,'S');

    unsigned platform =2;
    std::cout << " I print all the trains in platform " << platform << std::endl;
    ts.print_platform(platform);
    platform =3;
    std::cout << " I print all the trains in platform " << platform << std::endl;
    ts.print_platform(platform);

    std::cout << " Number of trains before '" << t3.getName() << "'  in direction South: " << ts.HowManyBefore(t3,'S') << std::endl;

    ts.Leaves(t3,'S'); // NOT ok --> road is not free
    ts.Leaves(t3,'N'); // ok
    ts.Leaves(t1,'W'); // not allowed direction
    ts.Leaves(t1,'S'); // ok

    return 0;

}
