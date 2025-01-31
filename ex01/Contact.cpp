#include "Contact.hpp"

void Contact::setFirstName(const std::string& firstName){
    this->_firstName = firstName;
}

void Contact::setLastName(const std::string& lastName){
    this->_lastName = lastName;
}

void Contact::setNickname(const std::string& nickname){
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber){
    this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret){
    this->_darkestSecret = darkestSecret;
}

const std::string& Contact::getFirstName() const{
    return (_firstName);
}

const std::string& Contact::getLastName() const{
    return (_lastName);
}

const std::string& Contact::getNickname() const{
    return (_nickname);
}

const std::string& Contact::getPhoneNumber() const{
    return (_phoneNumber);
}

const std::string& Contact::getDarkestSecret() const{
    return (_darkestSecret);
}