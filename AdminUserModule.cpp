#include "AdminModule.h"

void AddNewUser(vector<User>& users, int& lastId) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	User buf;
	buf.id = ++lastId;
	cout << "Login: ";
	getline(cin, buf.login);
	cout << "Password: ";
	getline(cin, buf.password);
	cout << "FIO: ";
	getline(cin, buf.fio);
	cout << "Number: ";
	getline(cin, buf.number);
	cout << "Role (0:Client; 1:Administrator): ";
	int _role;
	cin >> _role;
	buf.role_type = (ROLE)_role;
	users.push_back(buf);
}

void ChangeUser(vector<User>& users, int id) {
	int index = login_module::FindUser(users, id);
	if (index == -1)
	{
		cout << "User not found" << endl;
		system("pause");
		return;
	}
	login_module::DisplayOne(users[index]);
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
		users[index].login = data;
	}
	else if (choose == 2)
	{
		cout << "Password: ";
		getline(cin, data);
		users[index].password = data;
	}
	else if (choose == 3)
	{
		cout << "FIO: ";
		getline(cin, data);
		users[index].fio = data;
	}
	else if (choose == 4)
	{
		cout << "Number: ";
		getline(cin, data);
		users[index].number = data;
	}
	else if (choose == 5)
	{
		User* buf = &users[index];
		cout << "Login: ";
		getline(cin, buf->login);
		cout << "Password: ";
		getline(cin, buf->password);
		cout << "FIO: ";
		getline(cin, buf->fio);
		cout << "Number: ";
		getline(cin, buf->number);
	}
	else if (choose == 6)
	{
		return;
	}
}

void DeleteUser(vector<User>& users, int id)
{
	int index = login_module::FindUser(users, id);
	if (index == -1)
	{
		cout << "User not found" << endl;
		system("pause");
		return;
	}
	users.erase(users.begin() + index);
}