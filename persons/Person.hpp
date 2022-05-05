//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_PERSON_HPP
#define LABO4_RIVER_PERSON_HPP


#include "../Container/Container.h"

class Person {
   Container& actualContainer;

public:
   virtual bool check() const = 0;
   bool move(Container& to) const;

   explicit Person(Container& actualContainer);
   virtual ~Person() = default;
};


#endif //LABO4_RIVER_PERSON_HPP
