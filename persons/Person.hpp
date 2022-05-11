//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_PERSON_HPP
#define LABO4_RIVER_PERSON_HPP

class Container;

#include "../Container/Container.h"
#include "../ErrorManager.h"

class Person {
public:
   explicit Person(std::string name, Container *actualPosition, ErrorManager *errorManager);

   virtual ~Person() = default;


   /**
    * @brief It moves the person to the given container.
    * 
    * @param to The container to move to.
    * @return true if the person moved successfully.
    */
   bool move(Container &to);

   /**
    * @brief It tells id the person can drive the boat.
    * 
    * @return true if the person can drive.
    */
   virtual bool canDrive() const;

   /**
    * @brief Get the Name of the peron.
    * 
    * @return the name
    */
   std::string getName() const;

   /**
    * @brief Checks if the person can stay in his container.
    * 
    * @return true if it can.
    */
   virtual bool check() const = 0;

   /**
    * @brief Get the Actual Container where the person is.
    * 
    * @return a container.
    */
   Container* getActualContainer() const;

   /**
    * @brief Get the Error Manager object
    * 
    * @return ErrorManager* 
    */
   ErrorManager* getErrorManager() const;

private:
   static const bool CAN_DRIVE = true;
   Container *actualContainer = nullptr;
   ErrorManager* errorManager = nullptr;
   std::string name;
};


#endif //LABO4_RIVER_PERSON_HPP
