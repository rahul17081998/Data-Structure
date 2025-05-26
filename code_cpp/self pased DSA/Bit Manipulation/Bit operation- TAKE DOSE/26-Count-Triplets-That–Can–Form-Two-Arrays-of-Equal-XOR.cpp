/*
Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

 

Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)

*/


class Solution {
public:
 
    /*  
    Explanation for approach Method 2:
    you have an array : a[0], a[1].... a[n - 1]

    First things first:
    We need to understand small fact, if xor(a[0....i]) has appeared before at 
    index j then it means xor(a[j+1.....i]) = 0
    Another fact, if xor(a[i....j]) = 0 so this subarray will add (j - i - 1) to the answer.
    Now say currently we are at index i and let xor([0...i]) = x.
    Now say x has occurred 3 times previously at indices (i1, i2, i3)
    our answer for i will be = (i - i1 - 1) + (i - i2 - 1) + (i - i3 - 1)

    if you simplify this further you get 
    f * i - (i1 + i2 + i3) - f 
    => (i - 1) * f - (i1 + i2 + i3)

    f = no. of times x has occurred previously.
    (i1 + i2 + i3) = sum of all the indices where x has occurred previously.
    */

    // method2: Optimized method/ Hashmap used/TC = O(N)
    int countTriplets(vector<int>& arr){
        unordered_map<int, pair<int,int>> xorMap; // x --> {cnt, sum of starts}
        xorMap[0]=make_pair(1, 0); // by default if x=0, then total triplates = 1*i

        int ans = 0;
        int x =0;
        for(int i=0; i<arr.size(); i++){
            x ^=arr[i];
            if(xorMap.find(x)!=xorMap.end()){
                int cnt = xorMap[x].first;
                int sum = xorMap[x].second;
                ans += i*cnt - sum;
            }
            xorMap[x].first++;
            xorMap[x].second += (i+1);
        }
        return ans;
    }




    /* 
    // Method1: TC = O(N^2)
    int countTriplets(vector<int>& arr) {
        int ans=0;
        for(int i=0; i<arr.size(); i++){
            int val=arr[i];
            int cnt=0;
            for(int k=i+1; k<arr.size(); k++){
                val = val^arr[k];
                if(val==0){
                    ans += (k-i);
                }
            }
        }
        return ans;
    } 
    */



};
