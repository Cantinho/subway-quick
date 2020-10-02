//============================================================================
// Name        : SubwayQuick.cpp
// Author      : stf
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "model/manager/GestorSubway.h"
#include "model/orders/Order.h"
#include "model/orders/OrderItem.h"
#include "model/orders/eatables/BreadSize.h"
#include "model/orders/eatables/BreadType.h"
#include "model/orders/eatables/Filling.h"
#include "model/orders/eatables/FillingType.h"
#include "model/orders/eatables/Sandwich.h"


//exception
#include <stdexcept>
#include <exception>
#include <typeinfo>


using namespace std;

const int EXIT = 0;
const int SPLASH_SCREEN = 1;
const int LOGIN_MENU = 2;
const int MAIN_MENU = 3;

const int USER_MENU = 4;
const int EMPLOYEE_MENU = 5;
const int ORDER_MENU = 6;

const int INSERT_USER_MENU = 7;
const int REMOVE_USER_MENU = 8;

const int INSERT_EMPLOYEE_MENU = 9;
const int REMOVE_EMPLOYEE_MENU = 10;

const int INSERT_ORDER_MENU = 11;
const int REMOVE_ORDER_MENU = 12;



int STATE_MENU = 1;

// Criando usuário
User user1;
// Criando gestorSubway global
GestorSubway gestorSubway;



int mainA() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!


	// Criando usuário
	User user1;

	GestorSubway gestorSubway;

	// Realizando login sem ter usuário cadastrado
	cout << gestorSubway.login("admin", "") << endl;

	try {
	    throw 20;
		//cout << gestorSubway.getLoggedUser()->getUsername() << endl;
	}
	catch (int e) {
	    cout << "An exception occurred. Exception Nr. " << e << '\n';
	}



	// Inserindo usuário no sistema
	gestorSubway.insertUser("admin", user1);

	// Realizando login após cadastro de usuário no sistema
	cout << gestorSubway.login("admin", "") << endl;

    cout << gestorSubway.getLoggedUser() << endl;

    cout << "#################################################" << endl;
    cout << endl;
    cout << endl;

    gestorSubway.displayEmployees();
    cout << endl;
    gestorSubway.displayUsers();
    cout << endl;
    gestorSubway.displayOrders();
    cout << endl;
    cout << gestorSubway.toString() << endl;


	return 0;
}





void displaySplahScreen()
{
	do {
		try {
        int entry = 0;
	    cout << endl << "Deseja entrar no sistema? " << endl
             << "1) Sim;" << endl
		     << "2) Nao;" << endl
		     << "3) Sair." << endl;
	    cin >> entry;
	    if( entry < 1 || entry > 3) throw string("Opcao Invalida!!!");
	    if( entry == 2 || entry == 3 ) STATE_MENU = EXIT;
	    if( entry == 1 ) STATE_MENU = LOGIN_MENU;
	    break;
	    std::system("clear");
		} catch (string msg) {
			cout << "Erro detectado:" << msg << endl;
		}
	} while (true);


}

void displayLoginMenu()
{
	int tryCounter = 1;
	do {
        string username = "";
        string password = "";
	    cout << endl << "Digite um nome de usuario: " << endl;
	    cin >> username;
	    cout << endl << "Digite sua senha: " << endl;
	    cin >> password;
	    if( gestorSubway.login(username, password) == 0 ) {
	    	STATE_MENU = MAIN_MENU;
	    	cout << "Login realizado com sucesso." << endl << endl;
	    	break;
	    } else if ( tryCounter >= 3 ) {
	    	cout << "Numero maximo de tentativas foi excedido." << endl << endl;
	    	STATE_MENU = SPLASH_SCREEN;
	    	break;
	    } else {
	    	cout << "Nao foi possivel realizar login no sistema.\n" <<
	    			"Confira suas credenciais." << endl << endl;
	    	tryCounter++;
	    }
	} while (true);


}

