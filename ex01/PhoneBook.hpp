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
  std::string _formatField(const std::string &field) const;

public:
  PhoneBook();
  size_t getContactsCount() const;
  void addContact(const Contact &contact);
  void displayAllContacts() const;
  void displayContact(size_t searchIndex) const;
};

#endif // PHONEBOOK_HPP
