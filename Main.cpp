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
			orders = order_module::Individual(orders, currentUser.id);
			while (true)
			{
				system("cls");
				cout << "Select command:\n1)Display All\n2)Sort display\n3)Search data\n4)Save&Back\nChoose: ";
				cin >> choose;
				if (choose == 1)
				{
					order_module::DisplayAll(orders);
					system("pause");
				}
				else if (choose == 2)
				{
					cout << "Select sort:\n1)By ID\n2)By Name\n3)By Brand\n4)By Cost\nChoose: ";
					cin >> choose;
					if (choose == 1)
					{
						order_module::SortById(orders);
					}
					else if (choose == 2)
					{
						order_module::SortByName(orders);
					}
					else if (choose == 3)
					{
						order_module::SortByBrand(orders);
					}
					else if (choose == 4)
					{
						order_module::SortByCost(orders);
					}
					order_module::DisplayAll(orders);
					order_module::SortById(orders);
					system("pause");
				}
				else if (choose == 3)
				{
					cout << "Select find by:\n1)By Name\n2)By Brand\n3)By Date Recieve\n4)By Date Return\nChoose: ";
					cin >> choose;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					int index;
					if (choose == 1)
					{
						cout << "Name: ";
						string data;
						getline(cin, data);
						index = order_module::FindByName(orders, data);
					}
					else if (choose == 2)
					{
						cout << "Brand: ";
						string data;
						getline(cin, data);
						index = order_module::FindByBrand(orders, data);
					}
					else if (choose == 3)
					{
						cout << "Date recieve: ";
						Date data;
						data.fill(cin);
						index = order_module::FindByDateRecieve(orders, data);
					}
					else if (choose == 4)
					{
						cout << "Date return: ";
						Date data;
						data.fill(cin);
						index = order_module::FindByDateReturn(orders, data);
					}
					order_module::DisplayOne(orders[index]);
					system("pause");
				}
				else if (choose == 4)
				{
					break;
				}
			}
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
						cout << "Select command:\n1)Display all users\n2)Add new user\n3)Change user\n4)Delete user\n5)Save&Back\nChoose: ";
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
							cout << "Id order to change: ";
							cin >> id;
							ChangeUser(users, id);
						}
						else if (choose == 4)
						{
							cout << "Id order to delete: ";
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
					while (true)
					{
						system("cls");
						cout << "Select the operating mode:\n1)Redactor\n2)Process\n3)Save&Exit\nChoose: ";
						cin >> choose;
						if (choose == 1)
						{
							while (true)
							{
								system("cls");
								cout << "Select command:\n1)Display all orders\n2)Add new order\n3)Change order\n4)Delete order\n5)Save&Back\nChoose: ";
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
									cout << "Id order to change: ";
									cin >> id;
									ChangeOrder(orders, id);
								}
								else if (choose == 4)
								{
									cout << "Id order to delete: ";
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
							while (true)
							{
								system("cls");
								cout << "Select command:\n1)Individual\n2)Sort display\n3)Search\n4)Back\nChoose: ";
								cin >> choose;
								if (choose == 1)
								{
									Date dateX, dateY;
									order_module::Overdue(orders);
									order_module::Waiting(orders);
									cout << "Enter x date: ";
									dateX.fill(cin);
									cout << "Enter y date: ";
									dateY.fill(cin);
									order_module::TotalIncome(orders, dateX, dateY);
									system("pause");
								}
								else if (choose == 2)
								{
									cout << "Select sort:\n1)By ID\n2)By Name\n3)By Brand\n4)By Cost\nChoose: ";
									cin >> choose;
									if (choose == 1)
									{
										order_module::SortById(orders);
									}
									else if (choose == 2)
									{
										order_module::SortByName(orders);
									}
									else if (choose == 3)
									{
										order_module::SortByBrand(orders);
									}
									else if (choose == 4)
									{
										order_module::SortByCost(orders);
									}
									order_module::DisplayAll(orders);
									order_module::SortById(orders);
									system("pause");
								}
								else if (choose == 3)
								{
									cout << "Select find by:\n1)By Name\n2)By Brand\n3)By Date Recieve\n4)By Date Return\nChoose: ";
									cin >> choose;
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									int index;
									if (choose == 1)
									{
										cout << "Name: ";
										string data;
										getline(cin, data);
										index = order_module::FindByName(orders, data);
									}
									else if (choose == 2)
									{
										cout << "Brand: ";
										string data;
										getline(cin, data);
										index = order_module::FindByBrand(orders, data);
									}
									else if (choose == 3)
									{
										cout << "Date recieve: ";
										Date data;
										data.fill(cin);
										index = order_module::FindByDateRecieve(orders, data);
									}
									else if (choose == 4)
									{
										cout << "Date return: ";
										Date data;
										data.fill(cin);
										index = order_module::FindByDateReturn(orders, data);
									}
									order_module::DisplayOne(orders[index]);
									system("pause");
								}
								else if (choose == 4)
								{
									break;
								}
							}
						}
						else if (choose == 3)
						{
							order_module::SaveToFile(orders, lastOrderID);
							break;
						}
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