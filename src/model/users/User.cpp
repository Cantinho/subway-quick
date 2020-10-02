/*
 * User.cpp
 *
 *  Created on: 30 Aug 2014
 *      Author: samirtf
 */


#include "User.h"

using namespace std;

User::User() {
	setUsername("admin");
	setPassword("123456");
}

User::User(string username) {
	setUsername(username);
	setPassword("");
}

User::User(string username, string password) {
	setUsername(username);
	setPassword(password);
}

User::~User() { }


void User::setUsername(string username)
{
	_username = username;
}

string User::getUsername() const
{
	return _username;
}

void User::setPassword(string password)
{
	_password = password;
}

string User::getPassword() const
{
	return _password;
}

string User::toString() {
	std::ostringstream stream;
    stream << "std::User[username=[" << _username << "], password=[" << _password << "]]" ;
    return stream.str();
}

std::ostream& operator<<(std::ostream& outputStream, const User& user) {
	string s = user.getUsername();
    // print it
	return outputStream << "std::User[username=[" << user._username << "], password=[" << user._password << "]]" ;
}

void User::toDisplay()
{
	const char * c_toString = User::toString().c_str();
	printf( "%s", c_toString );
}

