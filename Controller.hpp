#ifndef LABO4_RIVER_CONTROLLER_HPP
#define LABO4_RIVER_CONTROLLER_HPP

#include <string>
#include "Container/Bank.hpp"
#include "Container/Boat.hpp"
#include "ErrorManager.hpp"

class Controller : public ErrorManager{
public:
   /**
    * @brief Contructor that initializes the River game.
    */
   Controller();

   ~Controller() override;

   /**
    * @brief Start the game.
    */
   void start();

   /**
    * @brief Show the help menu.
    */
   void showMenu() const;

   /**
    * @brief Display the game board.
    */
   void display() const;

   void manageError(const std::string& message) override;

private:
   /**
    * @brief Display the game board and execute new command.
    */
   void nextTurn();

   /**
    * @brief Reset game state.
    */
   void reset();

   /**
    * @brief Initialize game's persons.
    */
   void initPersons();

   /**
    * @brief Initialize game state variables.
    */
   void initStateVar();

   /**
    * @brief Print a help menu row with the right format
    *
    * @param param command
    * @param description description of the command
    */
   static void printMenuRow(const std::string& param, const std::string&
   description);

   /**
    * @brief Print the boat if it is next to the given bank.
    *
    * @param bank bank to check
    */
   void printBoat(Bank* bank) const;

   /**
    * @brief Print boundaries of the game board with the given separator.
    *
    * @param sep Character to print as a separator.
    */
   void printBoundary(char sep) const;

   /**
    * @brief Ask the user for a command and execute it.
    */
   void executeCommand();

   /**
    * @brief Embark a person on the boat.
    *
    * @param person Person to embark.
    * @return true if the person could be embarked, false otherwise.
    */
   bool embark(Person* person);

   /**
    * @brief Disembark a person from the boat in its bank.
    *
    * @param person Person to disembark.
    * @return true if the person could be disembarked, false otherwise.
    */
   bool land(Person* person);

   /**
    * @brief Move the boat to the next bank.
    */
   void moveBoat();

   /**
    * @brief Get the person with the given name.
    *
    * @param name Name of the person.
    * @return The person with the given name if found, nullptr otherwise.
    */
   Person* getPerson(const std::string& name) const;

   /**
    * @brief Check if the game is finished.
    */
   void checkGameState();

   /**
    * @brief Delete all persons.
    */
    void deletePersons();

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


#endif //LABO4_RIVER_CONTROLLER_HPP
