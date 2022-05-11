#ifndef LABO4_RIVER_CONTAINER_HPP
#define LABO4_RIVER_CONTAINER_HPP

#include <string>
#include <list>
#include "../persons/Person.hpp"

class Person;

/**
 * @brief Container class contains persons.
 * @authors Luca Coduri & Chloé Fontaine
 */
class Container {
public:
   friend std::ostream &operator<<(std::ostream &os, const Container &dt);


   explicit Container(std::string name);

   virtual ~Container() = default;

   /**
    * @brief Get the Persons in the Container.
    *
    * @return List of persons.
    */
   std::list<Person *> getPersons() const;

   /**
    * @brief Get the Name of the container.
    *
    * @return Containers name.
    */
   std::string getName() const;

   /**
    * @brief Adds a person to the container.
    *
    * @param person The person to add.
    * @return true if the person was added.
    */
   virtual bool addPerson(Person *person);

   /**
    * @brief Check if the person is in the container.
    *
    * @param person The person to check.
    * @return true if the person is in the container.
    */
   bool personInContainer(Person *person) const;

   /**
    * @brief Removes a person from the container.
    *
    * @param person The person to remove.
    */
   void removePerson(Person *person);

   /**
    * @brief Removes all persons from the container.
    */
   void removeAllPersons();

   /**
    * @brief Get the number of persons in the container.
    *
    * @return The number of persons in the container.
    */
   size_t getNbPeople() const;

private:
   std::string name;
   std::list<Person *> persons;
};

#endif // LABO4_RIVER_CONTAINER_HPP
