#ifndef USEREMPLOYEE_H
#define USEREMPLOYEE_H

#include "User.h"
#include <string>

class UserEmployee : public User {
public:
  // Constructor por defecto
  UserEmployee();
  // Constructor con parametros
  explicit UserEmployee(const std::string name, const std::string nif,
                        std::string password, std::string email);
  // Destructor
  virtual ~UserEmployee();
};

#endif // USEREMPLOYEE_H