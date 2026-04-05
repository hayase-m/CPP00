#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <string>

static bool readField(const std::string &label, std::string &value) {
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

static bool readContact(Contact &contact) {
  std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
  if (!readField("first name: ", firstName))
    return false;
  if (!readField("last name: ", lastName))
    return false;
  if (!readField("nick name: ", nickName))
    return false;
  if (!readField("phone number: ", phoneNumber))
    return false;
  if (!readField("darkest secret: ", darkestSecret))
    return false;
  contact.SetContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
  return true;
}

static bool readIndex(size_t &index, const PhoneBook &phoneBook) {
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
        index >= phoneBook.getContactsCount()) {
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
    std::cout << "Enter a command" << std::endl;
    if (!std::getline(std::cin, command))
      break;
    if (command == "ADD") {
      Contact contact;
      if (!readContact(contact))
        break;
      phoneBook.addContact(contact);
    } else if (command == "SEARCH") {
      if (phoneBook.getContactsCount() == 0) {
        std::cout << "PhoneBook is empty" << std::endl;
        continue;
      }
      phoneBook.displayAllContacts();
      size_t index;
      if (!readIndex(index, phoneBook))
        break;
      phoneBook.displayContact(index);
    } else if (command == "EXIT")
      break;
  }
  return 0;
}
