/*
 * Sandwich.cpp
 *
 *  Created on: 31 Aug 2014
 *      Author: samirtf
 */

#include "Sandwich.h"

using namespace std;

Sandwich::Sandwich() {
	setType(ITALIANO_BRANCO);
	setSize(_15CM);
}

Sandwich::~Sandwich() { }


BreadType Sandwich::getType() const
{
	return _type;
}

void Sandwich::setType(BreadType type)
{
	_type = type;
}

BreadSize Sandwich::getSize() const
{
	return _size;
}

void Sandwich::setSize(BreadSize size)
{
	_size = size;
}

bool Sandwich::insertFilling(Filling aFilling)
{
	_fillings.push_back(aFilling);
	return true;
}

int Sandwich::getCalories()
{
	int totalCalories = OrderItem::getCalories();

	for(std::vector<Filling>::iterator it = _fillings.begin(); it != _fillings.end(); ++it) {
	    /* std::cout << *it; ... */
		totalCalories += (*it).getCalories();

	}

	return totalCalories;
}

double Sandwich::getPrice()
{
	int totalPrice = OrderItem::getPrice();
	for(std::vector<Filling>::iterator it = _fillings.begin(); it != _fillings.end(); ++it) {
	    /* std::cout << *it; ... */
		totalPrice += (*it).getPrice();
	}
	return totalPrice;
}


string Sandwich::toString() {
	std::ostringstream stream;
	stream << "std::Sandwich::[" << "]" ;
	return stream.str();
}

std::ostream& operator<<(std::ostream& outputStream, Sandwich const& sandwich){
    // print it
	return outputStream << "std::Sandwich[" << "]" ;

}

void Sandwich::toDisplay()
{
	const char * c_toString = Sandwich::toString().c_str();
	printf( "%s", c_toString );
}
