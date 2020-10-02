/*
 * OrderItem.h
 *
 *  Created on: 31 Aug 2014
 *      Author: samirtf
 */

#ifndef ORDERITEM_H_
#define ORDERITEM_H_

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

class OrderItem {
public:
	OrderItem();
	virtual ~OrderItem();

	int getId() const;
	void setId(int id);

	string getName() const;
	void setName(string name);

	virtual int getCalories();
	void setCalories(int calories);

	virtual double getPrice();
	void setPrice(double price);

	virtual string toString();
	friend std::ostream& operator<<(std::ostream& outputStream, const OrderItem& orderItem);

	virtual void toDisplay();

private:
	int _id;
	string _name;
	int _calories;
	double _price;
};


#endif /* ORDERITEM_H_ */
