#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
 
class Solution{
 
public:
// /*
	// unordered_map<int, int> freqmp;
	// find freq of all elements and store into map
	void calFreq(vector<int> &nums, unordered_map<int, int> &freqmp){
		for(int i=0; i<nums.size(); i++){
			freqmp[nums[i]]++;
		}
	}
 
	double calFreqSum(int left, int right, unordered_map<int, int> &freqmp){
		double sum = 0;
		for(auto p: freqmp)
		{
			int num=p.first;
			int freq=p.second;
			// check if  left <= freq >= right
			if(left <= freq && freq <= right)
				sum = sum + num*freq; 
		}
		return sum;
	}
	// */
	// main function
	vector<double> sumFreq(vector<int> &nums, vector<vector<int> > &query)
	{
		// find freq of all elements and store into map
		unordered_map<int, int> freqmp;
		calFreq(nums, freqmp);
		vector<double> ans;
		for(int i=0; i<query.size(); i++)
		{
			double res = calFreqSum(query[i][0], query[i][1], freqmp); // left and right
			ans.push_back(res);
		}
		return ans;
	}
};
 
int main()
{
	// take input
	int N;
	cin>>N;
	vector<int> nums(N,-1);
	for(int i=0; i<N; i++)
		cin >> nums[i];
 
	int q;
	cin >> q;
	vector<vector<int> > query(q, vector<int>(2, 0));
	for(int i=0; i<q; i++)
	{
		for(int j=0; j<2; j++)
		{
			cin >> query[i][j];
		}
	}
 
	Solution ob;
	vector<double> ans = ob.sumFreq(nums, query);
	// print ans
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<endl;
	
	return 0;
}

/*
Sample Input
8
4 4 6 5 3 3 3 9
4
1 4
2 7
3 7
5 6
*/