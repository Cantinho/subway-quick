/*
 * GestorSubway.cpp
 *
 *  Created on: 30 Aug 2014
 *      Author: samirtf
 */

#include "GestorSubway.h"
#include <string>
using namespace std;

GestorSubway::GestorSubway() {

}

GestorSubway::~GestorSubway() {
	// TODO Auto-generated destructor stub
}

int GestorSubway::login(string username, string password)
{
	map<string, User>::iterator it = _users.find(username);
	User aUser;
	if( it != _users.end() )
	{
	   //element found;
	   aUser = it->second;

	   if (!aUser.getPassword().compare(password)) {
		       // passwords are equal.
		   _loggedUser = username;
		   return 0;
	   }
	}

	return -1;
}

int GestorSubway::logout()
{
	_loggedUser = "";
	return (_loggedUser.compare(""));
}

string GestorSubway::getLoggedUser()
{
	return _loggedUser;
}

bool GestorSubway::insertEmployee(Employee aEmployee)
{
	for(std::vector<Employee>::iterator it = _employees.begin(); it != _employees.end(); ++it) {
	    /* std::cout << *it; ... */
		cout << (*it).getName() << endl;
		if( (*it).getName().compare(aEmployee.getName()) == 0 ) return false;
	}
	_employees.push_back(aEmployee);
	return true;
}

Employee* GestorSubway::removeEmployee(string name)
{
	Employee aEmployee;
	for(std::vector<Employee>::iterator it = _employees.begin(); it != _employees.end(); ++it) {
	    /* std::cout << *it; ... */
		if( (*it).getName().compare(aEmployee.getName()) == 0 ) {
			aEmployee = *_employees.erase(it);
		}
	}
	return &aEmployee;
}

Employee* GestorSubway::findEmployee(string name)
{
	Employee aEmployee;
	for(std::vector<Employee>::iterator it = _employees.begin(); it != _employees.end(); ++it) {
	    /* std::cout << *it; ... */
		if( (*it).getName().compare(aEmployee.getName()) ) {
			aEmployee = *it;
			return &aEmployee;
		}
	}
	return NULL;
}

int GestorSubway::employeesSize()
{
	return _employees.size();
}

void GestorSubway::displayEmployees()
{
	cout << "Employees List - BEGIN" << endl;
	cout << "Size: " << employeesSize() << endl;
	for(std::vector<Employee>::iterator it = _employees.begin(); it != _employees.end(); ++it) {
	    /* std::cout << *it; ... */
		(*it).toDisplay();
		cout << endl;
	}
	cout << "Employees List - END" << endl;
}

bool GestorSubway::insertUser(string username, User user)
{
	if (_users.find(username) == _users.end() )
	{
	    // key username doesn't exist
		_users.insert(std::pair<string,User>(username, user));
		return true;
	}
	return false;
}

User* GestorSubway::removeUser(string username)
{
    User *aUser;
    std::map<string, User>::iterator it = _users.find (username);

    if (it != _users.end ())
    {
    	aUser = &it->second;
        _users.erase(username);
    } else {
        aUser = NULL;
    }

	return aUser;
}

User* GestorSubway::findUser(string username)
{
	map<string, User>::iterator it = _users.find(username);
	User* aUser;
	if( it != _users.end() )
	{
		//element found;
		aUser = &it->second;
	} else {
		aUser = NULL;
	}
	return aUser;
}

int GestorSubway::usersSize()
{
	return _users.size();
}

void GestorSubway::displayUsers()
{
	cout << "Users List - BEGIN" << endl;
	cout << "Size: " << usersSize() << endl;
	map<string, User>::iterator it = _users.begin();
	User aUser;
	while( it != _users.end() )
	{
	   //element found;
	   aUser = it->second;
	   aUser.toDisplay();
	   cout << endl;
	   it++;
	}
	cout << "Users List - END" << endl;
}



bool GestorSubway::insertOrder(Order order)
{
	for(std::vector<Order>::iterator it = _orders.begin(); it != _orders.end(); ++it) {
	    /* std::cout << *it; ... */
		if( (*it).getId() == order.getId() ) return false;
	}
	_orders.push_back(order);
	return true;
}

Order* GestorSubway::removeOrder(int id)
{
	Order aOrder;
	for(std::vector<Order>::iterator it = _orders.begin(); it != _orders.end(); ++it) {
	    /* std::cout << *it; ... */
		if( (*it).getId() == id ) {
			aOrder = *_orders.erase(it);
		}
	}
	return &aOrder;
}

Order* GestorSubway::findOrder(int id)
{
	Order aOrder;
	for(std::vector<Order>::iterator it = _orders.begin(); it != _orders.end(); ++it) {
	    /* std::cout << *it; ... */
		if( (*it).getId() == id ) {
			aOrder = *it;
			return &aOrder;
		}
	}
	return NULL;
}

int GestorSubway::ordersSize()
{
	return _orders.size();
}

void GestorSubway::displayOrders()
{
	cout << "Orders List - BEGIN" << endl;
	cout << "Size: " << ordersSize() << endl;
	for(std::vector<Order>::iterator it = _orders.begin(); it != _orders.end(); ++it) {
	    /* std::cout << *it; ... */
		(*it).toDisplay();
		cout << endl;
	}
	cout << "Orders List - END" << endl;
}



string GestorSubway::toString() {
	std::ostringstream stream;
	stream << "std::GestorSubway::[";
	for(std::vector<Employee>::iterator it = _employees.begin(); it != _employees.end(); ++it) {
	    /* std::cout << *it; ... */
		stream << (*it).toString();
	}
	stream << "],[";

	map<string, User>::iterator it = _users.begin();
	User aUser;
	if( it != _users.end() )
	{
	   //element found;
	   aUser = it->second;
	   stream << aUser.toString();
	}
	stream << "],[";

	for(std::vector<Order>::iterator it = _orders.begin(); it != _orders.end(); ++it) {
	    /* std::cout << *it; ... */
		stream << (*it).toString();
	}
	stream << "]]";

	return stream.str();
}

std::ostream& operator<<(std::ostream& outputStream, GestorSubway& gestorSubway){
    // print it
	return outputStream << "std::GestorSubway[" << gestorSubway.toString() << "]";
}

void GestorSubway::toDisplay()
{
	const char * c_toString = GestorSubway::toString().c_str();
	printf( "%s", c_toString );
}
