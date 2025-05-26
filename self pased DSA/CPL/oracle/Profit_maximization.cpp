#include <bits/stdc++.h>
using namespace std;

int travelVillage(vector<int> profit)
{
	vector<int> dp = profit;
	int n = profit.size();

	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(profit[i]%profit[j]==0){
				dp[i] = max(dp[i], dp[j]+profit[i]);
			}
		}
	}

	int ans= INT_MIN;
	for(int i=0; i<n; i++){
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main() {
	int n;
	cin>>n;
	vector<int> profit(n);
	for(int i=0; i<n; i++){
		cin>>profit[i];
	}
	cout<<travelVillage(profit)<<endl;
	return 0;
}