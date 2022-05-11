#include "catch.hpp"
#include "../persons/Son.hpp"
#include "../persons/Daughter.hpp"
#include "../Container/Bank.hpp"
#include "../Container/Boat.hpp"

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

      SECTION("Should return false if alone with father"){
         Father father2("Father", &bankRight, nullptr);
         Daughter daughter2("Daughter", &father2, &mother, &bankRight, nullptr);

         CHECK(false == daughter2.check());
      }

      SECTION("Should return true if not alone with father"){
         CHECK(true == daughter.check());
      }
   }
   SECTION("getFather()") {
      SECTION("Should return father"){
         CHECK(&father == daughter.getFather());
      }
   }

   SECTION( "getMother()" ) {
      SECTION("Should return mother"){
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

   SECTION("Cannot stay with father if mother is not there"){
      SECTION("Mother cannot leave her daughter with father") {
         REQUIRE(mother.move(boat) == false);
      }

      SECTION("Father can leave her daughter with mother"){
         REQUIRE(father.move(boat) == true);
      }
   }

}