#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>  
#include "LoginModule.h"
using namespace std;

struct Date
{
	int day;
	int month;
	int year;

	void fill(istream& in) {
		in >> day;
		in >> month;
		in >> year;
	}

	void display()
	{
		cout << day << '.' << month << '.' << year;
	}

	string to_string()
	{
		return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
	}

	friend bool operator==(const Date &lhs, const Date &rhs);
	friend bool operator!=(const Date &lhs, const Date &rhs);

};

struct Order
{
	int id;
	int client_id;
	string name;
	string brand;
	double cost;
	Date date_recieve;
	Date date_return;
	bool status;
};

namespace order_module
{
	void LoadFromFile(vector<Order> &st, int& lastId);
	void SaveToFile(vector<Order> st, int lastId);
	void DisplayAll(vector<Order> st);
	void DisplayOne(Order st);

	void Individual(vector<Order> orders, int clientId);
	void Uncomplited(vector<Order> orders);
	void Waiting(vector<Order> orders);
	void TotalIncome(vector<Order> orders);
	
	int FindById(vector<Order> st, int id);
	int FindByName(vector<Order> st, string name);
	int FindByBrand(vector<Order> st, string brand);
	int FindByDateRecieve(vector<Order> st, Date date);
	int FindByDateReturn(vector<Order> st, Date date);

	void SortById(vector<Order> &st);
	void SortByName(vector<Order> &st);
	void SortByBrand(vector<Order> &st);
	void SortByCost(vector<Order> &st);
}