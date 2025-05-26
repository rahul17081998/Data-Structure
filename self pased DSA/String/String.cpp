#include<bits/stdc++.h>
using namespace std;

string solve(string &str,int k);
string solve(string &str,int k)
{
	int i;
	deque<int> dq;
	int n=str.length();
	vector<int> ans(n-k+1);
	for(i=0;i<k;i++)
	{
		while(!dq.empty() && str[dq.back()]>=str[i])
			dq.pop_back();
		dq.push_back(i);
	}
	
	for(;i<n;i++)
	{
		ans[i-k]=dq.front();
		while(!dq.empty() && dq.front()<=i-k)
			dq.pop_front();
		while(!dq.empty() && str[dq.back()]>=str[i])
			dq.pop_back();
		dq.push_back(i);
	}
	 ans[n-k]=(dq.empty())?n-1:dq.front();
	 string x="";
	 int v=ans[0];
	 x+=str[v];
	 for(i=1;i<ans.size();i++)
	 {
	 	if(ans[i]-v>=k)
	 	{
	 		v=ans[i];
	 		x+=str[ans[i]];
	 	}
	 	else if(str[ans[i]]!=str[v])
	 	{
	 		v=ans[i];
	 		x+=str[ans[i]];
	 	}
	 }
	 sort(x.begin(),x.end());
	 return x;
	
}
int main()
{
	
	
	int k=3;
	
	string str="abcdef";
	
	cout<<solve(str,k)<<"\n";
	return 0;
}
