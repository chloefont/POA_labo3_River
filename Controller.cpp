//
// Created by cfont on 14.04.2022.
//

#include "Controller.h"
#include "persons/Father.hpp"
#include "persons/Mother.hpp"
#include "persons/Daughter.hpp"
#include "persons/Son.hpp"
#include "persons/Cop.hpp"
#include "persons/Robber.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

Controller::Controller() {
   boat = new Boat("Bateau", leftBank);
   leftBank = new Bank("Gauche");
   rightBank = new Bank("Droite");

   initPersons();
   turn = 0;
   gameFinished = false;

   showMenu();
   display();
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
   executeCommand();
   display();

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
      cout << p->getName() << " ";

   cout << endl;
}

void Controller::printBoat(Bank* bank) const {
   if (bank != boat->getBank()) {
      cout << endl;
      return;
   }

   cout << "Bateau : ";
   for (Person* p : boat->getPersons())
      cout << p->getName() << " ";
   cout << endl;
}

void Controller::printBoundary(char sep) const {
   cout.fill(sep);
   cout.width (gameSize);
   cout << "" << endl;
   cout.fill(' ');
}

void Controller::initPersons() {
   Father* father = new Father("pere");
   Mother* mother = new Mother("mere");
   Daughter* julie = new Daughter("julie", father, mother);
   Daughter* jeanne = new Daughter("jeanne", father, mother);
   Son* paul = new Son("paul", father, mother);
   Son* pierre = new Son("pierre", father, mother);
   Cop* cop = new Cop("policier");
   FamilyList family({father, mother, julie, jeanne, paul, pierre});
   Robber* robber = new Robber("robber", family, cop);

   persons.push_back(father);
   persons.push_back(mother);
   persons.push_back(julie);
   persons.push_back(jeanne);
   persons.push_back(paul);
   persons.push_back(pierre);
   persons.push_back(cop);
   persons.push_back(robber);

   for (Person* p : persons)
      leftBank->addPerson(p);
}

void Controller::executeCommand() {
   string command;
   bool valid = false;

   do {
      cout << turn << "> ";
      cin >> command;

      if (command.length() != 1) {
         printError("commande invalide");
         continue;
      }

      valid = true;
      string personName;

      switch (command[0]) {
         case 'p':
            display();
            break;
         case 'e' : {
            cin >> personName;
            Person* person = getPerson(personName);
            if (person == nullptr) {
               printError("personne introuvable");
               valid = false;
            } else {
               embark(person);
            }
            break;
         }
         case 'd' : {
            cin >> personName;
            Person* person = getPerson(personName);
            if (person == nullptr) {
               printError("personne introuvable");
               valid = false;
            } else {
               embark(person);
            }
            break;
         }
         case 'm':
            moveBoat();
            break;
         case 'r':
            reset();
            break;
         case 'q':
            break;
         case 'h':
            showMenu();
            break;
         default:
            valid = false;
            printError("commande invalide");
      }

   } while (!valid);

}

void Controller::printError(const string &message) {
   cout << "### " << message << endl;
   cin.clear();
   cin.ignore(250, '\n');
}

void Controller::moveBoat() {

}

void Controller::reset() {

}

Person *Controller::getPerson(const string &name) const {
   for (Person* p : persons) {
      if (p->getName() == name)
         return p;
   }

   return nullptr;
}

void Controller::embark(Person *person) {

}

void Controller::land(Person *person) {

}

void Controller::checkGameState() {

}
