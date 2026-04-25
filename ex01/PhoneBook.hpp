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
  std::string _FormatField(const std::string &field) const;

public:
  PhoneBook();
  size_t GetContactsCount() const;
  void AddContact(const Contact &contact);
  void DisplayAllContacts() const;
  void DisplayContact(size_t searchIndex) const;
};

#endif // PHONEBOOK_HPP
