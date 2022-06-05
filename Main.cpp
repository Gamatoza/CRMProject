#include "LoginModule.h"
#include "OrderModule.h"
#include "AdminModule.h"

int main() {
	vector<User> users;
	int lastUserID, lastOrderID;
	loginModule::loadFromFile(users, lastUserID);
	User currentUser;
	if (loginModule::login(users, currentUser))
	{
		int choose;
		vector<Order> orders;
		cout << "Initialize orders..." << endl;
		orderModule::loadFromFile(orders,lastOrderID);
		if (currentUser.RoleType == Role::Client)
		{
			cout << "Client work!" << endl;
		}
		else if (currentUser.RoleType == Role::Administrator)
		{
			int id;
			while (true)
			{
				system("cls");
				cout << "Select the operating mode:\n1)Work with users\n2)Work with data's\n3)Exit\nChoose: ";
				cin >> choose;
				if (choose == 1)
				{
					while (true)
					{
						system("cls");
						cout << "Select command:\n1)Display all users\n2)Add new user\n3)Change user\n4)Delete user\n5)Back\nChoose: ";
						cin >> choose;
						if (choose == 1)
						{
							loginModule::displayAll(users);
							system("pause");
						}
						else if (choose == 2)
						{
							add_new_user(users, lastUserID);
						}
						else if (choose == 3)
						{
							cout << "Id user to change: ";
							cin >> id;
							change_user(users, id);
						}
						else if (choose == 4)
						{
							cout << "Id user to delete: ";
							cin >> id;
							delete_user(users, id);
						}
						else if (choose == 5)
						{
							loginModule::saveToFile(users, lastUserID);
							break;
						}
					}
				}
				else if (choose == 2)
				{
					system("cls");
					cout << "Select the operating mode:\n1)Redactor\n2)Treatnebt\n3)Exit\nChoose: ";
					cin >> choose;
					if (choose == 1)
					{
						while (true)
						{
							system("cls");
							cout << "Select command:\n1)Display all orders\n2)Add new order\n3)Change order\n4)Delete order\n5)Back\nChoose: ";
							cin >> choose;
							if (choose == 1)
							{
								orderModule::displayAll(orders);
								system("pause");
							}
							else if (choose == 2)
							{
								add_new_order(orders, lastOrderID);
							}
							else if (choose == 3)
							{
								cout << "Id user to change: ";
								cin >> id;
								change_order(orders, id);
							}
							else if (choose == 4)
							{
								cout << "Id user to delete: ";
								cin >> id;
								delete_order(orders, id);
							}
							else if (choose == 5)
							{
								orderModule::saveToFile(orders, lastOrderID);
								break;
							}

						}
					}
					else if (choose == 2)
					{
						cout << "Work in progress";
						/*while (true)
						{

						}*/
					}
					else if (choose == 3)
					{
						orderModule::saveToFile(orders, lastOrderID);
						break;
					}
				}
				else if (choose == 3)
				{
					return 0;
				}
			}
		}
		else
		{
			cout << "Unknown roletype" << endl;
		}
	}

	return 0;
}