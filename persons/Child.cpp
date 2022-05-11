#include <stdexcept>
#include "Child.hpp"

using namespace std;

Child::Child(string name, Parent *preferredParent, Parent *secondParent,
             Container *actualPosition, ErrorManager *errorManager) :
   Person(std::move(name), actualPosition, errorManager),
   preferredParent(preferredParent), secondParent(secondParent) {

   if (preferredParent == nullptr || secondParent == nullptr) {
      throw invalid_argument("Parent cannot be nullptr");
   }
}

bool Child::check() const {
   if (secondParent->getActualContainer() == getActualContainer() &&
       preferredParent->getActualContainer() != getActualContainer()) {
      if (getErrorManager() != nullptr)
         getErrorManager()->manageError(getName() + " ne peut pas rester sans  "
                                        + preferredParent->getName() + " avec " +
                                        secondParent->getName());
      return false;
   }
   return true;
}

Parent *Child::getPreferredParent() const {
   return preferredParent;
}

Parent *Child::getSecondParent() const {
   return secondParent;
}

bool Child::canDrive() const {
   return CAN_DRIVE;
}
