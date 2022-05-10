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
   leftBank = new Bank("Gauche");
   rightBank = new Bank("Droite");
   boat = new Boat("Bateau", leftBank, BOAT_SIZE);

   initPersons();
   initStateVar();
}

void Controller::start() {
   showMenu();
   while (!gameFinished)
      nextTurn();

   if (gameWon)
      cout << "Felicitations, vous avez gagne !" << endl;
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
   cout << *leftBank;
   printBoundary(BANK_SEP);
   printBoat(leftBank);
   printBoundary(RIVER_SEP);
   printBoat(rightBank);
   printBoundary(BANK_SEP);
   cout << *rightBank;
   printBoundary(BANK_SEP);
}

void Controller::nextTurn() {
   display();
   executeCommand();

   checkGameState();
   turn++;
}

void Controller::printMenuRow(const std::string& param, const std::string&
description) {
   cout << left << setw(8) << param << " : " << description << endl;
}

void Controller::printBoat(Bank* bank) const {
   if (bank != boat->getBank()) {
      cout << endl;
      return;
   }

   cout << *boat;
}

void Controller::printBoundary(char sep) const {
   cout.fill(sep);
   cout.width (GAME_SIZE);
   cout << "" << endl;
   cout.fill(' ');
}

void Controller::initPersons() {
   Father* father = new Father("pere", leftBank, this);
   Mother* mother = new Mother("mere", leftBank, this);
   Daughter* julie = new Daughter("julie", father, mother, leftBank, this);
   Daughter* jeanne = new Daughter("jeanne", father, mother, leftBank, this);
   Son* paul = new Son("paul", father, mother, leftBank, this);
   Son* pierre = new Son("pierre", father, mother, leftBank, this);
   Cop* cop = new Cop("policier", leftBank, this);
   FamilyList family({father, mother, julie, jeanne, paul, pierre});
   Robber* robber = new Robber("robber", family, cop, leftBank, this);

   persons.push_back(father);
   persons.push_back(mother);
   persons.push_back(julie);
   persons.push_back(jeanne);
   persons.push_back(paul);
   persons.push_back(pierre);
   persons.push_back(cop);
   persons.push_back(robber);

}

void Controller::executeCommand() {
   string command;
   bool nextTurn = false;

   do {
      cout << turn << "> ";
      cin >> command;

      if (command.length() != 1) {
         manageError("commande invalide");
         continue;
      }
      string personName;

      switch (command[0]) {
         case 'p':
            display();
            break;
         case 'e' : {
            cin >> personName;
            Person* person = getPerson(personName);
            if (person == nullptr) {
               manageError("personne introuvable");
            } else {
               nextTurn = embark(person);
            }
            break;
         }
         case 'd' : {
            cin >> personName;
            Person* person = getPerson(personName);
            if (person == nullptr) {
               manageError("personne introuvable");
            } else {
               nextTurn = land(person);
            }
            break;
         }
         case 'm':
            moveBoat();
            nextTurn = true;
            break;
         case 'r':
            reset();
            nextTurn = true;
            break;
         case 'q':
            gameFinished = true;
            nextTurn = true;
            break;
         case 'h':
            showMenu();
            break;
         default:
            manageError("commande invalide");
      }

      cin.clear();
      cin.ignore(250, '\n');

   } while (!nextTurn);
}

void Controller::manageError(const string &message) {
   cout << "### " << message << endl;
}

void Controller::moveBoat() {
   if (!boat->moveTo(boat->getBank() == leftBank ? rightBank : leftBank))
      manageError("impossible de déplacer le bateau");
}

void Controller::reset() {
   Container* containers[2] = {boat, rightBank};

   for (Container* c : containers)
      for (Person* p : c->getPersons())
         leftBank->addPerson(p);

   initStateVar();
}

Person *Controller::getPerson(const string &name) const {
   for (Person* p : persons) {
      if (p->getName() == name)
         return p;
   }
   return nullptr;
}

bool Controller::embark(Person *person) {
   // TODO test embarquer qqu sur rive opposée
   if (boat->getBank()->personInContainer(person)) {
      if (person->move(*boat)) {
         return true;
      }

   } else {
      manageError("la personne selectionnee n'est pas sur la bonne rive");
   }

   return false;
}

bool Controller::land(Person *person) {
   if (boat->personInContainer(person)) {
      if (person->move(*boat->getBank())) {
         return true;
      } else {
         manageError("pas possible de deplacer cette personne sur cette rive");
      }

   } else {
      manageError("la personne selectionnee n'est pas sur le bateau");
   }

   return false;
}

void Controller::checkGameState() {
   if (rightBank->getPersons().size() == persons.size()) {
      gameFinished = true;
      gameWon = true;
   }
}

void Controller::initStateVar() {
   turn = 0;
   gameFinished = false;
   gameWon = false;
}

