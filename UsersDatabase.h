#ifndef USERSDATABASE_H
#define USERSDATABASE_H

#include "User.h"
#include <set>

//  SOURCES = User.cpp UsersDatabase.cpp mainUsersDatabase.cpp UserAdmin.cpp
//  UserEmployee.cpp UserGuest.cpp

// Declaracion anticipada de la cada clase de User
class UserAdmin;
class UserEmployee;
class UserGuest;

class UserPtrComparator {
public:
  bool operator()(const User *us1, const User *us2) const {
    // Comparar dnis de usuarios si tienen el mismo dni no se puede añadir el
    // usuario
    return us1->getNif() < us2->getNif();
  }
};

class UserNameComparator {
public:
  bool operator()(const User *lhs, const User *rhs) const {
    return lhs->getName() < rhs->getName();
  }
};

// UserDatabase:es para controlar todos los usuarios
class UsersDatabase {
public:
  // Constructor por defecto
  // Tengo que hacer un set de usuarios para luego añadirlos con .insert en el
  // metodo setUsers
  explicit UsersDatabase();

  // Destructor
  ~UsersDatabase();

  // Funcion para añadir un usuario al set de usuarios, el set de usuarios es el
  // conjunto de direcciones de memoria, almacena los punteros
  void addUser(const User *user);
  // getUsers devuelve un set de usuarios, getUsers devuelve un set de punteros
  // a usuarios
  std::set<const User *, UserPtrComparator> getUsers() const;
  // setUsers recibe un set de usuarios, setUsers recibe un set de punteros a
  // usuarios
  void setUsers(const std::set<const User *, UserPtrComparator> &users);

  // Ahora se implementan funciones para buscar un usuario por usuario, por
  // nombre, por NIF, por correo electrónico
  User *findUser(const User &user) const;
  User *findUserByName(const std::string name) const;
  User *findUserByNif(const std::string nif) const;
  User *findUserByPassword(const std::string password) const;
  User *findUserByEmail(const std::string email) const;

  // Ahora se implementa la funcion para eliminar un usuario por usuario, por
  // nombre, por NIF, por correo electrónico

  void deleteUser(const User &user);
  void deleteUserByName(const std::string name);
  void deleteUserByNif(const std::string nif);
  void deleteUserByEmail(const std::string email);

  bool isValidPrivileges(const std::string privileges) const;

  // Ahora imprimimos todos los usuarios
  void printUsers() const;

private:
  // Aqui se definen los atributos privados de la clase UsersDatabase
  // Hacer el conjunto de ususarios con set
  std::set<const User *, UserPtrComparator> users_;

  void printDeletedUser(const User *user) const;
};

#endif // UsersDatabase