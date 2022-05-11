//
// Created by luca on 05/05/22.
//

#ifndef LABO4_RIVER_CHILD_H
#define LABO4_RIVER_CHILD_H


#include "Person.hpp"
#include "Father.hpp"
#include "Mother.hpp"

class Child : public Person {
   static const bool CAN_DRIVE = false;
   Father* father;
   Mother* mother;

public:
   /**
    * Child constructor.
    * @param name Child's name.
    * @param father Child's father.
    * @param mother Child's mother.
    * @param actualPosition child's actual position.
    * @param errorManager the error manager.
    */
   Child(std::string name, Father *father, Mother *mother,
         Container *actualPosition, ErrorManager *errorManager);

   /**
    * Gets the child's father.
    * @return the father.
    */
   Father* getFather() const;

   /**
    * Gets the child's mother
    * @return
    */
   Mother* getMother() const;
   bool canDrive() const override;
   bool check() const override;
};


#endif //LABO4_RIVER_CHILD_H
