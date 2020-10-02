/*
 * Filling.h
 *
 *  Created on: 31 Aug 2014
 *      Author: samirtf
 */

#ifndef FILLING_H_
#define FILLING_H_

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "../OrderItem.h"
#include "FillingType.h"

using namespace std;

class Filling: public OrderItem {
public:
	Filling();
	virtual ~Filling();

	string getFlavor() const;
	void setFlavor(string flavor);

	FillingType getType() const;
	void setType(FillingType type);

	virtual string toString();
	friend std::ostream& operator<<(std::ostream& outputStream, const Filling& filling);

	void toDisplay();

private:
	string _flavor;
	FillingType _type;
};


#endif /* FILLING_H_ */
