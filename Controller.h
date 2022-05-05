//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_CONTROLLER_H
#define LABO4_RIVER_CONTROLLER_H

#include <string>
#include "Container/Bank.h"
#include "Container/Boat.h"

class Controller {
public:
   Controller();
   void showMenu() const;
   void display() const;
   void nextTurn();

private:
   static void printMenuRow(const std::string& param, const std::string&
   description);
   void printContainer(const Container& container) const;
   void printBoat(Bank* bank) const;
   void printBoundary(char sep) const;

   int turn;
   Bank* leftBank = new Bank("Gauche");
   Bank* rightBank = new Bank("Droite");
   Boat* boat;

   int gameSize = 30;
   char BANK_SEP = '-';
   char RIVER_SEP = '=';
};


#endif //LABO4_RIVER_CONTROLLER_H
