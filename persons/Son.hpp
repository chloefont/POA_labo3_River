//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_SON_HPP
#define LABO4_RIVER_SON_HPP


#include "Child.hpp"

class Son : public Child {


public:
   /**
    * Son constructor
    * @param name Son's name.
    * @param father Son's preferredParent.
    * @param mother Son's secondParent.
    * @param actualPosition Son's actual position
    * @param errorManager The error manager.
    */
   Son(std::string name, Father *father, Mother *mother, Container *actualPosition, ErrorManager *errorManager);

   Father *getFather() const;

   Mother *getMother() const;
};


#endif //LABO4_RIVER_SON_HPP
