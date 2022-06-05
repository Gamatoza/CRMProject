#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

enum Role
{
	Client,
	Administrator
};

struct User
{
public:
	int ID;
	string Login;
	string Password;
	string FIO;
	string Number;
	Role RoleType;
	User() {}

	User(int id, string login, string password, string fio, string number, Role role)
		:ID(id), Login(login), Password(password), FIO(fio), Number(number), RoleType(role) {}
};

namespace loginModule
{
	//TODO: check file
	void loadFromFile(vector<User> &st, int& lastID);
	void saveToFile(vector<User> st, int lastID);
	void displayAll(vector<User> st);
	void displayOne(User user);
	int findUser(vector<User> st, string login);
	int findUser(vector<User> st, int id);
	bool login(vector<User> st, User& outUser);
}