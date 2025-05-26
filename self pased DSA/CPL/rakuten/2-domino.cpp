#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

string solve(vector<string> &arr,int n)
{
	int i;
	int j;
	unordered_set<string> st(arr.begin(),arr.end());
	for(i=0;i<=5;i++)
	{
		for(j=0;j<=5;j++)
		{
			string a=to_string(i)+"-"+to_string(j);
			string b=to_string(j)+"-"+to_string(i);
			if(st.find(a)!=st.end() || st.find(b)!=st.end())
				continue;
			else
				return a;
		}
	}
	return "";
}
int main()
{
	
	int n;
	cin>>n;
	vector<string> arr;
	int i;
	for(i=0;i<n;i++)
	{
		string str;
		cin>>str;
		arr.push_back(str);
	}
	cout<<solve(arr,n)<<"\n";
	return 0;
}