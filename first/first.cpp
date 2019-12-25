#include <iostream>
#include <vector>
using namespace std;
int dfs(vector<vector<int>>& mmap, int x, int y, vector<vector<bool>>& visited) {
	if (x >= mmap.size() || y >= mmap[0].size() || x < 0 || y < 0)
		return 0;
	if (visited[x][y] == true)
		return 0;
	if (mmap[x][y] == 0)
		return 0;
	visited[x][y] = true;
	return 1 + dfs(mmap, x + 1, y, visited) + dfs(mmap, x - 1, y, visited) + dfs(mmap, x, y + 1, visited) + dfs(mmap, x, y - 1, visited)
		+ dfs(mmap, x + 1, y + 1, visited) + dfs(mmap, x - 1, y - 1, visited) + dfs(mmap, x + 1, y - 1, visited) + dfs(mmap, x - 1, y + 1, visited);
}
void maxAreaOfIsland(vector<vector<int>>& mmap) {
	if (mmap.empty())
		return;
	int num = 0;
	int res = 0;
	vector<vector<bool>> visited(mmap.size(), vector<bool>(mmap[0].size(), false));
																				   
	int m = mmap.size();
	int n = mmap[0].size();
	//¿ªÊ¼ËÑË÷
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == true)
				continue;
			if (mmap[i][j] == 0) {
				visited[i][j] = true;
				continue;
			}
			int temp = dfs(mmap, i, j, visited);
			++num;
			mmap[i][j] = 8;
			res = res>temp ? res : temp;
		}
	}
	cout << num << ',' << res << endl;


}

int main()
{
	int m, n;
	char c;
	cin >> m >> c >> n;
	vector<vector<int>> mmap(m, vector<int>(n, 0));
	int temp;
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n - 1; j++) {
			cin >> mmap[i][j];
			cin >> c;
		}
		cin >> mmap[i][n - 1];
	}
	maxAreaOfIsland(mmap);
	return 0;
}
