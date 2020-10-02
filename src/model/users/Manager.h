/*
 * Manager.h
 *
 *  Created on: 30 Aug 2014
 *      Author: samirtf
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Employee.h"
#include "User.h"

namespace std {

class Manager: public Employee, public User {
public:
	Manager(string name, Sex sex, string username, string password);
	virtual ~Manager();

	virtual string toString();
	friend std::ostream& operator<<(std::ostream& outputStream, Manager const& manager);

	void toDisplay();

};

} /* namespace std */

#endif /* MANAGER_H_ */
