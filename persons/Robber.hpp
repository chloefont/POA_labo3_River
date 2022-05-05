//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_ROBBER_HPP
#define LABO4_RIVER_ROBBER_HPP


#include "Person.hpp"

class Robber : public Person {
   static const bool CAN_DRIVE = false;

public:
   bool check() const override;
   bool canDrive() const override;
};


#endif //LABO4_RIVER_ROBBER_HPP
