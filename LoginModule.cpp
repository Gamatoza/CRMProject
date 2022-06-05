#include "LoginModule.h"
namespace loginModule
{
	void loadFromFile(vector<User> &st, int& lastID) 
	{
		ifstream in;
		int total;
		in.open("users.txt");
		in >> total;
		in >> lastID;
		while (!in.eof() && total-- > 0)
		{
			User buf;
			in >> buf.ID;
			in >> buf.Login;
			in >> buf.Password;
			in >> buf.FIO;
			in >> buf.Number;
			int _role;
			in >> _role;
			buf.RoleType = (Role)_role;
			st.push_back(buf);
		}
		in.close();
	}

	void saveToFile(const vector<User> st, int lastID)
	{
		ofstream out;
		out.open("users.txt");
		out << st.size() << endl;
		out << (lastID == 0 ? st[st.size()].ID : lastID) << endl;
		for(auto x: st)
		{
			out << x.ID << endl << x.Login << endl << x.Password << endl << x.FIO << endl << x.Number << endl << x.RoleType << endl;
		}
		out.close();
	}

	void displayAll(const vector<User> st)
	{
		for (auto user : st)
		{
			displayOne(user);
		}
	}

	void displayOne(User user)
	{
		cout << user.ID << " " << user.Login << " " << user.Password << " " << user.FIO << " " << user.Number << " " << (user.RoleType == 0 ? "Client" : "Admin") << endl;
	}

	int findUser(vector<User> st, string login) 
	{
		for (size_t i = 0; i < st.size(); i++)
		{
			if (st[i].Login == login)
			{
				return i;
			}
		}

		return -1;
	}
	
	int findUser(vector<User> st, int id) 
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

	bool login(vector<User> st, User& outUser)
	{
		string login, password;
		cout << "Login: ";
		getline(cin, login);
		int index = loginModule::findUser(st, login);
		if (index == -1)
		{
			cout << "Wrong login" << endl;
			return false;
		}
		cout << "Password: ";
		getline(cin, password);
		if (st[index].Password == password)
		{
			cout << "Login succesfull" << endl;
			outUser = st[index];
			return true;
		}
		else
		{
			cout << "Wrong password" << endl;
			return false;
		}
	}
}