/*


*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <sstream>



using namespace std;

struct semt
{
	int begin;
	int end;


	bool operator < (const semt& rhs) const {
		return begin < rhs.begin;
	}

};

string int2String(int a)
{
	stringstream ss;
	ss << a;
	return ss.str();
}

bool compare(const semt &a, const semt &b)
{
	return a.begin < b.begin;
}


void process(string str, list<semt> &ls)
{
	semt res;
	int pos = str.find(",", 0);
	if (pos == string::npos)
		return;
	res.begin = atoi((str.substr(0, pos)).c_str());
	res.end = atoi((str.substr(pos + 1)).c_str());
	ls.push_back(res);
}


void preProcess(string str, list<semt> &ls)
{
	while (str.find(";", 0) != string::npos)
	{
		int pos = str.find(";", 0);
		process(str.substr(0, pos), ls);
		str = str.substr(pos + 1);
	}
	process(str.substr(0), ls);
}

void func(vector<string> vs)
{
	int size = vs.size();
	list<semt> ls;
	list<semt>::iterator it;
	list<semt>::iterator p;
	for (int i = 0; i < size; i++)
	{
		preProcess(vs[i], ls);
	}

	int n = ls.size();
	ls.sort(compare);
	//sort(ls.begin(), ls.end(), compare);

	for (it = ls.begin(); it != ls.end();)
	{
		p = ++it;
		--it;
		if (p != ls.end() && (it->end >= p->begin))
		{
			p->begin = it->begin;
			if (p->end < it->end)
			{
				p->end = it->end;
			}
			ls.erase(it++);
		}
		else
		{
			++it;
		}

	}
	string res;
	for (it = ls.begin(); it != ls.end(); it++)
	{
		res += int2String(it->begin);
		res += ",";
		res += int2String(it->end);
		res += ";";
	}
	cout << res.substr(0, res.size() - 1) << endl;

}

int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		vector<string> vs(n);
		for (int i = 0; i < n; i++)
		{			
			getline(cin, vs[i]);
		}
		func(vs);
	}
	return 0;
}



