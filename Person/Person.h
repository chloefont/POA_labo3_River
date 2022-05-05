//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_PERSON_H
#define LABO4_RIVER_PERSON_H


#include <string>

class Person {
public:
   Person(const std::string& name);

   std::string getName() const;

private:
   std::string name;
};


#endif //LABO4_RIVER_PERSON_H
