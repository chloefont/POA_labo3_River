//
// Created by cfont on 05.05.2022.
//

#ifndef LABO4_RIVER_BOAT_H
#define LABO4_RIVER_BOAT_H

#include "Container.h"
#include "Bank.h"

class Boat : public Container {
public:
   Boat(const std::string& name, Bank* bank, size_t capacity);
   Bank* getBank() const;
   void setBank(Bank* bank);
   void addPerson(Person* person) override;

private:
   Bank* bank;
   size_t capacity;
};


#endif //LABO4_RIVER_BOAT_H
