#include<bits/stdc++.h>
using namespace std;
/* Hard question: 
problem Statement:
As the ruler of a kingdom, you have an army of wizards at your command.

You are given a 0-indexed integer array strength, where strength[i] denotes the strength of 
the ith wizard. For a contiguous group of wizards (i.e. the wizards' strengths form a 
subarray of strength), the total strength is defined as the product of the following two 
values:
The strength of the weakest wizard in the group.
The total of all the individual strengths of the wizards in the group.
Return the sum of the total strengths of all contiguous groups of wizards. Since the 
answer may be very large, return it modulo 109 + 7.
A subarray is a contiguous non-empty sequence of elements within an array.

*/
class Solution {
public:
    long long mod = 1000000007;
    void leftMin(vector<int>& strength, vector<int> &left, int N)
    {
        stack<int> st;
        for(int i=0; i<N; i++){
            while(!st.empty() && strength[st.top()] >= strength[i]){
                st.pop();
            }
            left[i] = st.empty()? -1:st.top();
            st.push(i);
        }
    }
    
    void rightMin(vector<int>& strength, vector<int> &right, int N)
    {
        stack<int> st;
        for(int i=N-1; i>=0; i--){
            while(!st.empty() && strength[st.top()] > strength[i]){
                st.pop();
            }
            right[i] = st.empty()? N:st.top();
            st.push(i);
        }
    }
    
    
    int totalStrength(vector<int>& strength) {
        
        const int N=strength.size();
        // sum of first k elements
        vector<long long> prefix(N+1, 0l);
        for(int i=0; i<N; i++){
            prefix[i+1] = (prefix[i] + strength[i])%mod;
        }
        // sum of first k prefix
        vector<long long> prefix_sum(N+2, 0l);
        for(int i=0; i<=N; i++){
            prefix_sum[i+1] = (prefix_sum[i] + prefix[i])%mod;
        }
        
        // first index on left < current strength[i]
        vector<int> left(N,-1);
        leftMin(strength, left, N);
        // first index on right <= current strength[i]
        vector<int> right(N, N);
        rightMin(strength, right, N);
        
        // main calculation
        long long res = 0;
        // Problem reduced to find out the sum of all subarray where in ith element as minimum element
        // for each element of strength array consider as minimum and find sum of all the subarray
        for (int i = 0; i < N; ++i) {
            res += ((prefix_sum[right[i] + 1] - prefix_sum[i + 1]) * (i - left[i]) % mod + mod * 2 - 
                   (prefix_sum[i + 1] - prefix_sum[left[i] + 1]) * (right[i] - i) % mod) % mod * strength[i] % mod;
            res %= mod;
        }
        return (int) res;
        
    }
};


int main(){
    vector<int> strength;
    strength.push_back(1);
    strength.push_back(3);
    strength.push_back(1);
    strength.push_back(2);
    Solution ob;
    cout<<ob.totalStrength(strength)<<endl;
    return 0;
}
/*
Input: strength = [1,3,1,2]
Output: 44
*/