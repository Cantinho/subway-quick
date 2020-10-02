/*
 * GestorSubway.h
 *
 *  Created on: 30 Aug 2014
 *      Author: samirtf
 */

#ifndef GESTORSUBWAY_H_
#define GESTORSUBWAY_H_

#include <string>
#include <map>
#include <vector>
#include "../users/Employee.h"
#include "../users/User.h"
#include "../orders/Order.h"



using namespace std;

class GestorSubway {
public:
	GestorSubway();
	virtual ~GestorSubway();

	int login(string username, string password);
	int logout();
	string getLoggedUser();

	bool insertEmployee(Employee aEmployee);
	Employee* removeEmployee(string name);
	Employee* findEmployee(string name);
	int employeesSize();
	void displayEmployees();

	bool insertUser(string username, User user);
	User* removeUser(string username);
	User* findUser(string username);
	int usersSize();
	void displayUsers();

	bool insertOrder(Order order);
	Order* removeOrder(int id);
	Order* findOrder(int id);
	int ordersSize();
	void displayOrders();


	virtual string toString();
	friend std::ostream& operator<<(std::ostream& outputStream, GestorSubway& gestorSubway);

	void toDisplay();

private:
	string _loggedUser = "";
	vector<Employee> _employees;
	vector<Order> _orders;
	map<string, User> _users;


};

#endif /* GESTORSUBWAY_H_ */
