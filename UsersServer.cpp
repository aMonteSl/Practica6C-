#include "UsersServer.h"

#include <fstream>
#include <iostream>
#include <string>

#include <set>

#include "UsersDatabase.h"

using namespace std;

// Constructor, el sevidor al construirse guardara en su base de datos tres
// usuarios de casa tipo
UsersServer::UsersServer() {
  // Creamos tres usuarios por defecto
  createUser("admin", "12345678X", "admin", "ADMIN", "admin@example.com");
  createUser("employee", "12345678Y", "employee", "EMPLOYEE",
             "employee@example.com");
  createUser("guest", "12345678Z", "guest", "GUEST", "guest@example.com");
}

UsersServer::~UsersServer() {
  // Esto destruira el set de punteros de la base de datos
}

void UsersServer::createUser(const std::string name, const std::string nif,
                             const std::string password,
                             const std::string privileges,
                             const std::string email) {
  // Debe de crear el usuario y añadir el puntero al set de usuarios
  User *user = new User(name, nif, password, privileges, email);
  usersDatabase_.addUser(user);
}

void UsersServer::deleteUser(const std::string nif) {
  usersDatabase_.deleteUserByNif(nif);
}

std::string UsersServer::getPrivileges(std::string nif) {
  User *user = usersDatabase_.findUserByNif(nif);
  if (user != nullptr) {
    return user->getPrivileges();
  } else {
    return "GUEST";
  }
}

bool UsersServer::findUserLogin(std::string name, std::string password,
                                std::string nif) {
  // Debemos de buscar encontrar a un usuario por su nombre, contraseña y nif
  // Si tienen el mismo puntero devolver true, si no false
  if (usersDatabase_.findUserByNif(nif) != nullptr) {
    if (usersDatabase_.findUserByNif(nif)->getName() == name &&
        usersDatabase_.findUserByNif(nif)->getPassword() == password) {
      return true;
    }
  }

  return false;
}

void UsersServer::updateUser(const std::string name, const std::string nif,
                             const std::string password,
                             const std::string privileges,
                             const std::string email) {
  User *userToUpdate = usersDatabase_.findUserByNif(nif);
  // Si el usuario existe, y los privilegios que se quieren cambiar
  // isValidPrivileges entonces se cambian los privilegios y el email
  if (userToUpdate != nullptr && usersDatabase_.isValidPrivileges(privileges)) {
    userToUpdate->setPrivileges(privileges);
    userToUpdate->setEmail(email);
  } else {
    std::cout << "User dosen't change, maybe correct privileges" << std::endl;
  }
}

void UsersServer::printUsersServer() const {
  this->usersDatabase_.printUsers();
}

void UsersServer::loadUsersFromFile() {
  // Cargo los usuarios del archivo
  // Siguiendo el formato de nombre nif password privilegios email
  std::cout << "Loading users from file..." << std::endl;
  std::ifstream file(fileName_);
  if (file.is_open()) {
    std::string name, nif, password, privileges, email;
    while (file >> name >> nif >> password >> privileges >> email) {
      createUser(name, nif, password, privileges, email);
    }
    file.close();
  } else {
    std::cerr << "Error: Unable to open file for reading." << std::endl;
  }
}

void UsersServer::saveUsersToFile() {
  // Guardo los usuarios en el archivo
  std::cout << "Saving users to file..." << std::endl;
  std::ofstream file(fileName_);
  if (file.is_open()) {
    for (const User *user : usersDatabase_.getUsers()) {
      file << user->getName() << " " << user->getNif() << " "
           << user->getPassword() << " " << user->getPrivileges() << " "
           << user->getEmail() << std::endl;
      std::cout << "User saved: " << user->getName() << "-" << user->getNif()
                << std::endl;
    }
    file.close();
  } else {
    std::cerr << "Error: Unable to open file for writing." << std::endl;
  }
}
