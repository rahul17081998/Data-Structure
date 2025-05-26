// time complexity = O(nlogn)
// Aux.space = theta(1)
#include<bits/stdc++.h>
using namespace std;
// structure defining 
struct Interval{
    int st,end;
};
// Comprater function
bool myComp(Interval a, Interval b)
{return a.st<b.st; }

void mergeInterval(Interval arr[], int n)
{
     sort(arr,arr+n,myComp);
     int res = 0;
     for (int i = 1; i < n; i++)
     {
         if(arr[res].end>=arr[i].st)
         {
            arr[res].end= max(arr[res].end,arr[i].end);
            arr[res].st = min(arr[res].st,arr[i].st);
         }
         else{
             res++;
             arr[res]=arr[i];
         }
     }
      for (int i = 0; i <= res; i++)
      {
          cout<<"["<<arr[i].st<<","<<arr[i].end<<"] ";
      }
      
}

int main(){
    // defining interval array 
    Interval arr[]={{5,10},{3,15},{18,30},{2,7}};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeInterval(arr,n);
    return 0;
}