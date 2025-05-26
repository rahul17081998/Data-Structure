/**/
#include<bits/stdc++.h>
using namespace std;

bool myComp(pair<int,int> a, pair<int,int> b){
    // if a.second is smaller the place it first
    // smaller finish time comes first
    return (a.second<b.second);
}

int maxActivity(pair<int,int> arr[], int n){
    sort(arr,arr+n,myComp);
    int prev=0;     // first activity
    int res=1; // first activity which is always considered)
    for(int curr=1; curr<n; curr++){    // loop starts with 2nd job, 1st always considered
        if(arr[curr].first >= arr[prev].second){
            res++;
            prev=curr;
        }
    }
    return res;

}

int main(){
    cout<<"Maximum number of activity that can\nhappen on a single tasking machine\n";
    pair<int,int> arr1[]={make_pair(2,3),make_pair(1,4),make_pair(5,8),make_pair(6,10)};
    int n1 = 4;
    cout<<"For 1st input: " <<maxActivity(arr1, n1)<<" \n";
    
    pair<int,int> arr2[]={make_pair(1,3),make_pair(2,4),make_pair(3,8),make_pair(10,11)};
    int n2 = 4;
    cout<<"For 2nd input: "<<maxActivity(arr2,n2)<<" \n";
    return 0;
}