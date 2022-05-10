//
// Created by cfont on 10.05.2022.
//

#ifndef LABO4_RIVER_ERRORMANAGER_H
#define LABO4_RIVER_ERRORMANAGER_H

#include <string>

/**
 * @brief This is an interface to manage error messages.
 */
class ErrorManager
{
public:
    /**
     * @brief Construct a new ErrorManager object
     * @param name The error message.
     **/
    virtual void manageError(const std::string &message) = 0;
};

#endif // LABO4_RIVER_ERRORMANAGER_H