void displayMainMenu()
{

	do {
		try {
	       int entry = 0;
		   cout << endl << "Deseja entrar em qual menu? " << endl
	            << "1) Menu de Usuarios;" << endl
			    << "2) Menu de Empregados;" << endl
			    << "3) Menu de Pedidos;" << endl
			    << "4) Sair do sistema." << endl;
		   cin >> entry;
		   if( entry < 1 || entry > 4) throw string("Opcao Invalida!!!");
		   if( entry == 1 ) {
			   STATE_MENU = USER_MENU;
		   }
		   else if( entry == 2 ) {
			   STATE_MENU = EMPLOYEE_MENU;
		   }
		   else if( entry == 3 ) {
			   STATE_MENU = ORDER_MENU;
		   }
		   else if( entry == 4 ) {
			   gestorSubway.logout();
			   STATE_MENU = SPLASH_SCREEN;
		   }
		   break;
		   std::system("clear");
		} catch (string msg) {
				cout << "Erro detectado:" << msg << endl;
		}
	} while (true);


}

void displayUserMenu()
{
	do {
		try {
	       int entry = 0;
		   cout << endl << "Deseja realizar que tarefa? " << endl
	            << "1) Cadastrar Usuario;" << endl
			    << "2) Remover Usuario;" << endl
			    << "3) Listar Usuarios;" << endl
			    << "4) Voltar." << endl;
		   cin >> entry;
		   if( entry < 1 || entry > 4) throw string("Opcao Invalida!!!");
		   if( entry == 1 ) {
			   STATE_MENU = INSERT_USER_MENU;
		   }
		   else if( entry == 2 ) {
			   STATE_MENU = REMOVE_USER_MENU;
		   }
		   else if( entry == 3 ) {
			   gestorSubway.displayUsers();
		   }
		   else if( entry == 4 ) {
			   STATE_MENU = MAIN_MENU;
		   }
		   break;
		   std::system("clear");
		} catch (string msg) {
				cout << "Erro detectado:" << msg << endl;
		}
	} while (true);
}


void displayEmployeeMenu()
{
	do {
		try {
	       int entry = 0;
		   cout << endl << "Deseja realizar que tarefa? " << endl
	            << "1) Cadastrar Empregado;" << endl
			    << "2) Remover Empregado;" << endl
			    << "3) Listar Empregados;" << endl
			    << "4) Voltar." << endl;
		   cin >> entry;
		   if( entry < 1 || entry > 4) throw string("Opcao Invalida!!!");
		   if( entry == 1 ) {
			   STATE_MENU = INSERT_EMPLOYEE_MENU;
		   }
		   else if( entry == 2 ) {
			   STATE_MENU = REMOVE_EMPLOYEE_MENU;
		   }
		   else if( entry == 3 ) {
			   gestorSubway.displayEmployees();
		   }
		   else if( entry == 4 ) {
			   STATE_MENU = MAIN_MENU;
		   }
		   break;
		   std::system("clear");
		} catch (string msg) {
				cout << "Erro detectado:" << msg << endl;
		}
	} while (true);

}


void displayOrderMenu()
{
	do {
		try {
	       int entry = 0;
		   cout << endl << "Deseja realizar que tarefa? " << endl
	            << "1) Cadastrar Pedido;" << endl
			    << "2) Remover Pedido;" << endl
			    << "3) Listar Pedidos;" << endl
			    << "4) Voltar." << endl;
		   cin >> entry;
		   if( entry < 1 || entry > 4) throw string("Opcao Invalida!!!");
		   if( entry == 1 ) {
			   STATE_MENU = INSERT_ORDER_MENU;
		   }
		   else if( entry == 2 ) {
			   STATE_MENU = REMOVE_ORDER_MENU;
		   }
		   else if( entry == 3 ) {
			   gestorSubway.displayOrders();
		   }
		   else if( entry == 4 ) {
			   STATE_MENU = MAIN_MENU;
		   }
		   break;
		   std::system("clear");
		} catch (string msg) {
				cout << "Erro detectado:" << msg << endl;
		}
	} while (true);

}


