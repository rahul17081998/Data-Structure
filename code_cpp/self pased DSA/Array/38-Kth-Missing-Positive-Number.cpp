/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int>st;

        for(int i=0; i<arr.size(); i++){
            st.insert(arr[i]);
        }

        int i=1;
        int count=0;
        while(count<k){
            // check if this number is not present into the set
            if(st.find(i)==st.end()){
                count++;
            }
            if(count==k) return i;
            i++;
        }
        return -1;

    }
};

