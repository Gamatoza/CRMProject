#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "LoginModule.h"
using namespace std;


/*
наименование ремонтируемого изделия (телевизор ит.д.), марка изделия,
Ф.И.О. владельца, телефон владельца, стоимость ремонта, дата приемки, дата выдачи, статус (выполнен или нет)
*/
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
	//TODO: check file
	void loadFromFile(vector<Order> &st, int& lastID);
	void saveToFile(vector<Order> st, int lastID);
	void displayAll(vector<Order> st);
	void displayOne(Order st);
	int findOrder(vector<Order> st, int id);
}