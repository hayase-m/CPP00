#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
  std::string _firstName;
  std::string _lastName;
  std::string _nickName;
  std::string _phoneNumber;
  std::string _darkestSecret;

public:
  bool SetContact(const std::string &firstName, const std::string &lastName,
                  const std::string &nickName, const std::string &phoneNumber,
                  const std::string &darkestSecret);
  std::string GetFirstName() const;
  std::string GetLastName() const;
  std::string GetNickName() const;
  std::string GetPhoneNumber() const;
  std::string GetDarkestSecret() const;
};

#endif // CONTACT_HPP
