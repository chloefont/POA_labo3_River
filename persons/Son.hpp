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
    * @param father Son's father.
    * @param mother Son's mother.
    * @param actualPosition Son's actual position
    * @param errorManager The error manager.
    */
   Son(std::string name, Father *father, Mother *mother, Container *actualPosition, ErrorManager *errorManager);
   bool check() const override;
};


#endif //LABO4_RIVER_SON_HPP
