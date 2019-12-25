/*
大家一定玩过“推箱子”这个经典的游戏。具体规则就是在一个N*M的地图上，有1个玩家、1个箱子、1个目的地以及若干障碍，其余是空地。玩家可以往上下左右4个方向移动，但是不能移动出地图或者移动到障碍里去。如果往这个方向移动推到了箱子，箱子也会按这个方向移动一格，当然，箱子也不能被推出地图或推到障碍里。当箱子被推到目的地以后，游戏目标达成。现在告诉你游戏开始是初始的地图布局，请你求出玩家最少需要移动多少步才能够将游戏目标达成。
输入描述:
每个测试输入包含1个测试用例
第一行输入两个数字N，M表示地图的大小。其中0<N，M<=8。
接下来有N行，每行包含M个字符表示该行地图。其中 . 表示空地、X表示玩家、*表示箱子、#表示障碍、@表示目的地。
每个地图必定包含1个玩家、1个箱子、1个目的地。


输出描述:
输出一个数字表示玩家最少需要移动多少步才能将游戏目标达成。当无论如何达成不了的时候，输出-1。

输入例子1:
4 4
....
..*@
....
.X..
6 6
...#..
......
#*##..
..##.#
..X...
.@#...

输出例子1:
3
11
*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
struct humanbox {
	int hx, hy, bx, by;
	humanbox(int x, int y, int bbx, int bby) :hx(x), hy(y), bx(bbx), by(bby) {};
};
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m, 0));
	int hx, hy, bx, by;
	int endx, endy;
	for (int i = 0; i != n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j != m; ++j)
		{
			if (str[j] == 'X')
			{
				map[i][j] = 'X';
				hx = i;
				hy = j;
			}
			else if (str[j] == '#')
				map[i][j] = '#';
			else if (str[j] == '@')
			{
				map[i][j] = '@';
				endx = i;
				endy = j;
			}
			else if (str[j] == '*')
			{
				map[i][j] = '*';
				bx = i;
				by = j;
			}
		}
	}
	int stepx[4] = { 0,0,1,-1 };
	int stepy[4] = { 1,-1,0,0 };
	int count[10][10][10][10] = { 0 };
	queue<humanbox> que;
	que.push(humanbox(hx, hy, bx, by));
	count[hx][hy][bx][by] = 1;
	while (!que.empty())
	{
		humanbox top_que = que.front();
		que.pop();
		if (top_que.bx == endx&&top_que.by == endy)
		{
			cout << (count[top_que.hx][top_que.hy][top_que.bx][top_que.by]) - 1 << endl;
			return 0;
		}
		for (int i = 0; i != 4; ++i)
		{
			int hnx = top_que.hx + stepx[i];
			int hny = top_que.hy + stepy[i];
			if (hnx<0 || hny<0 || hnx >= n || hny >= m || map[hnx][hny] == '#') continue;

			if (hnx == top_que.bx&&hny == top_que.by)
			{
				int bnx = top_que.bx + stepx[i];
				int bny = top_que.by + stepy[i];
				if (bnx<0 || bny<0 || bnx >= n || bny >= m || map[bnx][bny] == '#') continue;
				if (count[hnx][hny][bnx][bny]) continue;
				count[hnx][hny][bnx][bny] = count[top_que.hx][top_que.hy][top_que.bx][top_que.by] + 1;
				que.push(humanbox(hnx, hny, bnx, bny));
			}

			else
			{
				if (count[hnx][hny][top_que.bx][top_que.by])
					continue;
				count[hnx][hny][top_que.bx][top_que.by] = count[top_que.hx][top_que.hy][top_que.bx][top_que.by] + 1;
				que.push(humanbox(hnx, hny, top_que.bx, top_que.by));
			}

		}

	}

	cout << -1 << endl;
	return 0;

}


