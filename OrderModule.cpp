#include "OrderModule.h"

bool operator==(const Date& lhs, const Date& rhs) {
	return lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year;
}
bool operator!=(const Date& lhs, const Date& rhs) {
	return !(lhs == rhs);
}
bool operator< (Date const& lhs, Date const& rhs) {
	return lhs.year < rhs.year&& lhs.month < rhs.month&& lhs.day < rhs.day;
}
bool operator> (Date const& lhs, Date const& rhs) {
	return lhs.year > rhs.year && lhs.month > rhs.month && lhs.day > rhs.day;
}

Date GetCurrentDate()
{
	Date date;
	std::time_t t = std::time(0);   // get time now
	std::tm now;
	errno_t err = localtime_s(&now, &t);
	date.year = (now.tm_year + 1900);
	date.month = (now.tm_mon + 1);
	date.day = now.tm_mday;
	return date;
}

namespace order_module
{
	void LoadFromFile(vector<Order>& st, int& lastID) //TODO: write last index first
	{
		ifstream in;
		int total;
		in.open("orders.txt");
		if (!in)
		{
			in.open("orders.txt", std::fstream::binary | std::fstream::trunc | std::fstream::out);
			in.close();
			// re-open with original flags
			in.open("orders.txt", std::fstream::binary | std::fstream::in | std::fstream::out);
		}
		else
		{
			// read something
			in >> total;
			in >> lastID;
			while (!in.eof() && total-- > 0)
			{
				Order buf;
				in >> buf.id;
				in >> buf.client_id;
				in >> buf.name;
				in >> buf.brand;
				in >> buf.cost;
				buf.date_recieve.fill(in);
				buf.date_return.fill(in);
				in >> buf.status;
				st.push_back(buf);
			}
			in.close();
		}
	}

	void SaveToFile(const vector<Order> st, int lastID)
	{
		ofstream out;
		out.open("orders.txt");
		if (!out)
		{
			out.open("orders.txt", std::fstream::binary | std::fstream::trunc | std::fstream::out);
			out.close();
			// re-open with original flags
			out.open("orders.txt", std::fstream::binary | std::fstream::in | std::fstream::out);
		}
		else
		{
			out << st.size() << endl;
			out << (lastID == 0 ? st[st.size()].id : lastID) << endl;
			for (auto order : st)
			{
				out << order.id << endl
					<< order.client_id << endl
					<< order.name << endl
					<< order.brand << endl
					<< order.cost << endl
					<< order.date_recieve.day << " " << order.date_recieve.month << " " << order.date_recieve.year << endl
					<< order.date_return.day << " " << order.date_return.month << " " << order.date_return.year << endl
					<< order.status << endl;
			}
			out.close();
		}
	}

	void DisplayAll(const vector<Order> st)
	{
		for (auto order : st)
		{
			DisplayOne(order);
		}
	}

	void DisplayOne(Order order)
	{
		cout << order.id << " " << order.client_id << " " << order.name << " " << order.brand << " " << order.cost << " ";
		cout << order.date_recieve.to_string() << " ";
		cout << order.date_return.to_string() << " ";
		cout << order.status << endl;
	}

#pragma region Find
	int FindById(vector<Order> st, int id)
	{
		for (int i = 0; i < st.size(); i++)
		{
			if (st[i].id == id)
			{
				return i;
			}
		}

		return -1;
	}

	bool contains(string str1, string str2)
	{
		return str1.find(str2) != string::npos;
	}

	int FindByName(vector<Order> st, string name)
	{
		for (int i = 0; i < st.size(); i++)
		{
			if (contains(st[i].name, name))
			{
				return i;
			}
		}

		return -1;
	}

	int FindByBrand(vector<Order> st, string brand)
	{
		for (int i = 0; i < st.size(); i++)
		{
			if (contains(st[i].brand, brand))
			{
				return i;
			}
		}

		return -1;
	}

	int FindByDateRecieve(vector<Order> st, Date date)
	{
		for (int i = 0; i < st.size(); i++)
		{
			if (st[i].date_recieve == date)
			{
				return i;
			}
		}

		return -1;
	}

	int FindByDateReturn(vector<Order> st, Date date)
	{
		for (int i = 0; i < st.size(); i++)
		{
			if (st[i].date_return == date)
			{
				return i;
			}
		}

		return -1;
	}
#pragma endregion

#pragma region Sort
	bool cmpId(Order& st1, Order& st2)
	{
		return st1.id < st2.id;
	}

	bool cmpName(Order& st1, Order& st2)
	{
		return st1.name < st2.name;
	}

	bool cmpBrand(Order& st1, Order& st2)
	{
		return st1.brand < st2.brand;
	}

	bool cmpCost(Order& st1, Order& st2)
	{
		return st1.cost < st2.cost;
	}

	void SortById(vector<Order>& st)
	{
		sort(st.begin(), st.end(), cmpId);
	}
	void SortByName(vector<Order>& st)
	{
		sort(st.begin(), st.end(), cmpName);
	}
	void SortByBrand(vector<Order>& st)
	{
		sort(st.begin(), st.end(), cmpBrand);
	}
	void SortByCost(vector<Order>& st)
	{
		sort(st.begin(), st.end(), cmpCost);
	}
#pragma endregion

	vector<Order> Individual(vector<Order> orders, int clientId)
	{
		vector<Order> user_orders;
		for (auto order : orders)
		{
			if (order.client_id == clientId)
			{
				user_orders.push_back(order);
			}
		}
		return user_orders;
	}

	void Overdue(vector<Order> orders)
	{
		Date now = GetCurrentDate();
		for (auto order : orders)
		{
			if (!order.status && order.date_recieve > now)
			{
				DisplayOne(order);
			}
		}
	}

	void Waiting(vector<Order> orders)
	{
		Date now = GetCurrentDate();
		for (auto order : orders)
		{
			if (!order.status && order.date_recieve < now)
			{
				DisplayOne(order);
			}
		}
	}

	void TotalIncome(vector<Order> orders, Date x, Date y)
	{
		double summary = 0;
		for (auto order : orders)
		{
			if (order.date_return > x && order.date_return < y && order.status == 1)
			{
				DisplayOne(order);
				summary += order.cost;
			}
		}
		cout << "Summary: " << summary << endl;
	}
}