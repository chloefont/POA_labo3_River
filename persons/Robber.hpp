#ifndef LABO4_RIVER_ROBBER_HPP
#define LABO4_RIVER_ROBBER_HPP

#include "Person.hpp"
#include "Cop.hpp"
#include <array>

typedef std::list<Person *> FamilyList;

/**
 * @brief This class represents a robber.
 * @authors Luca Coduri & Chloé Fontaine
 */
class Robber : public Person {
   static const bool CAN_DRIVE = false;

public:
   /**
    * @brief Constructor of a robber
    *
    * @param name Name of the robber
    * @param family Family with which the robber cannot be
    * @param cop The cop with which the robber has to be
    * @param actualPosition Actual position of the robber
    * @param errorManager The error manager
    */
   explicit Robber(std::string name, FamilyList family, Cop *cop,
                   Container *actualPosition, ErrorManager *errorManager);

   bool canDrive() const override;

   bool check() const override;

   /**
    * Get the family that the robber can't stay with.
    * @return a list of persons.
    */
   FamilyList getFamily() const;

   /**
    * Get the cop that watch at the robber.
    * @return a cop.
    */
   Cop *getCop() const;

private:
   const FamilyList family;
   Cop *cop;
};


#endif //LABO4_RIVER_ROBBER_HPP
