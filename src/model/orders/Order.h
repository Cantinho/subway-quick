/*
 * Order.h
 *
 *  Created on: 31 Aug 2014
 *      Author: samirtf
 */


#ifndef ORDER_H_
#define ORDER_H_

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include "OrderItem.h"


namespace std {

class Order {
public:
	Order();
	virtual ~Order();

	int getId() const;
	void setId(int id);

	string getAttendant() const;
	void setAttendant(string attendant);

	string getCashier() const;
	void setCashier(string cashier);

	bool insertOrderItem(OrderItem orderItem);
	OrderItem* removeOrderItem(int orderItemId);
	OrderItem* findOrderItem(int orderItemId);
	int ordersSize();


	virtual string toString();
	friend std::ostream& operator<<(std::ostream& outputStream, const Order& order);

	void toDisplay();

private:
	int _id;
	string _attendant;
	string _cashier;
	vector<OrderItem> _orderItems;
};

} /* namespace std */

#endif /* ORDER_H_ */
