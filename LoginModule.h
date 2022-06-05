#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

enum ROLE
{
	Client,
	Administrator
};

struct User
{
public:
	int id;
	string login;
	string password;
	string fio;
	string number;
	ROLE role_type;
};

namespace login_module
{
	//TODO: check file
	void LoadFromFile(vector<User> &st, int& lastID);
	void SaveToFile(vector<User> st, int lastID);
	void DisplayAll(vector<User> st);
	void DisplayOne(User user);
	int FindUser(vector<User> st, string login);
	int FindUser(vector<User> st, int id);
	bool Login(vector<User> st, User& outUser);
}