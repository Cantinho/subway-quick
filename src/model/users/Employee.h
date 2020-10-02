/*
 * Employee.h
 *
 *  Created on: 30 Aug 2014
 *      Author: samirtf
 */

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "Sex.h"

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_



using namespace std;

class Employee {
public:
	Employee();
	Employee(string name, Sex sex);
	virtual ~Employee();

	string getName() const;
	void setName(string name);

	Sex getSex() const;
	void setSex(Sex sex);

	virtual string toString();
	friend std::ostream& operator<<(std::ostream& outputStream, const Employee& employee);

	void toDisplay();

private:
	string _name;
	Sex _sex;
};



#endif /* EMPLOYEE_H_ */
