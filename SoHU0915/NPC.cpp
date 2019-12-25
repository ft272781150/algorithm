/*

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct positon
{
	int x;
	int y;
};


void func(positon player, vector<positon> npc, int n)
{
	int min = 99999;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(player.x - npc[i].x) + abs(player.y - npc[i].y) < min)
		{
			min = abs(player.x - npc[i].x) + abs(player.y - npc[i].y);
			index = i;
		}
	}

	cout << '(' << npc[index].x << ',' << npc[index].y << ')' << endl;

}

//int main()
//{
//	positon player;
//	char c;
//	while (cin >> player.x >> c >> player.y >> c)
//	{
//		int n;
//		cin >> n;
//		vector<positon> npc(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> c >> npc[i].x >> c >> npc[i].y;
//		}
//
//		func(player, npc, n);
//	}
//	return 0;
//}
//


