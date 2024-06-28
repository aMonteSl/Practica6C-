#ifndef USERGUEST_H
#define USERGUEST_H

#include "User.h"
#include <string>

// Clase Admin clase hija de Usuario
class UserGuest : public User {
public:
  // Constructor por defecto
  UserGuest();
  // Constructor con parametros
  explicit UserGuest(const std::string name, const std::string nif,
                     std::string password, std::string email);
  // Destructor
  virtual ~UserGuest();
};

#endif // USERGUEST_H