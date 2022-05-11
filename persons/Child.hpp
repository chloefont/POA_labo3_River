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
   Parent* parent1;
   Parent* parent2;

public:


   /**
    * Gets the child's parent1.
    * @return the parent1.
    */
   Parent* getPrefferedParent() const;

   /**
    * Gets the child's parent2
    * @return
    */
   Parent* getSecondParent() const;
   bool canDrive() const override;
   bool check() const override;

protected:
   /**
    * Child constructor.
    * @param name Child's name.
    * @param parent1 Child's preferred parent.
    * @param parent2 Child's second parent.
    * @param actualPosition child's actual position.
    * @param errorManager the error manager.
    */
   Child(std::string name, Parent *parent1, Parent *parent2,
         Container *actualPosition, ErrorManager *errorManager);
};


#endif //LABO4_RIVER_CHILD_H