void displayInsertUserMenu()
{
	cout << "Insert User Menu" << endl << endl;
	do {
        string username = "";
        string password = "";
	    cout << endl << "Digite um nome de usuario: " << endl;
	    cin >> username;
	    cout << endl << "Digite sua senha: " << endl;
	    cin >> password;

	    User newUser(username, password);
	    if( gestorSubway.insertUser(username, newUser) ) {
	    	STATE_MENU = USER_MENU;
	    	cout << "Usuario cadastrado com sucesso." << endl << endl;
	    } else {
	    	cout << "Nao foi possivel cadastrar usuario.\n" <<
	    			"Tente novamente." << endl << endl;
	    	STATE_MENU = USER_MENU;
	    }
	    break;
	} while (true);

}

void displayRemoveUserMenu()
{
	cout << "Remove User Menu" << endl << endl;

    string username = "";
	cout << endl << "Digite um nome de usuario a ser removido: " << endl;
	cin >> username;
	if( gestorSubway.removeUser(username) != NULL ) {
		cout << "Usuario removido com sucesso" << endl << endl;
	} else {
		cout << "Usuario nao encontrado." << endl << endl;
	}
  	STATE_MENU = USER_MENU;

}


void displayInsertEmployeeMenu()
{
	cout << "Insert Employee Menu" << endl << endl;

    string name = "";
    string sex = "";
	cout << endl << "Digite um nome de empregado: " << endl;
	cin >> name;
	cout << endl << "Digite o sexo: M (padrao) ou F: " << endl;
	cin >> sex;

	Sex sexType = _male;
	if (sex.compare("F")) {
		sexType = _female;
	}

	Employee newEmployee(name, sexType);
	if( gestorSubway.insertEmployee(newEmployee) ) {

	    	cout << "Empregado cadastrado com sucesso." << endl << endl;
	} else {
	    	cout << "Nao foi possivel cadastrar empregado.\n" <<
	    			"Tente novamente." << endl << endl;

	}
    STATE_MENU = EMPLOYEE_MENU;


}

void displayRemoveEmployeeMenu()
{
	cout << "Remove Employee Menu" << endl << endl;

    string name = "";
	cout << endl << "Digite um nome de usuario a ser removido: " << endl;
	cin >> name;
	if( gestorSubway.removeEmployee(name) != NULL ) {
		cout << "Empregado removido com sucesso" << endl << endl;
	} else {
		cout << "Empregado nao encontrado." << endl << endl;
	}
  	STATE_MENU = EMPLOYEE_MENU;

}





