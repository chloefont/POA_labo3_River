//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include "Robber.hpp"
using namespace std;
bool Robber::check() const {

   if(cop->getActualContainer() != getActualContainer()){
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

Robber::Robber(std::string name, FamilyList family, Cop* cop) : Person
                                                                   (std::move(name),
                                                                    nullptr), family(std::move(family)), cop(cop) {

}

FamilyList Robber::getFamily() const {
   return family;
}

Cop* Robber::getCop() const {
   return cop;
}



