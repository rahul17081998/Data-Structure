/*
knapsack problem 

    pair:
    first-->weight
    second-->value
    sort on the basis of (value/weight) in decresing order
    */


#include<bits/stdc++.h>
using namespace std;
//  compair value/weight 
bool myComp(pair<int,int> a, pair<int,int> b){
    double x1 = (double)a.second/a.first;
    double x2 = (double)b.second/b.first;
    return x1>x2;
}
double knapsackMax(pair<int,int> arr[], int n, double given_cap)
{
    double res=0;
    sort(arr,arr+n,myComp);  // sorting 
    double curr_cap = given_cap;
    for(int i=0; i<n; i++)
    {
        if(arr[i].first <= curr_cap)
        {
            curr_cap=curr_cap-arr[i].first;
            res=res+arr[i].second;
        }
        else
        {
            res = res+arr[i].second*(curr_cap/arr[i].first);
            return res;
        }
    }
    return res;

}
int main(){
    
    pair<int,int> arr[] = {make_pair(50,600), make_pair(20,500), make_pair(30,400)};
    int n=3;
    double capacity = 70;
    cout<<"maximum value in knapsack having "<<capacity<<":"<<knapsackMax(arr,n,capacity);
    return 0;
}