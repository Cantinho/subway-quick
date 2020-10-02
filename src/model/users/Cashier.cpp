/*
 * Cashier.cpp
 *
 *  Created on: 30 Aug 2014
 *      Author: samirtf
 */

#include <iostream>
#include <sstream>
#include <stdio.h>
#include "Cashier.h"
#include "Employee.h"
#include "User.h"
#include "Sex.h"

using namespace std;

//Cashier::Cashier() {

//}/

Cashier::Cashier(string name, Sex sex, string username, string password)
// explicitly call base-class constructor
: Employee( name, sex ), User(username, password)
{

}

Cashier::~Cashier() { }

string Cashier::toString() {
	std::ostringstream stream;
	stream << "std::Cashier[" << Employee::toString() << ", " << User::toString() << "]" ;
	return stream.str();
}

std::ostream& operator<<(std::ostream& outputStream, Cashier & cashier){
    // print it
	return outputStream << "std::Cashier[" << "???" << "]" ;

}

void Cashier::toDisplay()
{
	const char * c_toString = Cashier::toString().c_str();
	printf( "%s", c_toString );
}

