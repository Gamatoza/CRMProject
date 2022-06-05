#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "LoginModule.h"
#include "OrderModule.h"
using namespace std;

#pragma region redactor

void AddNewUser(vector<User>& users, int& lastId);
void ChangeUser(vector<User>& users, int id);
void DeleteUser(vector<User>& users, int id); //TODO: get back

#pragma endregion

#pragma region orders

void AddNewOrder(vector<Order>& orders, int& lastId);
void ChangeOrder(vector<Order>& orders, int id);
void DeleteOrder(vector<Order>& orders, int id);

#pragma endregion
