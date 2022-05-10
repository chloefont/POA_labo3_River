//
// Created by cfont on 10.05.2022.
//

#ifndef LABO4_RIVER_ERRORMANAGER_H
#define LABO4_RIVER_ERRORMANAGER_H

#include <string>

class ErrorManager {
public:
    virtual void manageError(const std::string& message) = 0;
};

#endif //LABO4_RIVER_ERRORMANAGER_H
