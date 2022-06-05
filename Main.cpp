#include "LoginModule.h"
#include "OrderModule.h"
#include "AdminModule.h"

int main() {
	vector<User> users;
	int lastUserID, lastOrderID;
	login_module::LoadFromFile(users, lastUserID);
	User currentUser;
	if (login_module::Login(users, currentUser))
	{
		int choose;
		vector<Order> orders;
		cout << "Initialize orders..." << endl;
		order_module::LoadFromFile(orders, lastOrderID);
		if (currentUser.role_type == ROLE::Client)
		{
			/*
			просмотр всех данных;
			поиск данных (как минимум по трем различным параметрам);
			сортировка (как минимум по трем различным параметрам).
			*/
		}
		else if (currentUser.role_type == ROLE::Administrator)
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
							login_module::DisplayAll(users);
							system("pause");
						}
						else if (choose == 2)
						{
							AddNewUser(users, lastUserID);
						}
						else if (choose == 3)
						{
							cout << "Id user to change: ";
							cin >> id;
							ChangeUser(users, id);
						}
						else if (choose == 4)
						{
							cout << "Id user to delete: ";
							cin >> id;
							DeleteUser(users, id);
						}
						else if (choose == 5)
						{
							login_module::SaveToFile(users, lastUserID);
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
								order_module::DisplayAll(orders);
								system("pause");
							}
							else if (choose == 2)
							{
								AddNewOrder(orders, lastOrderID);
							}
							else if (choose == 3)
							{
								cout << "Id user to change: ";
								cin >> id;
								ChangeOrder(orders, id);
							}
							else if (choose == 4)
							{
								cout << "Id user to delete: ";
								cin >> id;
								DeleteOrder(orders, id);
							}
							else if (choose == 5)
							{
								order_module::SaveToFile(orders, lastOrderID);
								break;
							}
						}
					}
					else if (choose == 2)
					{
						cout << "Work in progress";
						/*
						выполнение индивидуального задания;
						поиск данных (как минимум по трем различным параметрам);
						сортировка (как минимум по трем различным параметрам).
						*/
					}
					else if (choose == 3)
					{
						order_module::SaveToFile(orders, lastOrderID);
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