/*

*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
using namespace std;


struct val
{
	int a;
	string rel;
};

int stringToint(string str)
{
	stringstream ss(str);
	int res = 0;
	ss >> res;
	return res;
}


int Atoi(string s, int radix)    
{
	int ans = 0;
	for (int i = 0; i<s.size(); i++)
	{
		char t = s[i];
		if (t >= '0'&&t <= '9') ans = ans*radix + t - '0';
		else ans = ans*radix + t - 'a' + 10;
	}
	return ans;
}

val preprocess(string str)
{
	val res;
	int pos = str.find('#', 0);
	if (pos != string::npos)
	{
		res.a = stringToint(str.substr(0, pos + 1));
		res.rel = str.substr(pos + 1);
	}
	return res;
}

void func(vector<string> vs)
{
	vector<string> res;
	map<int, int> mp;
	map<int, int>::iterator it;
	mp.clear();
	int len = vs.size();
	int k;
	for (int i = 0; i < len; i++)
	{
		val kk = preprocess(vs[i]);
		k = Atoi(kk.rel, kk.a);
		mp[k]++;
		
	}

	for (int i = 0; i < len; i++)
	{
		val kk = preprocess(vs[i]);
		if (mp.find(Atoi(kk.rel, kk.a))->second == 1)
		{
			res.push_back(vs[i]);
		}
	}

	int reslen = res.size();
	if (reslen == 0)
	{
		cout << "None" << endl;
		return;
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}

}

//int main()
//{
//	vector<string> vs;
//	string str;
//	while (getline(cin, str))
//	{
//		if (str != "END")
//		{
//			vs.push_back(str);
//		}
//		else
//		{
//			func(vs);
//			vs.clear();
//		}
//	}
//
//	return 0;
//}


