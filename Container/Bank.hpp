#ifndef LABO4_RIVER_BANK_HPP
#define LABO4_RIVER_BANK_HPP

#include "Container.hpp"

/**
 * @brief This class represents a bank.
 * @authors Luca Coduri & Chloé Fontaine
 */
class Bank : public Container {
public:
   /**
    * @brief Construct a new Bank object
    *
    * @param name The name of the bank.
    **/
   explicit Bank(std::string name);

private:
};

#endif // LABO4_RIVER_BANK_HPP