int orderId = 1;
void displayInsertOrderMenu()
{
	cout << "Insert Order Menu" << endl << endl;

	Order newOrder;
	newOrder.setId(orderId);
	newOrder.setAttendant(gestorSubway.getLoggedUser());
	newOrder.setCashier(gestorSubway.getLoggedUser());

	const int ORDER = 1;
	const int COMBO = 2;
	int orderType = 0;

	bool success = false;

	do {
		try {
	       int entry = 0;
		   cout << endl << "Digite sua opcao: " << endl
	            << "1) Pedido;" << endl
			    << "2) Combo;" << endl
			    << "3) Sair." << endl;
		   cin >> entry;
		   if( entry < 1 || entry > 3) throw string("Opcao Invalida!!!");
		   if( entry == 1 ) {
			   orderType = ORDER;
		   }
		   else if( entry == 2 ) {
			   orderType = COMBO;
		   }
		   else if( entry == 3 ) {
			   STATE_MENU = ORDER_MENU;
		   }
		   break;
		   std::system("clear");
		} catch (string msg) {
				cout << "Erro detectado:" << msg << endl;
		}
	} while (true);

	if ( STATE_MENU == ORDER_MENU ) return;


	cout << "Vamos comecar escolhendo um dos nossos deliciosos paes." << endl << endl;

	Sandwich newSandwich;
	int orderItemId = 1;
	int fillingId = 1;

	// ORDER TYPE
	do {
		try {
	        int entry = 0;
		    cout << endl
			 	 << "1)  Iltaliano Branco         (15cm)    - Preço: R$ 0,60" << endl
		 		 << "2)  Iltaliano Branco         (30cm)    - Preco: R$ 1,00" << endl
	 			 << "3)  9 Graos                  (15cm)    - Preco: R$ 0,80" << endl
				 << "4)  9 Graos                  (30cm)    - Preco: R$ 1,20" << endl
				 << "5)  Parmesao e Oregano       (15cm)    - Preco: R$ 1,00" << endl
				 << "6)  Parmesao e Oregano       (30cm)    - Preço: R$ 1,40" << endl
				 << "7)  Tres Queijos             (15cm)    - Preco: R$ 1,20" << endl
				 << "8)  Tres Queijos             (30cm)    - Preco: R$ 1,60" << endl
				 << "9)  9 Graos com Aveia e Mel  (15cm)    - Preco: R$ 1,40" << endl
				 << "10) 9 Graos com Aveia e Mel  (30cm)    - Preco: R$ 1,80" << endl;
		    cin >> entry;
		    if( entry < 1 || entry > 10) throw string("Opcao Invalida!!!");
		    if( entry == 1 ) {
			    newSandwich.setName("Iltaliano Branco         (15cm)");
			    newSandwich.setPrice(0.60);
			    newSandwich.setType(ITALIANO_BRANCO);
			    newSandwich.setSize(_15CM);
			    newSandwich.setCalories(150);
		    }
		    else if( entry == 2 ) {
				newSandwich.setName("Iltaliano Branco         (30cm)");
				newSandwich.setPrice(1.00);
				newSandwich.setType(ITALIANO_BRANCO);
				newSandwich.setSize(_30CM);
				newSandwich.setCalories(300);
		    }
		    else if( entry == 3 ) {
				newSandwich.setName("9 Graos         (15cm)");
				newSandwich.setPrice(0.80);
				newSandwich.setType(NOVE_GRAOS);
				newSandwich.setSize(_15CM);
				newSandwich.setCalories(160);
		    }
		    else if( entry == 4 ) {
				newSandwich.setName("9 Graos         (30cm)");
				newSandwich.setPrice(1.20);
				newSandwich.setType(NOVE_GRAOS);
				newSandwich.setSize(_30CM);
				newSandwich.setCalories(320);
		    }
		    else if( entry == 5 ) {
				newSandwich.setName("Parmesao e Oregano         (15cm)");
				newSandwich.setPrice(1.00);
				newSandwich.setType(PARMESAO_E_OREGANO);
				newSandwich.setSize(_15CM);
				newSandwich.setCalories(120);
		    }
		    else if( entry == 6 ) {
				newSandwich.setName("Parmesao e Oregano         (30cm)");
				newSandwich.setPrice(1.40);
				newSandwich.setType(PARMESAO_E_OREGANO);
				newSandwich.setSize(_30CM);
				newSandwich.setCalories(240);
		    }
		    else if( entry == 7 ) {
				newSandwich.setName("Tres Queijos         (15cm)");
				newSandwich.setPrice(1.20);
				newSandwich.setType(TRES_QUEIJOS);
				newSandwich.setSize(_15CM);
				newSandwich.setCalories(150);
		    }
		    else if( entry == 8 ) {
				newSandwich.setName("Tres Queijos         (30cm)");
				newSandwich.setPrice(1.60);
				newSandwich.setType(TRES_QUEIJOS);
				newSandwich.setSize(_30CM);
				newSandwich.setCalories(300);
		    }
		    else if( entry == 9 ) {
				newSandwich.setName("9 Graos com Aveia e Mel         (15cm)");
				newSandwich.setPrice(1.40);
				newSandwich.setType(TRES_QUEIJOS);
				newSandwich.setSize(_15CM);
				newSandwich.setCalories(110);
		    }
		    else if( entry == 10 ) {
				newSandwich.setName("9 Graos com Aveia e Mel         (30cm)");
				newSandwich.setPrice(1.80);
				newSandwich.setType(TRES_QUEIJOS);
				newSandwich.setSize(_30CM);
				newSandwich.setCalories(220);
		    }
		    newSandwich.setId(orderItemId);


		    //adiciona item pao no pedido
		    newOrder.insertOrderItem(newSandwich);

		    //incrementa ordem id
		    orderItemId++;

		    break;
		    std::system("clear");
		} catch (string msg) {
				cout << "Erro detectado:" << msg << endl;
		}
	} while (true);




	// Colocando recheio no sanduiche
	Filling newFilling;

	do {
		try {
	        int entry = 0;
		    cout << endl
		    	 << "1) Frango Defumado com Cream Cheese          - Preco: R$ 2,90" << endl
		    	 << "2) Atum                                      - Preco: R$ 2,50" << endl
		    	 << "3) Steak de Carne Sabor Churrasco            - Preco: R$ 2,30" << endl
		    	 << "4) Frango Teriyaki                           - Preco: R$ 2,60" << endl
		    	 << "5) Vegetariano                               - Preco: R$ 1,90" << endl
		    	 << "6) Almondegas                                - Preco: R$ 2,20" << endl
		    	 << "7) Rosbife                                   - Preco: R$ 3,00" << endl
		    	 << "8) Frango                                    - Preco: R$ 2,00" << endl;
		    cin >> entry;
		    if( entry < 1 || entry > 8) throw string("Opcao Invalida!!!");
		    if( entry == 1 ) {
		    	newFilling.setName("Frango Defumado com Cream Cheese");
		    	newFilling.setPrice(2.90);
		    	newFilling.setFlavor("Frango Defumado com Cream Cheese");
		    	newFilling.setType(FILLING);
		    	newFilling.setCalories(150);
		    }
		    else if( entry == 2 ) {
		    	newFilling.setName("Atum");
		    	newFilling.setPrice(2.50);
		    	newFilling.setFlavor("Atum");
		    	newFilling.setType(FILLING);
		    	newFilling.setCalories(180);
		    }
		    else if( entry == 3 ) {
		    	newFilling.setName("Steak de Carne Sabor Churrasco");
		    	newFilling.setPrice(2.30);
		    	newFilling.setFlavor("Steak de Carne Sabor Churrasco");
		    	newFilling.setType(FILLING);
		    	newFilling.setCalories(220);
		    }
		    else if( entry == 4 ) {
		    	newFilling.setName("Frango Teriyaki");
		    	newFilling.setPrice(2.60);
		    	newFilling.setFlavor("Frango Teriyaki");
		    	newFilling.setType(FILLING);
		    	newFilling.setCalories(270);
		    }
		    else if( entry == 5 ) {
		    	newFilling.setName("Vegetariano");
		    	newFilling.setPrice(1.90);
		    	newFilling.setFlavor("Vegetariano");
		    	newFilling.setType(FILLING);
		    	newFilling.setCalories(120);
		    }
		    else if( entry == 6 ) {
		    	newFilling.setName("Almondegas");
		    	newFilling.setPrice(2.20);
		    	newFilling.setFlavor("Almondegas");
		    	newFilling.setType(FILLING);
		    	newFilling.setCalories(280);
		    }
		    else if( entry == 7 ) {
		    	newFilling.setName("Rosbife");
		    	newFilling.setPrice(3.00);
		    	newFilling.setFlavor("Rosbife");
		    	newFilling.setType(FILLING);
		    	newFilling.setCalories(320);
		    }
		    else if( entry == 8 ) {
		    	newFilling.setName("Frango");
		    	newFilling.setPrice(2.00);
		    	newFilling.setFlavor("Frango");
		    	newFilling.setType(FILLING);
		    	newFilling.setCalories(220);
		    }
		    newFilling.setId(fillingId);


		    //adiciona recheio no pao
		    newSandwich.insertFilling(newFilling);

		    //incrementa ordemItemId
		    fillingId++;

		    break;
		    std::system("clear");
		} catch (string msg) {
				cout << "Erro detectado:" << msg << endl;
		}
	} while (true);


	// Adicionando queijos no pao
	Filling newCheeseFilling;

	do {
		try {
	        int entry = 0;
		    cout << endl
		    	 << "1) Cheddar         						  - Preco: R$ 0,80" << endl
		    	 << "2) Suico                                     - Preco: R$ 1,00" << endl
		    	 << "3) Prato            						  - Preco: R$ 0,50" << endl;
		    cin >> entry;
		    if( entry < 1 || entry > 3) throw string("Opcao Invalida!!!");
		    if( entry == 1 ) {
		    	newCheeseFilling.setName("Cheddar");
		    	newCheeseFilling.setPrice(0.80);
		    	newCheeseFilling.setFlavor("Cheddar");
		    	newCheeseFilling.setType(CHEESE);
		    	newCheeseFilling.setCalories(120);
		    }
		    else if( entry == 2 ) {
		    	newCheeseFilling.setName("Suico");
		    	newCheeseFilling.setPrice(1.00);
		    	newCheeseFilling.setFlavor("Suico");
		    	newCheeseFilling.setType(CHEESE);
		    	newCheeseFilling.setCalories(150);
		    }
		    else if( entry == 3 ) {
		    	newCheeseFilling.setName("Prato");
		    	newCheeseFilling.setPrice(0.50);
		    	newCheeseFilling.setFlavor("Prato");
		    	newCheeseFilling.setType(CHEESE);
		    	newCheeseFilling.setCalories(175);
		    }
		    newCheeseFilling.setId(fillingId);


		    //adiciona recheio de queijo no pao
		    newSandwich.insertFilling(newCheeseFilling);

		    //incrementa ordemItemId
		    fillingId++;

		    break;
		    std::system("clear");
		} catch (string msg) {
				cout << "Erro detectado:" << msg << endl;
		}
	} while (true);



	// Adiciona "adicionais" no pao
	Filling newAdditionalFilling;

	do {
		try {
	        int entry = 0;
		    cout << endl
		    	 << "1) Bacon                                  - Preco: R$ 1,50" << endl
		    	 << "2) Tomate Seco                            - Preco: R$ 1,70" << endl
		    	 << "3) Cream Cheese                           - Preco: R$ 1,30" << endl
		    	 << "4) Sem Adicional                          - Preco: R$ 0,00" << endl;
		    cin >> entry;
		    if(entry == 4) break;

		    if( entry < 1 || entry > 14) throw string("Opcao Invalida!!!");
		    if( entry == 1 ) {
		    	newAdditionalFilling.setName("Bacon");
		    	newAdditionalFilling.setPrice(1.50);
		    	newAdditionalFilling.setFlavor("Bacon");
		    	newAdditionalFilling.setType(ADDITIONAL);
		    	newAdditionalFilling.setCalories(120);
		    }
		    else if( entry == 2 ) {
		    	newAdditionalFilling.setName("Tomate Seco");
		    	newAdditionalFilling.setPrice(1.70);
		    	newAdditionalFilling.setFlavor("Tomate Seco");
		    	newAdditionalFilling.setType(ADDITIONAL);
		    	newAdditionalFilling.setCalories(150);
		    }
		    else if( entry == 3 ) {
		    	newAdditionalFilling.setName("Cream Cheese");
		    	newAdditionalFilling.setPrice(1.30);
		    	newAdditionalFilling.setFlavor("Cream Cheese");
		    	newAdditionalFilling.setType(ADDITIONAL);
		    	newAdditionalFilling.setCalories(175);
		    }
		    newAdditionalFilling.setId(fillingId);


		    //adiciona recheio de queijo no pao
		    newSandwich.insertFilling(newAdditionalFilling);

		    //incrementa ordemItemId
		    fillingId++;

		    break;
		    std::system("clear");
		} catch (string msg) {
				cout << "Erro detectado:" << msg << endl;
		}
	} while (true);


	// Adicionando vegetais no pao
	Filling newVegetablesFilling;

	do {
		try {
	        int entry = 0;
		    cout << endl
		    	 << "1) Tropical         						      - Preco: R$ 1,50" << endl
		    	 << "2) Light                                    	  - Preco: R$ 1,00" << endl
		    	 << "3) Sem salada            						  - Preco: R$ 0,00" << endl;
		    cin >> entry;
		    if(entry == 3) break;

		    if( entry < 1 || entry > 3) throw string("Opcao Invalida!!!");
		    if( entry == 1 ) {
		    	newVegetablesFilling.setName("Tropical");
		    	newVegetablesFilling.setPrice(1.50);
		    	newVegetablesFilling.setFlavor("Tropical");
		    	newVegetablesFilling.setType(VEGETABLE);
		    	newVegetablesFilling.setCalories(70);
		    }
		    else if( entry == 2 ) {
		    	newVegetablesFilling.setName("Light");
		    	newVegetablesFilling.setPrice(1.70);
		    	newVegetablesFilling.setFlavor("Light");
		    	newVegetablesFilling.setType(VEGETABLE);
		    	newVegetablesFilling.setCalories(50);
		    }
		    newVegetablesFilling.setId(fillingId);


		    //adiciona recheio de queijo no pao
		    newSandwich.insertFilling(newVegetablesFilling);

		    //incrementa ordemItemId
		    fillingId++;

		    break;
		    std::system("clear");
		} catch (string msg) {
				cout << "Erro detectado:" << msg << endl;
		}
	} while (true);






	// Adicionando temperos no pao
	Filling newSpicesFilling;

	do {
		try {
	        int entry = 0;
		    cout << endl
		    	 << "1) Sal           						          - Preco: R$ 0.00" << endl
		    	 << "2) Vinagre                                    	  - Preco: R$ 0,00" << endl
		    	 << "3) Azeite                                    	  - Preco: R$ 0,00" << endl
		    	 << "4) Sem tempero            						  - Preco: R$ 0,00" << endl;
		    cin >> entry;
		    if(entry == 4) break;

		    if( entry < 1 || entry > 4) throw string("Opcao Invalida!!!");
		    if( entry == 1 ) {
		    	newSpicesFilling.setName("Sal");
		    	newSpicesFilling.setPrice(0.0);
		    	newSpicesFilling.setFlavor("Sal");
		    	newSpicesFilling.setType(SPICES);
		    	newSpicesFilling.setCalories(10);
		    }
		    else if( entry == 2 ) {
		    	newSpicesFilling.setName("Vinagre");
		    	newSpicesFilling.setPrice(0.0);
		    	newSpicesFilling.setFlavor("Vinagre");
		    	newSpicesFilling.setType(SPICES);
		    	newSpicesFilling.setCalories(30);
		    }
		    else if( entry == 3 ) {
		    	newSpicesFilling.setName("Azeite");
		    	newSpicesFilling.setPrice(0.0);
		    	newSpicesFilling.setFlavor("Azeite");
		    	newSpicesFilling.setType(SPICES);
		    	newSpicesFilling.setCalories(40);
		    }
		    newSpicesFilling.setId(fillingId);


		    //adiciona recheio de queijo no pao
		    newSandwich.insertFilling(newSpicesFilling);

		    //incrementa ordemItemId
		    fillingId++;

		    break;
		    std::system("clear");
		} catch (string msg) {
				cout << "Erro detectado:" << msg << endl;
		}
	} while (true);





	// Adicionando molhos no pao
	Filling newSaucesFilling;

	do {
		try {
	        int entry = 0;
		    cout << endl
		    	 << "1) Mostarda e Mel                             - Preco: R$ 1,00" << endl
		    	 << "2) Cebola Agridoce                            - Preco: R$ 1,00" << endl
		    	 << "3) Barbecue                                   - Preco: R$ 1,00" << endl
		    	 << "4) Parmesao                                   - Preco: R$ 1,00" << endl
		    	 << "5) Chipotle                                   - Preco: R$ 1,00" << endl
		    	 << "6) Sem Molho                                  - Preco: R$ 0,00" << endl;
		    cin >> entry;
		    if(entry == 6) break;

		    if( entry < 1 || entry > 6) throw string("Opcao Invalida!!!");
		    if( entry == 1 ) {
		    	newSaucesFilling.setName("Mostarda e Mel");
		    	newSaucesFilling.setPrice(1.0);
		    	newSaucesFilling.setFlavor("Mostarda e Mel");
		    	newSaucesFilling.setType(SAUCES);
		    	newSaucesFilling.setCalories(70);
		    }
		    else if( entry == 2 ) {
		    	newSaucesFilling.setName("Cebola Agridoce");
		    	newSaucesFilling.setPrice(1.0);
		    	newSaucesFilling.setFlavor("Cebola Agridoce");
		    	newSaucesFilling.setType(SAUCES);
		    	newSaucesFilling.setCalories(60);
		    }
		    else if( entry == 3 ) {
		    	newSaucesFilling.setName("Barbecue");
		    	newSaucesFilling.setPrice(1.0);
		    	newSaucesFilling.setFlavor("Barbecue");
		    	newSaucesFilling.setType(SAUCES);
		    	newSaucesFilling.setCalories(40);
		    }
		    else if( entry == 4 ) {
		    	newSaucesFilling.setName("Parmesao");
		    	newSaucesFilling.setPrice(1.0);
		    	newSaucesFilling.setFlavor("Parmesao");
		    	newSaucesFilling.setType(SAUCES);
		    	newSaucesFilling.setCalories(90);
		    }
		    else if( entry == 5 ) {
		    	newSaucesFilling.setName("Chipotle");
		    	newSaucesFilling.setPrice(1.0);
		    	newSaucesFilling.setFlavor("Chipotle");
		    	newSaucesFilling.setType(SAUCES);
		    	newSaucesFilling.setCalories(120);
		    }
		    newSaucesFilling.setId(fillingId);


		    //adiciona recheio de queijo no pao
		    newSandwich.insertFilling(newSaucesFilling);

		    //incrementa ordemItemId
		    fillingId++;

		    break;
		    std::system("clear");
		} catch (string msg) {
				cout << "Erro detectado:" << msg << endl;
		}
	} while (true);



	cout << "IDNOVO: " << orderId << endl << endl;
	cout << "ID: " << newOrder.getId() << endl << endl;
	newOrder.setId(orderId);
	gestorSubway.insertOrder(newOrder);

	orderId++;


	// COMBO TYPE


/*
	while(STATE_ORDER == 1)
	{

	}
*/


    STATE_MENU = ORDER_MENU;


}

