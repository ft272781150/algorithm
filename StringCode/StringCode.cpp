/*
给定一个字符串，请你将字符串重新编码，将连续的字符替换成“连续出现的个数+字符”。比如字符串AAAABCCDAA会被编码成4A1B2C1D2A。
输入描述:
每个测试输入包含1个测试用例
每个测试用例输入只有一行字符串，字符串只包括大写英文字母，长度不超过10000。
*/
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string intToString(int rel)
{
	stringstream ss;
	ss << rel;
	return ss.str();
}


struct KV
{
	int num;
	char value;
};


void StringCode(string str)
{

	string res;
	vector<KV> vk;
	for (int i = 0; i < str.size(); )
	{
		char tmp = str[i];
		int n = 0;
		while (i < str.size() && str[i] == tmp)
		{
			n++;
			i++;
		}
		KV kv;
		kv.num = n;
		kv.value = tmp;
		vk.push_back(kv);
	}

	for (int i = 0; i < vk.size(); i++)
	{
		res += intToString(vk[i].num);
		res += vk[i].value;
	}

	cout << res << endl;
}

int main()
{
	string str;
	while (cin >> str)
	{
		StringCode(str);
	}
	return 0;
}



