//
// Created by cfont on 14.04.2022.
//

#include "Controller.h"

#include <iostream>
#include <iomanip>

using namespace std;

Controller::Controller() : boat(new Boat("Bateau", leftBank)) {
}

void Controller::showMenu() const {
   printMenuRow("p", "afficher");
   printMenuRow("e <nom>", "embarquer <nom>");
   printMenuRow("d <nom>", "debarquer <nom>");
   printMenuRow("m", "deplacer bateau");
   printMenuRow("r", "reinitialiser");
   printMenuRow("q", "quitter");
   printMenuRow("h", "menu");
}

void Controller::display() const {
   printBoundary(BANK_SEP);
   printContainer(*leftBank);
   printBoundary(BANK_SEP);
   printBoat(leftBank);
   printBoundary(RIVER_SEP);
   printBoat(rightBank);
   printBoundary(BANK_SEP);
   printContainer(*rightBank);
   printBoundary(BANK_SEP);
}

void Controller::nextTurn() {
   turn++;
}

void Controller::printMenuRow(const std::string& param, const std::string&
description) {
   cout << left << setw(8) << param << " : " << description << endl;
}

void Controller::printContainer(const Container& container) const {
   cout << container.getName() << " : ";

   if (container.getPersons().empty()) {
      cout << endl;
      return;
   }

   for (Person* p : container.getPersons())
      cout << p->getName();

   cout << endl;
}

void Controller::printBoat(Bank* bank) const {
   if (bank == boat->getBank()) {

   }
}

void Controller::printBoundary(char sep) const {
   cout.fill(sep);
   cout.width (gameSize);
   cout << endl;
}
