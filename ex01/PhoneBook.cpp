#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactIndex(0), _contactsCount(0) {}

void PhoneBook::addContact(const Contact &contact) {
  _contacts[_contactIndex] = contact;
  _contactIndex = (_contactIndex + 1) % 8;
  if (_contactsCount < 8)
    _contactsCount++;
}

std::string PhoneBook::_formatField(const std::string &field) {
  if (field.length() > 10)
    return field.substr(0, 9) + '.';
  return field;
};

void PhoneBook::displayAllContacts() {
  for (size_t i = 0; i < _contactsCount; i++) {
    std::cout << '|' << std::setw(10) << i << '|' << std::setw(10)
              << _formatField(_contacts[i].GetFirstName()) << '|'
              << std::setw(10) << _formatField(_contacts[i].GetLastName())
              << '|' << std::setw(10)
              << _formatField(_contacts[i].GetNickName()) << '|' << std::endl;
  }
}
void PhoneBook::displayContact(size_t searchIndex) {};