void displayRemoveOrderMenu()
{
	cout << "Remove Order Menu" << endl << endl;

    int id = 0;
	cout << endl << "Digite o ID do pedido a ser removido: " << endl;
	cin >> id;
	if( gestorSubway.removeOrder(id) != NULL ) {
		cout << "Pedido removido com sucesso" << endl << endl;
	} else {
		cout << "Pedido nao encontrado." << endl << endl;
	}
  	STATE_MENU = ORDER_MENU;

}



bool ONLINE = true;



int main()
{
	// Inserindo usuário padrao no sistema
	gestorSubway.insertUser("admin", user1);


	while(ONLINE) {
		switch (STATE_MENU) {
			case SPLASH_SCREEN:
				displaySplahScreen();
				break;

			case LOGIN_MENU:
				displayLoginMenu();
				break;

			case MAIN_MENU:
				displayMainMenu();
				break;

			case USER_MENU:
				displayUserMenu();
				break;

			case EMPLOYEE_MENU:
				displayEmployeeMenu();
				break;

			case ORDER_MENU:
				displayOrderMenu();
				break;

			case INSERT_USER_MENU:
				displayInsertUserMenu();
				break;

			case REMOVE_USER_MENU:
				displayRemoveUserMenu();
				break;

			case INSERT_EMPLOYEE_MENU:
				displayInsertEmployeeMenu();
				break;

			case REMOVE_EMPLOYEE_MENU:
				displayRemoveEmployeeMenu();
				break;

			case INSERT_ORDER_MENU:
				displayInsertOrderMenu();
				break;

			case REMOVE_ORDER_MENU:
				//displayMEmployeeMenu();
				break;

			case EXIT:
				ONLINE = false;
				break;

			default:
				break;
		}
	}

	return 0;
}
