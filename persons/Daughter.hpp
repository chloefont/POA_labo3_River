//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_DAUGHTER_HPP
#define LABO4_RIVER_DAUGHTER_HPP


#include "Child.hpp"

class Daughter: public Child {
public:
   Daughter(std::string name, Father* father, Mother* mother);
   bool check() const override;
};


#endif //LABO4_RIVER_DAUGHTER_HPP
