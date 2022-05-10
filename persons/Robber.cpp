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
            //throw runtime_error("le voleur ne peut pas être en contact avec un membre de la famille sans le policier");
      }

      return true;
   }

   return true;
}

bool Robber::canDrive() const {
   return CAN_DRIVE;
}

Robber::Robber(std::string name, FamilyList family, Cop* cop, Container *actualPosition) : Person
                                                                   (std::move(name),
                                                                    actualPosition), family
                                                                    (std::move(family)), cop(cop) {

}

FamilyList Robber::getFamily() const {
   return family;
}

Cop* Robber::getCop() const {
   return cop;
}



