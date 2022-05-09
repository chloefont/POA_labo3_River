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
   void start();
   void showMenu() const;
   void showWelcome() const;
   void display() const;
   void nextTurn();

private:
   void reset();
   void initPersons();
   void initStateVar();
   static void printMenuRow(const std::string& param, const std::string&
   description);
   void printContainer(const Container& container) const;
   void printBoat(Bank* bank) const;
   void printBoundary(char sep) const;
   void executeCommand();
   static void printError(const std::string& message) ;
   void embark(Person* person);
   void land(Person* person);
   void moveBoat();
   Person* getPerson(const std::string& name) const;
   void checkGameState();

   int turn;
   bool gameFinished;

   Bank* leftBank;
   Bank* rightBank;
   Boat* boat;
   std::list<Person*> persons;

   const size_t GAME_SIZE = 70;
   const size_t BOAT_SIZE = 2;
   char BANK_SEP = '-';
   char RIVER_SEP = '=';
};


#endif //LABO4_RIVER_CONTROLLER_H
