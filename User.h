#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
  User();

  explicit User(const std::string name, const std::string nif,
                std::string password, std::string privileges,
                std::string email);

  std::string getName() const;
  std::string getNif() const;
  std::string getPassword() const;
  std::string getPrivileges() const;
  std::string getEmail() const;

  void setName(const std::string name);
  void setNif(const std::string nif);
  void setPassword(const std::string password);
  virtual void setPrivileges(const std::string privileges);
  void setEmail(const std::string email);

  // Reciben como parametro el puntero a un objeto de la clase User y devuelven
  // un booleano
  bool operator<(const User &user) const;
  bool operator>(const User &user) const;
  bool operator==(const User &user) const;
  friend std::ostream &operator<<(std::ostream &os, const User &user);
  friend std::istream &operator>>(std::istream &is, User &user);
  void printUser() const;

  // Destructor
  virtual ~User();

private:
  std::string name;
  std::string nif;
  std::string password;
  std::string privileges;
  std::string email;
};

#endif