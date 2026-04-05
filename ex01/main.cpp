#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <string>

static std::string readField(const std::string &label) {
  std::string value;
  std::cout << label;
  std::getline(std::cin, value);
  return value;
}

int main(void) {
  PhoneBook phoneBook;
  std::string command = "";

  while (1) {
    std::cout << "Enter a command" << std::endl;
    std::getline(std::cin, command);
    if (command == "ADD") {
      Contact contact;
      std::string firstName = readField("first name: ");
      std::string lastName = readField("last name: ");
      std::string nickName = readField("nick name: ");
      std::string phoneNumber = readField("phone number: ");
      std::string darkestSecret = readField("darkest secret: ");

      if (contact.SetContact(firstName, lastName, nickName, phoneNumber,
                             darkestSecret))
        phoneBook.addContact(contact);
      else
        std::cout << "Empty fields are not allowed" << std::endl;
    } else if (command == "SEARCH") {
      phoneBook.displayAllContacts();
      size_t index;
      char extra;
      std::string indexText = readField("index: ");
      std::istringstream iss(indexText);
      if (!(iss >> index) || (iss >> extra))
        std::cout << "Invalid index" << std::endl;
      else
        phoneBook.displayContact(index);
    } else if (command == "EXIT")
      break;
  }
  return 0;
}
