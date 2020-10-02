/*
 * OrderItem.cpp
 *
 *  Created on: 31 Aug 2014
 *      Author: samirtf
 */

#include "OrderItem.h"

using namespace std;

OrderItem::OrderItem() {
	setId(0);
	setName("");
	setCalories(0);
	setPrice(0.0);
}

OrderItem::~OrderItem() { }


int OrderItem::getId() const
{
	return _id;
}

void OrderItem::setId(int id)
{
	_id = id;
}

string OrderItem::getName() const
{
	return _name;
}

void OrderItem::setName(string name)
{
	_name = name;
}

int OrderItem::getCalories()
{
	return _calories;
}

void OrderItem::setCalories(int calories)
{
	_calories = calories;
}

double OrderItem::getPrice()
{
	return _price;
}

void OrderItem::setPrice(double price)
{
	_price = price;
}

string OrderItem::toString() {
	std::ostringstream stream;
	stream << "std::OrderItem::[" << "]" ;
	return stream.str();
}

std::ostream& operator<<(std::ostream& outputStream, OrderItem const& orderItem){
    // print it
	return outputStream << "std::OrderItem[" << "]" ;

}

void OrderItem::toDisplay()
{
	const char * c_toString = OrderItem::toString().c_str();
	printf( "%s", c_toString );
}
