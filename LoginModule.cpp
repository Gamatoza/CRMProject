#include "LoginModule.h"
namespace login_module
{
	void LoadFromFile(vector<User> &st, int& lastID) 
	{
		ifstream in;
		int total;
		in.open("users.txt");
		in >> total;
		in >> lastID;
		while (!in.eof() && total-- > 0)
		{
			User buf;
			in >> buf.id;
			in >> buf.login;
			in >> buf.password;
			in >> buf.fio;
			in >> buf.number;
			int _role;
			in >> _role;
			buf.role_type = (ROLE)_role;
			st.push_back(buf);
		}
		in.close();
	}

	void SaveToFile(const vector<User> st, int lastID)
	{
		ofstream out;
		out.open("users.txt");
		out << st.size() << endl;
		out << (lastID == 0 ? st[st.size()].id : lastID) << endl;
		for(auto x: st)
		{
			out << x.id << endl << x.login << endl << x.password << endl << x.fio << endl << x.number << endl << x.role_type << endl;
		}
		out.close();
	}

	void DisplayAll(const vector<User> st)
	{
		for (auto user : st)
		{
			DisplayOne(user);
		}
	}

	void DisplayOne(User user)
	{
		cout << user.id << " " << user.login << " " << user.password << " " << user.fio << " " << user.number << " " << (user.role_type == 0 ? "Client" : "Admin") << endl;
	}

	int FindUser(vector<User> st, string login) 
	{
		for (size_t i = 0; i < st.size(); i++)
		{
			if (st[i].login == login)
			{
				return i;
			}
		}

		return -1;
	}
	
	int FindUser(vector<User> st, int id) 
	{
		for (size_t i = 0; i < st.size(); i++)
		{
			if (st[i].id == id)
			{
				return i;
			}
		}

		return -1;
	}

	bool Login(vector<User> st, User& outUser)
	{
		string login, password;
		cout << "Login: ";
		getline(cin, login);
		int index = login_module::FindUser(st, login);
		if (index == -1)
		{
			cout << "Wrong login" << endl;
			return false;
		}
		cout << "Password: ";
		getline(cin, password);
		if (st[index].password == password)
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