/*

*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int findIndex(int x, vector<int> &vp)
{
	int i, j, res;
	res = x;
	while (res != vp[res])     
		res = vp[res]; 
		i = x;
	while (i != res)             
	{
		j = vp[i];         
		vp[i] = res;        
		i = j;                    
	}
	return res;                  
}

void preProcess(int i, int j, vector<int> &vp, vector<int> &val)
{
	i = findIndex(i, vp);
	j = findIndex(j, vp);
	if (i == j) return;
	if (val[i]<val[j])
		vp[i] = j;  
	else
	{
		vp[j] = i;
		if (val[i] == val[j]) val[i]++;
	}
}



int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> vp(n + 1);
		vector<int> val(n + 1, 0);
		vector<int> m(n + 1, 0);
		for (int i = 0; i<n; i++)
		{
			vp[i] = i;
		}

		for (int i = 1; i <= n; i++) {
			int t;
			while (cin>>t) {
				if (t == 0)
					break;
				preProcess(i, t, vp, val);
			}
		}

		int count = 0;
		for (int i = 1; i <= n; i++) {
			int t = findIndex(i, vp);
			if (m[t] == 0) {
				count++;
				m[t] = 1;
			}
		}
		cout << count << endl;
		
	}

	return 0;
}

