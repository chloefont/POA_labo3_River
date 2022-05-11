//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_PARENT_HPP
#define LABO4_RIVER_PARENT_HPP


#include "Person.hpp"

class Parent: public Person {
public:
   /**
    *
    * @param name Parent's name
    * @param actualPosition Parent's actual position
    * @param errorManager The error manager
    */
   explicit Parent(std::string name, Container *actualPosition, ErrorManager *errorManager);
   bool check() const override;
};


#endif //LABO4_RIVER_PARENT_HPP
