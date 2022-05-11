#ifndef LABO4_RIVER_PERSON_HPP
#define LABO4_RIVER_PERSON_HPP

#include "../Container/Container.hpp"
#include "../ErrorManager.hpp"

class Container;

/**
 * @brief This class represents a person. It movements can be restricted
 *        by the check function.
 * @authors Luca Coduri & Chloé Fontaine
 */
class Person {
public:
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
   virtual bool check() const;

   /**
    * @brief Get the Actual Container where the person is.
    * 
    * @return a container.
    */
   Container *getActualContainer() const;

   /**
    * @brief Get the Error Manager object
    * 
    * @return ErrorManager* 
    */
   ErrorManager *getErrorManager() const;

protected:
   /**
    * @brief Constructor of a person.
    *
    * @param name Name of the person.
    * @param actualPosition Container where the person is.
    * @param errorManager The error manager.
    */
   explicit Person(std::string name, Container *actualPosition,
                   ErrorManager *errorManager);

private:
   static const bool CAN_DRIVE = true;
   Container *actualContainer = nullptr;
   ErrorManager *errorManager = nullptr;
   std::string name;
};


#endif //LABO4_RIVER_PERSON_HPP
