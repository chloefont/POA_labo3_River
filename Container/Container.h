//
// Created by cfont on 05.05.2022.
//

#ifndef LABO4_RIVER_CONTAINER_H
#define LABO4_RIVER_CONTAINER_H

#include <string>
#include <list>
class Person;
#include "../persons/Person.hpp"


class Container {
public:
   explicit Container(std::string  name);
   std::list<Person*> getPersons() const;
   std::string getName() const;

private:
   std::string name;
   std::list<Person*> persons;
};


#endif //LABO4_RIVER_CONTAINER_H
