#include <bits/stdc++.h>
using namespace std;

int WineDp(vector<int> wines, int i, int j, int y, vector<vector<int> > &dp)
{
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int opt1 = wines[i]*y + WineDp(wines, i+1, j, y+1, dp); // select from front endl
    int opt2 = wines[j]*y + WineDp(wines, i, j-1, y+1, dp);
    return dp[i][j] = max(opt1, opt2);
}

int main() {
	
	int n;
	cin>>n;
	vector<int> wines(n);
	for(int i=0; i<n; i++){
	    cin>>wines[i];
	}
	vector<vector<int> > dp(100, vector<int> (100, -1));
	cout<<WineDp(wines, 0, n-1, 1, dp)<<endl;
	return 0;
}
/*
Sample Input:

5 
2 3 5 1 4

Sample Output:
50


*/