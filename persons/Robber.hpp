//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_ROBBER_HPP
#define LABO4_RIVER_ROBBER_HPP


#include "Person.hpp"
#include "Cop.hpp"
#include <array>
typedef std::list<Person*> FamilyList;

class Robber : public Person {
   static const bool CAN_DRIVE = false;

public:
   /**
    *
    * @param name
    * @param family
    * @param cop
    * @param actualPosition
    * @param errorManager
    */
   explicit Robber(std::string name, FamilyList family, Cop* cop, Container *actualPosition, ErrorManager *errorManager);
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
   Cop* getCop() const;

private:
   const FamilyList family;
   Cop* cop;
};


#endif //LABO4_RIVER_ROBBER_HPP
