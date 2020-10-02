/*
 * Manager.cpp
 *
 *  Created on: 30 Aug 2014
 *      Author: samirtf
 */

#include "Manager.h"

using namespace std;

Manager::Manager(string name, Sex sex, string username, string password)
// explicitly call base-class constructor
: Employee( name, sex ), User(username, password)
{

}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}

string Manager::toString() {
	std::ostringstream stream;
	stream << "std::Manager[" << Employee::toString() << ", " << User::toString() << "]" ;
	return stream.str();
}

std::ostream& operator<<(std::ostream& outputStream, Manager const& manager){
    // print it
	return outputStream << "std::Manager[" << "???" << "]" ;

}

void Manager::toDisplay()
{
	const char * c_toString = Manager::toString().c_str();
	printf( "%s", c_toString );
}

