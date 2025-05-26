/*
I/p: a[]={10,12,15}
     b[]={18,12}
O/p:    4
*/
#include<iostream>
#include<unordered_set>
using namespace std;
// effective method
void unionTwo(int a[],int b[],int n,int m)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(b[i]);
    }
    cout<<"Effective method\nsize -->"<<s.size()<<endl<<endl;
}
// Naive method
void mergesort(int a[],int b[],int n,int m)
{
    int temp[n+m];
    for (int i = 0; i < n; i++)
    {
        temp[i]=a[i];
    }
    for (int i = 0; i < m; i++)
    {
        temp[i+n]=b[i];
    }
    cout<<"after merge array -->";
    for (int i = 0; i < m+n; i++)
    {
        cout<<temp[i]<<" ";
    }
    sort(temp,temp+n+m);
    cout<<"\nafter sorting -->";
    for (int i = 0; i < m+n; i++)
    {
        cout<<temp[i]<<" ";
    }
    int arr[m+n];
    int count=0;
    for (int i = 0; i < m+n; i++)
    {
        if(temp[i]!=temp[i+1])
        {
            arr[count]=temp[i];
            count++;
        }

    }
    if(temp[m+m-1]!=temp[m+n-2])
        arr[count]=temp[m+n-1];
    cout<<"\nunoin  -->";
    for (int i = 0; i < count; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nsize -->"<<count<<endl;
}
int main(){
    int a[]={10,12,15};
    int b[]={18,12};
    int n =sizeof(a)/sizeof(a[0]);
    int m =sizeof(b)/sizeof(b[0]);
    unionTwo(a,b,n,m);
    mergesort(a,b,n,m);
    return 0;
}