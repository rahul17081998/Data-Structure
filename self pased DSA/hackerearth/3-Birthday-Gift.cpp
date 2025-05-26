#include<bits/stdc++.h>
using namespace std;

// /*
class Solution{
public:
	void fun(int rot, vector<vector<int> > &grid, string dir)
	{
		int n = grid.size();
		vector<vector<int> > temp;
		if(dir=="Left"){
			for(int j=n-1; j>=0; j--)
			{
				vector<int> level;
				for(int i=0; i<n; i++)
				{
					level.push_back(grid[i][j]);
				}
				temp.push_back(level);
			}
		}
		else{
			for(int j=0; j<n; j++)
			{
				vector<int> level;
				for(int i=n-1; i>=0; i--)
				{
					level.push_back(grid[i][j]);
				}
				temp.push_back(level);
			}
		}

		grid = temp;

	}

	void solve(vector<vector<int> > &grid, string s)
	{
		int left=0;
		int right=0;
		for(int i=0; i<s.length(); i++)
		{
			if(s[i]=='L') left++;
			else right++;
		}
		if(left>right){
			left = left-right;
			for(int i=0; i<left; i++)
				fun(left, grid, "Left");
		}
		else{
			right = right - left;
			for(int i=0; i<right; i++)
				fun(right, grid, "Right");
		}

		

	}
};
// */
int main()
{
	// write input
	int n;
	cin>>n;
	vector<vector<int> > grid(n, vector<int> (n, -1));
	for(int i=0; i<n ;i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>grid[i][j];
		}
	}
	string s;
	cin >> s;

	Solution ob;
	ob.solve(grid, s);
	// print ans
	for(int i=0; i<n ;i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

/*
Sample input:

2
1 2
3 4
RLR

Sample O/p:
3 1
4 2

*/