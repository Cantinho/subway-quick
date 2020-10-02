/*
 * Drink.cpp
 *
 *  Created on: 1 Sep 2014
 *      Author: samirtf
 */

#include "Drink.h"

using namespace std;

Drink::Drink() {
	setSize(SMALL);
}

Drink::~Drink() { }

DrinkSize Drink::getSize() const
{
	return _size;
}
void Drink::setSize(DrinkSize size)
{
	_size = size;
}


string Drink::toString() {
	std::ostringstream stream;
	stream << "std::Drink::[" << "]" ;
	return stream.str();
}

std::ostream& operator<<(std::ostream& outputStream, Drink const& drink){
    // print it
	return outputStream << "std::Drink[" << "]" ;

}

void Drink::toDisplay()
{
	const char * c_toString = Drink::toString().c_str();
	printf( "%s", c_toString );
}
