/*

*/
#include <iostream>
#include <string>

using namespace std;

void str_cpy(string &dst, string &source)
{
	dst = source;
}

int main()
{
	string str;
	while (cin >> str)
	{
		string res;
		str_cpy(res, str);
		cout << res << endl;
	}
	return 0;
}




