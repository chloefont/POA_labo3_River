//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_ROBBER_HPP
#define LABO4_RIVER_ROBBER_HPP


#include "Person.hpp"
#include "Cop.hpp"
#include <array>
typedef std::list<Person*> FamilyList;

class Robber : public Person {
   static const bool CAN_DRIVE = false;

public:
   explicit Robber(std::string name, FamilyList family, Cop* cop);
   bool canDrive() const override;
   bool check() const override;
   FamilyList getFamily() const;
   Cop* getCop() const;

private:
   const FamilyList family;
   Cop* cop;
};


#endif //LABO4_RIVER_ROBBER_HPP
