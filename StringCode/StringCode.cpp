/*
����һ���ַ��������㽫�ַ������±��룬���������ַ��滻�ɡ��������ֵĸ���+�ַ����������ַ���AAAABCCDAA�ᱻ�����4A1B2C1D2A��
��������:
ÿ�������������1����������
ÿ��������������ֻ��һ���ַ������ַ���ֻ������дӢ����ĸ�����Ȳ�����10000��
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



