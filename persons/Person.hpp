//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_PERSON_HPP
#define LABO4_RIVER_PERSON_HPP

class Container;

#include "../Container/Container.h"

class Person {
public:
   explicit Person(std::string name, Container *actualPosition);

   virtual ~Person() = default;

   bool move(Container &to);

   virtual bool canDrive() const;

   std::string getName() const;

   virtual bool check() const = 0;

   Container* getActualContainer() const;

private:
   static const bool CAN_DRIVE = true;
   Container *actualContainer = nullptr;
   std::string name;
};


#endif //LABO4_RIVER_PERSON_HPP
