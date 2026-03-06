#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstddef>

class PhoneBook {
private:
  Contact _contacts[8];
  size_t _contactIndex;
  size_t _sumContacts;

public:
  PhoneBook();
  void AddContact(const Contact &contact);
  Contact ShowContact(size_t searchIndex);
};

#endif // PHONEBOOK_HPP
