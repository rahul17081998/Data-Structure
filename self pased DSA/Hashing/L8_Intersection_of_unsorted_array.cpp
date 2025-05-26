#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
// Effective method 2
int InteruseSet(int a[],int b[],int n,int m)
{
    int res=0;
    unordered_set<int> s(a,a+n);
    for (int i = 0; i < m; i++)
    {
        if(s.find(b[i])!=s.end())
            res++;
            s.erase((b[i]));
    }
    return res;
} 
// Effective method 1
int intersections(int a[],int b[],int n,int m)
{
    unordered_map<int,int> u; 
    unordered_map<int,int> v;
    for (int i = 0; i < n; i++)
    {
        u[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        v[b[i]]++;
    }

    int count=0;
    for(auto x:u)
        for(auto y:v)
            if(x.first==y.first)
                count++;
    return count;
} 
// Naive method
int InterSection(int a[],int b[], int n, int m)
{
    int res=0;
    for (int i = 0; i < n; i++)
    {
        bool flag=false;
        for (int j = 0; j < i; j++)
        {
            if(a[i]==a[j])
            {
                flag = true;
                break;
            }
        }
        if(flag==true)
            continue;
        for (int j = 0; j < m; j++)
        {
            if(a[i]==b[j])
            {
                res++;
                break;
            }
        }
    }
    return res;
    
}
int main(){
    int a[]={10,15,20,5,30,80,80};
    int b[]={30,5,30,80};
    int n =sizeof(a)/sizeof(a[0]);
    int m =sizeof(b)/sizeof(b[0]);
    cout<<"Effective method 2\nIntersection of two arrays distinct no of elements "<<InteruseSet(a,b,n,m)<<endl;
    cout<<"Effective method 1\nIntersection of two arrays distinct no of elements "<<intersections(a,b,n,m)<<endl;
    cout<<"Naive method\nIntersection of two arrays distinct no of elements "<<InterSection(a,b,n,m)<<endl;
    return 0;
}