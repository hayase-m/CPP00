#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <string>

static bool ReadField(const std::string &label, std::string &value) {
  if (std::cin.eof())
    return false;
  while (1) {
    std::cout << label;
    if (!std::getline(std::cin, value))
      return false;
    if (!value.empty()) {
      return true;
    }
    std::cout << "Empty fields are not allowed" << std::endl;
  }
}

static bool ReadContact(Contact &contact) {
  std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
  if (!ReadField("first name: ", firstName))
    return false;
  if (!ReadField("last name: ", lastName))
    return false;
  if (!ReadField("nick name: ", nickName))
    return false;
  if (!ReadField("phone number: ", phoneNumber))
    return false;
  if (!ReadField("darkest secret: ", darkestSecret))
    return false;
  contact.SetContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
  return true;
}

static bool ReadIndex(size_t &index, const PhoneBook &phoneBook) {
  if (std::cin.eof())
    return false;
  while (1) {
    char extra;
    std::string indexText;
    std::cout << "index: ";
    if (!std::getline(std::cin, indexText))
      return false;
    if (indexText.empty() || indexText[0] == '-') {
      std::cout << "Invalid index" << std::endl;
      continue;
    }
    std::istringstream iss(indexText);
    if (!(iss >> index) || (iss >> extra) ||
        index >= phoneBook.GetContactsCount()) {
      std::cout << "Invalid index" << std::endl;
      continue;
    }
    return true;
  }
}

int main(void) {
  PhoneBook phoneBook;
  std::string command = "";

  while (1) {
    if (std::cin.eof())
      break;
    std::cout << "Enter a command" << std::endl;
    if (!std::getline(std::cin, command))
      break;
    if (command == "ADD") {
      Contact contact;
      if (!ReadContact(contact))
        break;
      phoneBook.AddContact(contact);
    } else if (command == "SEARCH") {
      if (phoneBook.GetContactsCount() == 0) {
        std::cout << "PhoneBook is empty" << std::endl;
        continue;
      }
      phoneBook.DisplayAllContacts();
      size_t index;
      if (!ReadIndex(index, phoneBook))
        break;
      phoneBook.DisplayContact(index);
    } else if (command == "EXIT")
      break;
  }
  return 0;
}
