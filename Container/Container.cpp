//
// Created by cfont on 05.05.2022.
//

#include "Container.h"
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

Container::Container(std::string name) : name(std::move(name))
{
}

std::list<Person *> Container::getPersons() const
{
   return persons;
}

std::string Container::getName() const
{
   return name;
}

bool Container::addPerson(Person *person)
{
   if (personInContainer(person))
      return false;

   persons.push_back(person);
   return true;
}

void Container::removePerson(Person *person)
{
   persons.remove(person);
}

size_t Container::getNbPeople() const
{
   return persons.size();
}

bool Container::personInContainer(Person *person) const
{
   return find(persons.begin(), persons.end(), person) != persons.end();
}

std::ostream &operator<<(ostream &os, const Container &container)
{
   os << container.getName() << " : ";

   if (container.getPersons().empty())
   {
      os << endl;
      return os;
   }

   for (Person *p : container.getPersons())
      os << p->getName() << " ";

   os << endl;
   return os;
}

void Container::removeAllPersons() {
   persons.clear();
}
