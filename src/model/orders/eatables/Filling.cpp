/*
 * Filling.cpp
 *
 *  Created on: 31 Aug 2014
 *      Author: samirtf
 */

#include "Filling.h"

using namespace std;

Filling::Filling() {
	setFlavor("");
	setType(CHEESE);
}

Filling::~Filling() {
	// TODO Auto-generated destructor stub
}

string Filling::getFlavor() const
{
	return _flavor;
}

void Filling::setFlavor(string flavor)
{
	_flavor = flavor;
}

FillingType Filling::getType() const
{
	return _type;
}

void Filling::setType(FillingType type)
{
	_type = type;
}

string Filling::toString() {
	std::ostringstream stream;
	stream << "std::Filling::[" << "]" ;
	return stream.str();
}

std::ostream& operator<<(std::ostream& outputStream, Filling const& filling){
    // print it
	return outputStream << "std::Filling[" << "]" ;

}

void Filling::toDisplay()
{
	const char * c_toString = Filling::toString().c_str();
	printf( "%s", c_toString );
}
