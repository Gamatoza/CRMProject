#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "LoginModule.h"
#include "OrderModule.h"
using namespace std;

#pragma region redactor

void add_new_user(vector<User>& users, int& lastId);
void change_user(vector<User>& users, int id);
void delete_user(vector<User>& users, int id); //TODO: get back

#pragma endregion

#pragma region orders

void add_new_order(vector<Order>& orders, int& lastId);
void change_order(vector<Order>& orders, int id);
void delete_order(vector<Order>& orders, int id);

#pragma endregion
