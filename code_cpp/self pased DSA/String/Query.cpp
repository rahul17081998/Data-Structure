#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
long long int get(int k,int l,int n);
long long int ncr(int n,int r);

long long int ncr(int n,int r)
{
	if(n<0 || r<0 || r>n)
		return 0;
	int i;
	long long int p=1;
	for(i=1;i<=r;i++)
	{
		p=(p*(n+1-i)/i)%M;
	}
	return p;
}
long long int get(int k,int l,int n)
{
	int i;
	long long int sum=0l;
	for(i=k;i<=n;i++)
	{
		long long a=ncr(i-1,k-1)%M;
		long long b=ncr(n-i,l-k)%M;
		sum=(sum%M+((i*a)%M*b)%M)%M;
	}
	return sum;
}
vector<int> solve(vector<int> ks, vector<int> ls, vector<int> ns)
{
	vector<int> ans;
	int n = ks.size();
	for(int i=0;i<n;i++)
	{
		
		ans.push_back(get(ks[i],ls[i],ns[i]));
	}
	return ans;
}

int main()
{
	
	int n;
	cin>>n;
	vector<int> ks(n);
	vector<int> ls(n);
	vector<int> ns(n);
	int i;
	for(i=0;i<n;i++)
	{
		int x;
		cin>>x;
		ks[i]=x;
	}
	for(i=0;i<n;i++)
	{
		int x;
		cin>>x;
		ls[i]=x;
	}
	for(i=0;i<n;i++)
	{
		int x;
		cin>>x;
		ns[i]=x;
	}

	vector<int> ans = solve(ks,ls,ns);
	cout<<"O/P: \n";
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
/*
4
2 1 2 3
2 1 2 3
3 1 2 3
*/