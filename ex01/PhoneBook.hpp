#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstddef>
#include <iomanip>
#include <iostream>

class PhoneBook {
private:
  Contact _contacts[8];
  size_t _contactIndex;
  size_t _contactsCount;
  std::string _formatField(const std::string &field);

public:
  PhoneBook();
  void addContact(const Contact &contact);
  void displayAllContacts();
  void displayContact(size_t searchIndex);
};

#endif // PHONEBOOK_HPP
