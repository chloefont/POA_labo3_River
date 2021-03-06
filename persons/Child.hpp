#ifndef LABO4_RIVER_CHILD_H
#define LABO4_RIVER_CHILD_H

#include "Person.hpp"
#include "Father.hpp"
#include "Mother.hpp"

/**
 * @brief This class represents a child.
 * @authors Luca Coduri & Chloé Fontaine
 */
class Child : public Person {
public:
   /**
    * Gets the child's preferred parent.
    * @return the preferredParent.
    */
   Parent* getPreferredParent() const;

   /**
    * Gets the child's second parent
    * @return
    */
   Parent* getSecondParent() const;

   bool canDrive() const override;

   bool check() const override;

protected:
   /**
    * Child constructor.
    * @param name Child's name.
    * @param preferredParent Child's preferred parent.
    * @param secondParent Child's second parent.
    * @param actualPosition child's actual position.
    * @param errorManager the error manager.
    */
   Child(std::string name, Parent *preferredParent, Parent *secondParent,
         Container *actualPosition, ErrorManager *errorManager);

   Child(const Child &child) = delete;

   Child& operator=(const Child &child) = delete;

private:
   static const bool CAN_DRIVE = false;
   Parent* preferredParent;
   Parent* secondParent;
};


#endif //LABO4_RIVER_CHILD_H
