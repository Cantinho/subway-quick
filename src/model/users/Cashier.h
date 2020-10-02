/*
 * Cashier.h
 *
 *  Created on: 30 Aug 2014
 *      Author: samirtf
 */

#ifndef CASHIER_H_
#define CASHIER_H_

#include "Employee.h"
#include "User.h"

using namespace std;

class Cashier: public Employee, public User {
public:
	Cashier(string name, Sex sex, string username, string password);
	virtual ~Cashier();

	virtual string toString();
	friend std::ostream& operator<<(std::ostream& outputStream, Cashier& cashier);

	void toDisplay();
};


#endif /* CASHIER_H_ */
