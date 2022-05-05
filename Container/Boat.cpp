//
// Created by cfont on 05.05.2022.
//

#include "Boat.h"

Boat::Boat(const std::string& name, Bank* bank) : Container(name), bank(bank) {
}

Bank* Boat::getBank() const {
   return bank;
}
