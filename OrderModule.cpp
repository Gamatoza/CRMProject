#include "OrderModule.h"

namespace orderModule
{
	void loadFromFile(vector<Order> &st, int& lastID) //TODO: write last index first
	{
		ifstream in;
		int total;
		in.open("orders.txt");
		in >> total;
		in >> lastID;
		while (!in.eof() && total-- > 0)
		{
			Order buf;
			in >> buf.ID;
			in >> buf.ClientID;
			in >> buf.Name;
			in >> buf.Brand;
			in >> buf.Cost;
			in >> buf.DateRecieve;
			in >> buf.DateReturn;
			in >> buf.Status;
			st.push_back(buf);
		}
		in.close();
	}

	void saveToFile(const vector<Order> st, int lastID)
	{
		ofstream out;
		out.open("orders.txt");
		out << st.size() << endl;
		out << (lastID == 0 ? st[st.size()].ID : lastID) << endl;
		for(auto x: st)
		{
			out << x.ID << endl << x.ClientID << endl << x.Name << endl << x.Brand << endl << x.Cost << endl << x.DateRecieve << endl << x.DateReturn << endl << x.Status << endl;
		}
		out.close();
	}

	void displayAll(const vector<Order> st)
	{
		for (auto order : st)
		{
			displayOne(order);
		}
	}

	void displayOne(Order order)
	{
		cout << order.ID << " " << order.ClientID << " " << order.Name << " " << order.Brand << " " << order.Cost << " " << order.DateRecieve << " " << order.DateReturn << " " << order.Status << endl;
	}

	int findById(vector<Order> st, int id) 
	{
		for (size_t i = 0; i < st.size(); i++)
		{
			if (st[i].ID == id)
			{
				return i;
			}
		}

		return -1;
	}



}