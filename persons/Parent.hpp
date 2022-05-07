//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_PARENT_HPP
#define LABO4_RIVER_PARENT_HPP


#include "Person.hpp"

class Parent: public Person {
public:
   explicit Parent(std::string name);
   bool check() const override;
};


#endif //LABO4_RIVER_PARENT_HPP
