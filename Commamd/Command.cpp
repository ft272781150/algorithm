/*
Æ¥ÅäÃüÁîĞĞ

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> vs;

bool compare(string front, string back, int index)
{
	int i = vs[index].find(' ', 0);
	string f = vs[index].substr(0, i);
	string b = vs[index].substr(i + 1);

	if (f.find(front, 0) != string::npos && b.find(back, 0) != string::npos)
		return true;
	else
		return false;
}

void print(int n)
{
	switch (n)
	{
	case 1:
	{
		cout << "board fault" << endl;
		break;
	}
	case 2:
	{
		cout << "where to add" << endl;
		break;
	}
	case 3:
	{
		cout << "no board at all" << endl;
		break;
	}
	case 4:
	{
		cout << "impossible" << endl;
		break;
	}
	case 5:
	{
		cout << "install first" << endl;
		break;
	}
	default:
		cout << "unkown command" << endl;
		break;
	}
}

void match(string str)
{
	int count = 0;
	int res = 0;
	int index = str.find(" ", 0);
	if (index != string::npos)
	{
		string front = str.substr(0, index);
		string back = str.substr(index + 1);
		for (int i = 1; i < vs.size(); i++)
		{
			if (compare(front, back, i))
			{
				res = i;
				count++;
			}

		}
		if (count == 1)
		{
			print(res);
		}
		else
		{
			print(0);
		}
	}
	else
	{
		if (vs[0].find(str, 0) != string::npos)
		{
			cout << "reset what" << endl;
		}
		else
		{
			cout << "unkown command" << endl;
		}
	}
}


int main()
{
	vs.push_back("reset");
	vs.push_back("reset board");
	vs.push_back("board add");
	vs.push_back("board delet");
	vs.push_back("reboot backplane");
	vs.push_back("backplane abort");
	string command;
	while (getline(cin, command))
	{
		match(command);
	}
	return 0;
}


