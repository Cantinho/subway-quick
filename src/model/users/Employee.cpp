/*
 * Employee.cpp
 *
 *  Created on: 30 Aug 2014
 *      Author: samirtf
 */

#include "Employee.h"

using namespace std;

Employee::Employee(){
	setName("");
	setSex(_male);
}

Employee::Employee(string name, Sex sex){
	setName(name);
	setSex(sex);
}

Employee::~Employee() { }

string Employee::getName() const
{
	return _name;
}

void Employee::setName(string name)
{
	_name = name;
}

Sex Employee::getSex() const
{
	return _sex;
}

void Employee::setSex(Sex sex)
{
	_sex = sex;
}

string Employee::toString() {
	std::ostringstream stream;
    stream << "std::Employee[name=[" << _name << "], sex=[" << _sex << "]]" ;
    return stream.str();
}

std::ostream& operator<<(std::ostream& outputStream, const Employee& employee) {
	string s = employee.getName();
    // print it
	return outputStream << "std::Employee[name=[" << employee._name << "], sex=[" << employee._sex << "]]" ;
}

void Employee::toDisplay()
{
	const char * c_toString = Employee::toString().c_str();
	printf( "%s", c_toString );
}


