#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactIndex(0), _sumContacts(0) {}

void PhoneBook::AddContact(const Contact &contact) {
  _contacts[_contactIndex] = contact;
  _contactIndex = (_contactIndex + 1) % 8;
  if (_sumContacts < 8)
    _sumContacts++;
}
