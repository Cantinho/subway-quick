/*
 * Order.cpp
 *
 *  Created on: 31 Aug 2014
 *      Author: samirtf
 */

#include "Order.h"

using namespace std;

Order::Order() {
	setId(0);
	setAttendant("");
	setCashier("");
}

Order::~Order() {
	// TODO Auto-generated destructor stub
}

int Order::getId() const
{
	return _id;
}

void Order::setId(int id)
{
	_id = id;
}

string Order::getAttendant() const
{
	return _attendant;
}

void Order::setAttendant(string attendant)
{
	_attendant = attendant;
}


string Order::getCashier() const
{
	return _cashier;
}

void Order::setCashier(string cashier)
{
	_cashier = cashier;
}

bool Order::insertOrderItem(OrderItem orderItem)
{
	_orderItems.push_back(orderItem);
	return true;
}

OrderItem* Order::removeOrderItem(int orderItemId)
{
	OrderItem aOrderItem;
	for(std::vector<OrderItem>::iterator it = _orderItems.begin(); it != _orderItems.end(); ++it) {
	    /* std::cout << *it; ... */
		if( (*it).getId() == orderItemId ) {
			aOrderItem = *_orderItems.erase(it);
		}
	}
	return &aOrderItem;
}

OrderItem* Order::findOrderItem(int orderItemId)
{
	OrderItem aOrderItem;
	for(std::vector<OrderItem>::iterator it = _orderItems.begin(); it != _orderItems.end(); ++it) {
	    /* std::cout << *it; ... */
		if( (*it).getId() == orderItemId ) {
			aOrderItem = *(it);
			return &aOrderItem;
		}
	}
	return NULL;
}

int Order::ordersSize()
{
	return _orderItems.size();
}


string Order::toString() {
	std::ostringstream stream;
	stream << "std::Order::[" << "]" ;
	return stream.str();
}

std::ostream& operator<<(std::ostream& outputStream, Order const& order){
    // print it
	return outputStream << "std::Order[" << "]" ;

}

void Order::toDisplay()
{
	const char * c_toString = Order::toString().c_str();
	printf( "%s", c_toString );
}
