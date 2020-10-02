/*
 * Drink.h
 *
 *  Created on: 1 Sep 2014
 *      Author: samirtf
 */

#ifndef DRINK_H_
#define DRINK_H_

#include <iostream>
#include <sstream>
#include <stdio.h>
#include "../OrderItem.h"
#include "DrinkSize.h"

using namespace std;

class Drink: public OrderItem {
public:
	Drink();
	virtual ~Drink();

	DrinkSize getSize() const;
	void setSize(DrinkSize drinkSize);


	virtual string toString();
	friend std::ostream& operator<<(std::ostream& outputStream, const Drink& drink);

	void toDisplay();

private:
	DrinkSize _size;
};


#endif /* DRINK_H_ */
