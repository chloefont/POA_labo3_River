//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_PERSON_HPP
#define LABO4_RIVER_PERSON_HPP

class Container;
#include "../Container/Container.h"

class Person {
public:
   explicit Person(std::string  name);
   virtual bool check() const = 0;
   bool move(Container& to) const;
   virtual bool canDrive() const;
   virtual ~Person() = default;
   std::string getName() const;

private:
   static const bool CAN_DRIVE = true;
   Container* actualContainer = nullptr;
   std::string name;
};


#endif //LABO4_RIVER_PERSON_HPP
