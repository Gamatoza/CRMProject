#include "OrderModule.h"

void AddNewOrder(vector<Order>& orders, int& lastId)
{
	Order buf;
	buf.id = ++lastId;
	cout << "ClientID: ";
	cin >> buf.client_id; //TODO: Check is has one
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Name: ";
	getline(cin, buf.name);
	cout << "Brand: ";
	getline(cin, buf.brand);
	cout << "Cost: ";
	cin >> buf.cost;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "DateRecieve: ";
	buf.date_recieve.fill(cin);
	cout << "DateReturn: ";
	buf.date_return.fill(cin);
	cout << "Status: ";
	cin >> buf.status;
	orders.push_back(buf);
}

void ChangeOrder(vector<Order>& orders, int id)
{
	int index = order_module::FindById(orders, id);
	if (index == -1)
	{
		cout << "Order not found" << endl;
		system("pause");
		return;
	}
	order_module::DisplayOne(orders[index]);
	cout << "What do you need to change\n1)Name\n2)Brand\n3)Cost\n4)DateRecieve\n5)DateReturn\n6)Status\n7)All\n8)Back\nChoose: ";
	int choose;
	cin >> choose;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (choose == 1)
	{
		cout << "Name: ";
		getline(cin, orders[index].name);
	}
	else if (choose == 2)
	{
		cout << "Brand: ";
		getline(cin, orders[index].brand);
	}
	else if (choose == 3)
	{
		cout << "Cost: ";
		cin >> orders[index].cost;
	}
	else if (choose == 4)
	{
		cout << "DateRecieve: ";
		orders[index].date_recieve.fill(cin);
	}
	else if (choose == 5)
	{
		cout << "DateReturn: ";
		orders[index].date_return.fill(cin);
	}
	else if (choose == 6)
	{
		cout << "Status: ";
		cin >> orders[index].status;
	}
	else if (choose == 7)
	{
		Order * buf = &orders[index];
		cout << "Name: ";
		getline(cin, buf->name);
		cout << "Brand: ";
		getline(cin, buf->brand);
		cout << "Cost: ";
		cin >> buf->cost;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "DateRecieve: ";
		buf->date_recieve.fill(cin);
		cout << "DateReturn: ";
		buf->date_return.fill(cin);
		cout << "Status: ";
		cin >> buf->status;
	}
	else if (choose == 8)
	{
		return;
	}
}

void DeleteOrder(vector<Order>& orders, int id)
{
	int index = order_module::FindById(orders, id);
	if (index == -1)
	{
		cout << "User not found" << endl;
		system("pause");
		return;
	}
	orders.erase(orders.begin()+index);
}

