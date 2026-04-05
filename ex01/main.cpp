#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

static std::string readLine(const std::string &label) {
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
      std::string firstName = readLine("first name ");
      std::string lastName = readLine("last name ");
      std::string nickName = readLine("nick name ");
      std::string phoneNumber = readLine("phone number ");
      std::string darkestSecret = readLine("darkest secret ");

      if (contact.SetContact(firstName, lastName, nickName, phoneNumber,
                             darkestSecret))
        phoneBook.addContact(contact);
      else
        std::cout << "Empty fields are not allowed" << std::endl;
    } else if (command == "SEARCH") {

    } else if (command == "EXIT") {

    } else {
    }
  }
  return 0;
}