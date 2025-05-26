#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution{
public:
	unordered_map<int, double> mp; // <menuNo, avgPrice>
	void avgOfMenu(vector<vector<int> > &grid)
	{
		int n = grid.size();
		int m = grid[0].size();
		int totalMenu = n;
		// find avg for each menu
		for(int i=0; i<n; i++)
		{
			double sum=0;
			for(int j=0; j<m; j++) 
				sum = sum+ grid[i][j];
			double avg = sum/m;
			// mp.insert({i, avg});
            mp[i]=avg;
		}
	}

	void maximumPrice(vector<vector<int> > &grid, vector<int> &maxPrice)
	{
		int n = grid.size();
		int m = grid[0].size();
		for(int j=0; j<m; j++)
		{
			int maxi=0;
			for(int i=0; i<n; i++)
			{
				maxi = max(maxi, grid[i][j]);
			}
			maxPrice[j]=maxi;
		}
	}
	int solve(vector<vector<int> > &grid)
	{
		int n = grid.size();
		int m = grid[0].size();
		avgOfMenu(grid); // find avg of all menu  
		vector<int> maxPrice(m, 0);
		// find for each item maximum price
		maximumPrice(grid, maxPrice);
		// keep recorede of a menu have how many good price
		vector<int> goodPrice(n, 0); 

		for(int j=0; j<m; j++)
		{
			// int maxi=0;
			for(int i=0; i<n; i++)
			{
				if(maxPrice[j]==grid[i][j]) 
					goodPrice[i]++;
			}
			// maxPrice[j]=maxi;
		}

		// find maximum occurance in goodPrice array
		int maxOcc = 0;
		for(int i=0; i<n; i++)
			maxOcc = max(maxOcc, goodPrice[i]);
		// find how many items have same maxOcc
		int ans=-1;
		int maxa=0;
		for(int i=0; i<goodPrice.size(); i++)
		{
			if(maxOcc == goodPrice[i] )
			{
				if(maxa < mp[i]){
					maxa = mp[i];
					ans = i+1;
				}
			}
		}

		return ans;
		// return 4;
	}
};

int main()
{
	int n, m;
	// take n amd m as input
	cin>> n >> m;
	vector<vector<int> > grid(n, vector<int>(m, -1));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>grid[i][j];
		}
	}
	Solution ob;
	cout<<ob.solve(grid)<<endl;
	return 0;
}

/*
Sample input:
3 4
1 2 1 10
3 2 3 4
1 3 3 2

O/P: 2
*/