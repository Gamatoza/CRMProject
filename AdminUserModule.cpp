#include "AdminModule.h"

void add_new_user(vector<User>& users, int& lastId)
{
	User buf;
	buf.ID = ++lastId;
	cout << "Login: ";
	cin >> buf.Login;
	cout << "Password: ";
	cin >> buf.Password;
	cout << "FIO: ";
	cin >> buf.FIO;
	cout << "Number: ";
	cin >> buf.Number;
	cout << "Role (0:Client; 1:Administrator): ";
	int _role;
	cin >> _role;
	buf.RoleType = (Role)_role;
	users.push_back(buf);
}

void change_user(vector<User>& users, int id)
{
	int index = loginModule::findUser(users, id);
	if (index == -1)
	{
		cout << "User not found" << endl;
		system("pause");
		return;
	}
	loginModule::displayOne(users[index]);
	cout << "What do you need to change\n1)Login\n2)Password\n3)FIO\n4)Number\n5)All\n6)Back\nChoose: ";
	int choose;
	cin >> choose;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string data;
	if (choose == 1)
	{
		cout << "Login: ";
		getline(cin, data);
		users[index].Login = data;
	}
	else if (choose == 2)
	{
		cout << "Password: ";
		getline(cin, data);
		users[index].Password = data;
	}
	else if (choose == 3)
	{
		cout << "FIO: ";
		getline(cin, data);
		users[index].FIO = data;
	}
	else if (choose == 4)
	{
		cout << "Number: ";
		getline(cin, data);
		users[index].Number = data;
	}
	else if (choose == 5)
	{
		User * buf = &users[index];
		cout << "Login: ";
		getline(cin, buf->Login);
		cout << "Password: ";
		getline(cin, buf->Password);
		cout << "FIO: ";
		getline(cin, buf->FIO);
		cout << "Number: ";
		getline(cin, buf->Number);
	}
	else if (choose == 6)
	{
		return;
	}
}

void delete_user(vector<User>& users, int id)
{
	int index = loginModule::findUser(users, id);
	if (index == -1)
	{
		cout << "User not found" << endl;
		system("pause");
		return;
	}
	users.erase(users.begin()+index);
}