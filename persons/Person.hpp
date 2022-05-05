//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_PERSON_HPP
#define LABO4_RIVER_PERSON_HPP


#include "../Container/Container.h"

class Person {
   static const bool CAN_DRIVE = true;
   Container* actualContainer = nullptr;

public:
   virtual bool check() const = 0;
   bool move(Container& to) const;
   virtual bool canDrive() const;
   virtual ~Person() = default;
};


#endif //LABO4_RIVER_PERSON_HPP
