/*
 * Sandwich.h
 *
 *  Created on: 31 Aug 2014
 *      Author: samirtf
 */

#ifndef SANDWICH_H_
#define SANDWICH_H_


#include "../OrderItem.h"
#include "BreadSize.h"
#include "BreadType.h"
#include "Filling.h"
#include <vector>

using namespace std;

class Sandwich: public OrderItem {
public:
	Sandwich();
	virtual ~Sandwich();

	BreadType getType() const;
	void setType(BreadType type);

	BreadSize getSize() const;
	void setSize(BreadSize size);

	bool insertFilling(Filling aFilling);

	virtual int getCalories();

	virtual double getPrice();

	virtual string toString();
	friend std::ostream& operator<<(std::ostream& outputStream, const Sandwich& sandwich);

	virtual void toDisplay();

private:
	BreadType _type;
	BreadSize _size;
	vector<Filling> _fillings;
};


#endif /* SANDWICH_H_ */
