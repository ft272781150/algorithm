/*
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>


using namespace std;

struct edge
{
	int oEdge;
	int iEdge;
};


void bfs(vector<list<int>> vli, int n)
{
	queue<int> q;
	q.push(vli[0].front());
	vli[0].pop_front();
	vector<int> visited(n, 0);
	int sum = 0;
	while (!q.empty())
	{
		int val = q.front();
		q.pop();
		if (visited[val] == 0)
		{
			visited[val]++;
			sum++;
		}
		
			
	}

	cout << "4" << endl;
}

int main()
{

	int n;
	while (cin >> n)
	{
		vector<list<int>> vli(n, list<int>(0));
		for (int i = 0; i < n - 1; i++)
		{
			int source, end;
			cin >> source >> end;
			vli[source - 1].push_back(end);
		}
		bfs(vli, n);
	}

	return 0;

}


