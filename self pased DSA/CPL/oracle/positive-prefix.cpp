#include<bits/stdc++.h>
using namespace std;

int maxPosPrefix(vector<int> arr){
    int n = arr.size();
    // rearrange the array 
    vector<int> left, right;
    for(int i=0; i<n; i++){
        if(arr[i]>0)
            left.push_back(arr[i]);
        else{
            right.push_back(arr[i]);
        }
    }

    sort(right.rbegin(), right.rend());

    for(int i=0; i<left.size(); i++){
        arr[i]=left[i];
    }

    for(int i=0; i<right.size(); i++){
        arr[i+left.size()]=right[i];
    }

    if(arr[0]<0) return 0;
    vector<int> prefixSum(n, 0);
    prefixSum[0] = arr[0];
    int count=1;


    for(int i=1; i<n; i++){
        prefixSum[i] = prefixSum[i-1]+arr[i];
        if(prefixSum[i]<0) return count;
        count++;
    }
    return count;

}


int main(){

    vector<int> arr;
    arr.push_back(-6);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(-10);

    cout<<maxPosPrefix(arr);
    return 0;
}