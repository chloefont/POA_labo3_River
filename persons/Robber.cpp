//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include <utility>
#include "Robber.hpp"
using namespace std;
bool Robber::check() const {

   if(cop.getActualContainer() != getActualContainer()){
      for(Person* member: family){
         if(member->getActualContainer() == getActualContainer())
            return false;
      }
   }

   return true;
}

bool Robber::canDrive() const {
   return CAN_DRIVE;
}

Robber::Robber(std::string name, const FamilyArray &family, Cop &cop) : Person
(std::move(name)), family(family), cop(cop) {

}

FamilyArray Robber::getFamily() const {
   return family;
}

Cop &Robber::getCop() const {
   return cop;
}



