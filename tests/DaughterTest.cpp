
#include "catch.hpp"
#include "../persons/Son.hpp"
#include "../persons/Daughter.hpp"
#include "../Container/Bank.h"
#include "../Container/Boat.h"

TEST_CASE( "Daughter" ) {
   Bank bankLeft("Left");
   Bank bankRight("Right");
   Boat boat("Boat", &bankLeft, 2);

   Father father("Father", &bankLeft, nullptr);
   Mother mother("Mother", &bankLeft, nullptr);
   Daughter daughter("Daughter", &father, &mother, &bankLeft, nullptr);


   SECTION("Check()"){
      SECTION("Should not throw exception"){
         REQUIRE_NOTHROW(daughter.check());
      }

      SECTION("Should return false"){
         Father father2("Father", &bankRight, nullptr);
         Daughter daughter2("Daughter", &father2, &mother, &bankRight, nullptr);

         CHECK(false == daughter2.check());
      }

      SECTION("Should return true"){
         CHECK(true == daughter.check());
      }
   }
   SECTION( "getFather()" ) {
      SECTION("Should return parent1"){
         CHECK(&father == daughter.getFather());
      }
   }

   SECTION( "getMother()" ) {
      SECTION("Should return parent1"){
         CHECK(&mother == daughter.getMother());
      }
   }

   SECTION( "canDrive()" ) {
      SECTION("Should return false"){
         CHECK(false == daughter.canDrive());
      }
   }

   SECTION( "getName()" ) {
      SECTION("Should return name"){
         CHECK("Daughter" == daughter.getName());
      }
   }

   SECTION("move()"){
      SECTION("Move to boat should be ok"){
         REQUIRE(daughter.move(boat));
      }

      SECTION("Move to right bank should be ok"){
         REQUIRE(daughter.move(bankRight));
      }

      SECTION("Move back to left bank should be ok"){
         REQUIRE(daughter.move(boat));
         REQUIRE(daughter.move(bankLeft));
      }
   }

   SECTION("Cannot stay with parent1 if parent2 is not there"){
      SECTION("Mother cannot leave her daughter with parent1") {
         REQUIRE(mother.move(boat) == false);
      }

      SECTION("Father can leave her daughter with parent2"){
         REQUIRE(father.move(boat) == true);
      }
   }

}