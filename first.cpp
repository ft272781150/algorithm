/*


*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef struct {
	int w;
	int l;
	int h;
}box;

bool compare(const box& l, const box& r) {
	if (l.w < r.w)
		return true;
	else if (l.w > r.w)
		return false;
	else
		return l.l < r.l;
}

int getHeight(vector<int> w, vector<int> l, vector<int> h, int n) {
	int size = w.size();
	vector<box> vBox;
	for (int i = 0; i < size; i++) {
		box tmp;
		tmp.w = w[i];
		tmp.l = l[i];
		tmp.h = h[i];
		vBox.push_back(tmp);
	}
	sort(vBox.begin(), vBox.end(), compare);

	vector<int> dp(size, 0);
	dp[0] = vBox[0].h;
	int maxRes = vBox[0].h;
	for (int i = 1; i<size; i++) {
		for (int j = 0; j < i; j++) {
			if (vBox[i].w > vBox[j].w && vBox[i].l > vBox[j].l)
				dp[i] = max(dp[i], dp[j]);
		}
		dp[i] += vBox[i].h;
		if (dp[i] > maxRes)
			maxRes = dp[i];
	}
	return maxRes;
}

