//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include "Robber.hpp"
using namespace std;
bool Robber::check() const {

   if(cop->getActualContainer() != getActualContainer()){
      for(Person* member: family) {
         if (member->getActualContainer() == getActualContainer()) {
            if (getErrorManager() != nullptr)
               getErrorManager()->manageError("le voleur ne peut pas etre en contact "
                                           "avec un membre de la famille sans le policier");
            return false;
         }
      }

      return true;
   }

   return true;
}

bool Robber::canDrive() const {
   return CAN_DRIVE;
}

Robber::Robber(std::string name, FamilyList family, Cop* cop, Container *actualPosition, ErrorManager *errorManager) : Person
                                                                   (std::move(name),
                                                                    actualPosition, errorManager), family
                                                                    (std::move(family)), cop(cop) {

}

FamilyList Robber::getFamily() const {
   return family;
}

Cop* Robber::getCop() const {
   return cop;
}



