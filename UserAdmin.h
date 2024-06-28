#ifndef USERADMIN_H
#define USERADMIN_H

#include "User.h"
#include <string>

// Clase Admin clase hija de Usuario
class UserAdmin : public User {
public:
  // Constructor por defecto
  UserAdmin();
  // Constructor con parametros
  explicit UserAdmin(const std::string name, const std::string nif,
                     std::string password, std::string email);
  // Destructor
  virtual ~UserAdmin();
};

#endif // USERADMIN_H
