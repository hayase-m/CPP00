#include "Contact.hpp"

bool Contact::SetContact(const std::string &firstName,
                         const std::string &lastName,
                         const std::string &nickName,
                         const std::string &phoneNumber,
                         const std::string &darkestSecret) {
  if (firstName.empty() || lastName.empty() || nickName.empty() ||
      phoneNumber.empty() || darkestSecret.empty())
    return false;
  _firstName = firstName;
  _lastName = lastName;
  _nickName = nickName;
  _phoneNumber = phoneNumber;
  _darkestSecret = darkestSecret;
  return true;
}

std::string Contact::GetFirstName() const { return _firstName; }
std::string Contact::GetLastName() const { return _lastName; }
std::string Contact::GetNickName() const { return _nickName; }
std::string Contact::GetPhoneNumber() const { return _phoneNumber; }
std::string Contact::GetDarkestSecret() const { return _darkestSecret; }