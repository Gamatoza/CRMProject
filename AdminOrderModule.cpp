#include "OrderModule.h"

void add_new_order(vector<Order>& orders, int& lastId)
{
	Order buf;
	buf.ID = ++lastId;
	cout << "ClientID: ";
	cin >> buf.ClientID; //TODO: Check is has one
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Name: ";
	getline(cin, buf.Name);
	cout << "Brand: ";
	getline(cin, buf.Brand);
	cout << "Cost: ";
	cin >> buf.Cost;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "DateRecieve: ";
	getline(cin, buf.DateRecieve);
	cout << "DateReturn: ";
	getline(cin, buf.DateReturn);
	cout << "Status: ";
	cin >> buf.Status;
	orders.push_back(buf);
}

void change_order(vector<Order>& orders, int id)
{
	int index = orderModule::findOrder(orders, id);
	if (index == -1)
	{
		cout << "Order not found" << endl;
		system("pause");
		return;
	}
	orderModule::displayOne(orders[index]);
	cout << "What do you need to change\n1)Name\n2)Brand\n3)Cost\n4)DateRecieve\n5)DateReturn\n6)Status\n7)All\n8)Back\nChoose: ";
	int choose;
	cin >> choose;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string data;
	if (choose == 1)
	{
		cout << "Name: ";
		getline(cin, data);
		orders[index].Name = data;
	}
	else if (choose == 2)
	{
		cout << "Brand: ";
		getline(cin, data);
		orders[index].Brand = data;
	}
	else if (choose == 3)
	{
		cout << "Cost: ";
		double cost;
		cin >> cost;
		orders[index].Cost = cost;
	}
	else if (choose == 4)
	{
		cout << "DateRecieve: ";
		getline(cin, data);
		orders[index].DateRecieve = data;
	}
	else if (choose == 5)
	{
		cout << "DateReturn: ";
		getline(cin, data);
		orders[index].DateReturn = data;
	}
	else if (choose == 6)
	{
		cout << "Status: ";
		bool status;
		cin >> status;
		orders[index].Status = status;
	}
	else if (choose == 7)
	{
		Order * buf = &orders[index];
		cout << "Name: ";
		getline(cin, buf->Name);
		cout << "Brand: ";
		getline(cin, buf->Brand);
		cout << "Cost: ";
		cin >> buf->Cost;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "DateRecieve: ";
		getline(cin, buf->DateRecieve);
		cout << "DateReturn: ";
		getline(cin, buf->DateReturn);
		cout << "Status: ";
		cin >> buf->Status;
	}
	else if (choose == 8)
	{
		return;
	}
}

void delete_order(vector<Order>& orders, int id)
{
	int index = orderModule::findOrder(orders, id);
	if (index == -1)
	{
		cout << "User not found" << endl;
		system("pause");
		return;
	}
	orders.erase(orders.begin()+index);
}

void individual_admin_order(vector<Order> orders)
{

}

void search_admin_order(vector<Order> orders)
{

}

void sort_admin_order(vector<Order> orders)
{

}