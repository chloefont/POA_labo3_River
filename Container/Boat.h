//
// Created by cfont on 05.05.2022.
//

#ifndef LABO4_RIVER_BOAT_H
#define LABO4_RIVER_BOAT_H

#include "Container.h"
#include "Bank.h"

class Boat : public Container {
public:
   Boat(const std::string& name, Bank* bank);
   Bank* getBank() const;

private:
   Bank* bank;
};


#endif //LABO4_RIVER_BOAT_H
