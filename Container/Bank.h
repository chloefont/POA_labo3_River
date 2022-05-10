//
// Created by cfont on 05.05.2022.
//

#ifndef LABO4_RIVER_BANK_H
#define LABO4_RIVER_BANK_H

#include "Container.h"

/**
 * @brief This class represents a bank.
 *
 */
class Bank : public Container
{
public:
   /**
    * @brief Construct a new Bank object
    *
    * @param name The name of the bank.
    **/
   explicit Bank(const std::string &name);

private:
};

#endif // LABO4_RIVER_BANK_H
