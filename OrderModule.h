#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "LoginModule.h"
using namespace std;


struct Order
{
	int ID;
	int ClientID;
	string Name;
	string Brand;
	double Cost;
	string DateRecieve;
	string DateReturn;
	bool Status;
};

namespace orderModule
{
	void loadFromFile(vector<Order> &st, int& lastID);
	void saveToFile(vector<Order> st, int lastID);
	void displayAll(vector<Order> st);
	void displayOne(Order st);

	void individual(vector<Order> orders, int clientId);
	void uncomplited(vector<Order> orders);
	
	int findById(vector<Order> st, int id);
	int findByName(vector<Order> st, string name);
	int findByBrand(vector<Order> st, string brand);
	int findByDateRecieve(vector<Order> st, string date);
	int findByDateReturn(vector<Order> st, string date);

	void sortById(vector<Order> &st);
	void sortByName(vector<Order> &st);
	void sortByBrand(vector<Order> &st);
	void sortByCost(vector<Order> &st);
}