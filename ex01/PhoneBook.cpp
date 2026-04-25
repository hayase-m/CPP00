#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactIndex(0), _contactsCount(0) {}

size_t PhoneBook::GetContactsCount() const { return _contactsCount; }

void PhoneBook::AddContact(const Contact &contact) {
  _contacts[_contactIndex] = contact;
  _contactIndex = (_contactIndex + 1) % 8;
  if (_contactsCount < 8)
    _contactsCount++;
}

std::string PhoneBook::_FormatField(const std::string &field) const {
  if (field.length() > 10)
    return field.substr(0, 9) + '.';
  return field;
}

void PhoneBook::DisplayAllContacts() const {
  for (size_t i = 0; i < _contactsCount; i++) {
    std::cout << '|' << std::setw(10) << i << '|' << std::setw(10)
              << _FormatField(_contacts[i].GetFirstName()) << '|'
              << std::setw(10) << _FormatField(_contacts[i].GetLastName())
              << '|' << std::setw(10)
              << _FormatField(_contacts[i].GetNickName()) << '|' << std::endl;
  }
}
void PhoneBook::DisplayContact(size_t searchIndex) const {
  std::cout << _contacts[searchIndex].GetFirstName() << std::endl
            << _contacts[searchIndex].GetLastName() << std::endl
            << _contacts[searchIndex].GetNickName() << std::endl
            << _contacts[searchIndex].GetPhoneNumber() << std::endl
            << _contacts[searchIndex].GetDarkestSecret() << std::endl;
}
