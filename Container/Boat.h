//
// Created by cfont on 05.05.2022.
//

#ifndef LABO4_RIVER_BOAT_H
#define LABO4_RIVER_BOAT_H

#include "Container.h"
#include "Bank.h"

/**
 * @brief This class represents a boat.
 *
 */
class Boat : public Container
{
public:
   /**
    * @brief Construct a new Boat object
    *
    * @param name The name of the boat.
    * @param bank The actual bank where the boat is.
    * @param capacity The capacity of the boat.
    */
   Boat(const std::string &name, Bank *bank, size_t capacity);

   /**
    * @brief Get the Bank where the boat is.
    *
    * @return The bank where the boat is.
    */
   Bank *getBank() const;

   /**
    * @brief Moves the boat to a bank.
    *
    * @param bank The bank where the boat should be moved to.
    * @return true if the boat was moved.
    */
   bool moveTo(Bank *bank);

   bool addPerson(Person *person) override;

private:
   Bank *bank;
   size_t capacity;
};

#endif // LABO4_RIVER_BOAT_H
