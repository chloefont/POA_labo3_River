//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_SON_HPP
#define LABO4_RIVER_SON_HPP


#include "Child.hpp"

class Son : public Child {


public:
   Son(std::string name, Father *father, Mother *mother, Container *actualPosition);
   bool check() const override;
};


#endif //LABO4_RIVER_SON_HPP
