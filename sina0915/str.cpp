/*

*/
#include <iostream>
#include <string>
#include <set>

using namespace std;

void func(string first, string second)
{
	set<char> sc;
	string res;
	int flen = first.size();
	int slen = second.size();

	for (int i = 0; i < slen; i++)
	{
		sc.insert(second[i]);
	}
	for (int i = 0; i < flen; i++)
	{
		if (sc.find(first[i]) == sc.end())
		{
			res += first[i];
		}
	}

	cout << res << endl;

}

//int main()
//{
//	string first, second;
//	while (cin >> first >> second)
//	{
//		func(first, second);
//	}
//	return 0;
//}


