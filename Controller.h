//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_CONTROLLER_H
#define LABO4_RIVER_CONTROLLER_H

#include <string>
#include "Container/Bank.h"
#include "Container/Boat.h"
#include "ErrorManager.h"

class Controller : public ErrorManager{
public:
   /**
    * Contructor that initializes the River game.
    */
   Controller();

   /**
    * Start the game.
    */
   void start();

   /**
    * Show the help menu.
    */
   void showMenu() const;

   /**
    * Display the game board.
    */
   void display() const;

private:
   void nextTurn();
   void reset();
   void initPersons();
   void initStateVar();
   static void printMenuRow(const std::string& param, const std::string&
   description);
   void printBoat(Bank* bank) const;
   void printBoundary(char sep) const;
   void executeCommand();
   void manageError(const std::string& message) ;
   bool embark(Person* person);
   bool land(Person* person);
   void moveBoat();
   Person* getPerson(const std::string& name) const;
   void checkGameState();

   int turn;
   bool gameFinished;
   bool gameWon;

   Bank* leftBank;
   Bank* rightBank;
   Boat* boat;
   std::list<Person*> persons;

   const long long GAME_SIZE = 70;
   const size_t BOAT_SIZE = 2;
   char BANK_SEP = '-';
   char RIVER_SEP = '=';
};


#endif //LABO4_RIVER_CONTROLLER_H
