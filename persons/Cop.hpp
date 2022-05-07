//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_COP_H
#define LABO4_RIVER_COP_H


#include "Person.hpp"

class Cop: public Person {
public:
   explicit Cop(std::string name);
   bool check() const override;
};


#endif //LABO4_RIVER_COP_H
