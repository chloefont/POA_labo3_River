//
// Created by luca on 05/05/22.
//

#ifndef LABO4_RIVER_CHILD_H
#define LABO4_RIVER_CHILD_H


#include "Person.hpp"
#include "Father.hpp"
#include "Mother.hpp"

class Child : public Person {
   static const bool CAN_DRIVE = false;
   Father* father;
   Mother* mother;

public:
   Child(std::string name, Father* father, Mother* mother);
   Father* getFather() const;
   Mother* getMother() const;
   bool canDrive() const override;
   bool check() const override;
};


#endif //LABO4_RIVER_CHILD_H
