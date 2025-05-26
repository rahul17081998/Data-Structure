/*https://www.geeksforgeeks.org/maximum-bitwise-and-value-of-subsequence-of-length-k/

first find sum of all possible subarrays of size k. then using above link find maxm value of & between y subarrays. then | this with x. TC=O(n^2), because of above link. 

logic: after getting a vector of sum of all possible subarrays. we find among these ele how many ele 
have last(variable) bit as 1. last starts from 31. suppose the no of ele is >= y, then among these ele 
by reducing last by 1, we again check how many ele have (last-1) bit set. each time, if the vector returned
 from findsubset size >=y that means, all the ele of that array has last(variable) bit as 1 and now 
 next processing will happen in this new array. each time the vector returned by findsubset fucn >=y 
 that means all ele in this new array have all bits set from 31 till last. suppose at some point we 
 found last such that no of ele < y then the prev returned array is ans and if size of prev returned 
 array is >y then we take any y ele bcoz all the ele will have same set bits starting from 31 until 
 latest successful "last" bit.

eg: initially temp1 has 6 ele. last=31, y=2. suppose 5 ele have 31st bit set, then temp2=5 ele. 
temp1=5 ele, last=30. suppose 4 ele have 30th bit set, then temp2=4 ele, all these 4 ele will have 
31st and 30-th bit set. temp1=4  ele, last=29, suppose there is no two ele which have same bit set 
from (29-0) then the ans is from prev returned 4 ele, just take any 2 ele.
*/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> findSubset(vector<int>& temp, int& last, int k){
    vector<int> ans;
    // Iterate from left till 0 till we get a bit set of K numbers
    for (int i = last; i >= 0; i--) {
        int cnt = 0;
        // Count the numbers whose i-th bit is set
        for (auto it : temp) {
            int bit = it & (1 << i);
            if (bit > 0)
                cnt++;
        }
        // If the array has numbers>=k whose i-th bit is set
        if (cnt >= k) {
            for (auto it : temp) {
                int bit = it & (1 << i);
                if (bit > 0)
                    ans.push_back(it);
            }
            // Update last
            last = i - 1;
            // Return the new set of numbers, all os in this will have i-th bit set
            return ans;
        }
    }
    return ans;
}


int f(vector<int> &arr, int n, int k, int y, int x){
    vector<int> prefix_sum(n);
    prefix_sum[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix_sum[i]=arr[i]+prefix_sum[i-1];
    }
    int i=k-1;
    vector<int> a;
    int start=0;
    while(i<n){
        if(start==0)
            a.push_back(prefix_sum[i]);
        else
            a.push_back(prefix_sum[i]-prefix_sum[start-1]);
        i++;
        start++;
    }
    int last=31;
    vector<int> temp1, temp2;
    for(int i=0;i<a.size();i++){
        temp2.push_back(a[i]);
    }
    while(temp2.size()>=y){
        temp1=temp2;
        temp2 = findSubset(temp2, last, y);
    }
    int ans = temp1[0];
    for (int i = 0; i < y; i++)
        ans = ans & temp1[i];
 
    return (ans|x);
    
}

int main() {
    // vector<int> arr{5,4,2,4,9};
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(9);
    int k=2;
    int y=2;
    int x=7;
    cout<<f(arr, 5, k,y,x);
    return 0;
}