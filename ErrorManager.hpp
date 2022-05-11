#ifndef LABO4_RIVER_ERRORMANAGER_HPP
#define LABO4_RIVER_ERRORMANAGER_HPP

#include <string>

/**
 * @brief This is an interface to manage error messages.
 */
class ErrorManager{
public:
   /**
     * @brief Manage an error
     * @param name The error message.
     **/
    virtual void manageError(const std::string& message) = 0;

    virtual ~ErrorManager() = default;
};

#endif //LABO4_RIVER_ERRORMANAGER_HPP
