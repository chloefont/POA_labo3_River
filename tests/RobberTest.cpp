
#include "catch.hpp"
#include "../persons/Son.hpp"
#include "../persons/Robber.hpp"
#include "../persons/Daughter.hpp"
#include "../Container/Bank.h"
#include "../Container/Boat.h"

TEST_CASE( "Robber" ) {
   Bank bankLeft("Left");
   Bank bankRight("Right");
   Boat boat("Boat", &bankLeft, 2);

   Father father("Father", &bankLeft);
   Mother mother("mother", &bankLeft);
   Son son1("Son1", &father, &mother, &bankLeft);
   Son son2("Son2", &father, &mother, &bankLeft);
   Daughter daughter1("Daughter1", &father, &mother, &bankRight);
   Daughter daughter2("Daughter2", &father, &mother, &bankRight);
   Cop cop("Cop", &bankLeft);
   FamilyList familyList = {
      &father,
      &mother,
      &son1,
      &son2,
      &daughter1,
      &daughter2
   };
   Robber robber("Robber", familyList, &cop, &bankLeft);


   SECTION("Check()"){
      SECTION("Should not throw exception"){
         REQUIRE_NOTHROW(robber.check());
      }

      SECTION("Should return false"){
         CHECK(false == robber.check());
      }

      SECTION("Should return true"){
         CHECK(true == robber.check());
      }
   }

   SECTION( "getFamily()" ) {
      SECTION("Should return the family"){
         CHECK(familyList == robber.getFamily());
      }
   }

   SECTION( "getName()" ) {
      SECTION("Should return father"){
         CHECK("Robber" == robber.getName());
      }
   }

   SECTION( "canDrive()" ) {
      SECTION("Should return false"){
         CHECK(false == robber.canDrive());
      }
   }

   SECTION( "getCop()" ) {
      SECTION("Should return false"){
         CHECK(&cop == robber.getCop());
      }
   }

   SECTION("move()"){
      SECTION("Move to boat should be ok"){
         REQUIRE(robber.move(boat));
      }

      SECTION("Move to right bank should be ok"){
         REQUIRE(robber.move(bankRight));
      }

      SECTION("Move back to left bank should be ok"){
         REQUIRE(robber.move(boat));
         REQUIRE(robber.move(bankLeft));
      }
   }

   SECTION("Cannot be with member of family without policeman"){
      SECTION("Cannot move to boat with member of family") {
         son1.move(boat);
         REQUIRE(robber.move(boat) == true);
      }

      SECTION("Cannot move to right bank with member of family") {
         robber.move(boat);
         cop.move(boat);

         REQUIRE(boat.moveTo(&bankRight) == true);
         REQUIRE(robber.move(bankRight) == false);
      }

      SECTION("Can move to right bank with member of family and policeman") {
         robber.move(boat);
         cop.move(boat);

         REQUIRE(boat.moveTo(&bankRight) == true);
         REQUIRE(cop.move(bankRight) == true);
         REQUIRE(robber.move(bankRight) == true);
      }
   }

}

