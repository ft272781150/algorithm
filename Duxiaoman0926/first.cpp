/*

*/
#include <iostream>
#include <vector>

using namespace std;


struct game
{
	int a;
	int b;
	int n;
};


void func(vector<game> vg, int t)
{

}

int main()
{
	int t;
	while (cin >> t)
	{
		vector<game> vg(t);
		for (int i = 0; i < t; i++)
		{
			cin >> vg[i].a >> vg[i].b >> vg[i].n;
		}

		func(vg, t);
	}
	return 0;

}


