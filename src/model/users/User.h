/*
 * User.h
 *
 *  Created on: 30 Aug 2014
 *      Author: samirtf
 */

#ifndef USER_H_
#define USER_H_

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

class User {
public:
	User();
	User(string username);
	User(string username, string password);

	virtual ~User();

	string getUsername() const;
	void setUsername(string username);

	string getPassword() const;
	void setPassword(string password);

	virtual string toString();
	friend std::ostream& operator<<(std::ostream& outputStream, const User& user);

	void toDisplay();

private:
	string _username;
	string _password;
};


#endif /* USER_H_ */


