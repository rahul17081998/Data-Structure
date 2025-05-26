// Date: 25/08/2022
// Easy
// LeeCode

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        // store the odd index value to odd_v: sort in decreasing order
        // store the even index value to even_v vector : sort in incresing order
        vector<int> odd_v, even_v;
        for(int i=0; i<nums.size(); i++)
        {
            if(i==0 || i%2==0) // even index
                even_v.push_back(nums[i]);
            else
                odd_v.push_back(nums[i]);
        }
        
        sort(even_v.rbegin(), even_v.rend()); // decresing order [we will take values from back side thatswhy i sorted in reverse order]
        sort(odd_v.begin(), odd_v.end()); // increasing order [we will take values from back side thatswhy i sorted in reverse order]
        
        for(int i=0; i<nums.size(); i++)
        {
            if(i==0 || i%2==0) // even index
            {
                nums[i]=even_v.back();
                even_v.pop_back();
            }
                       
            else
            {
                nums[i]=odd_v.back();
                odd_v.pop_back();
            }
                
        }
        
        return nums;
    }
};

int main(){
    // input
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(9);
    nums.push_back(1);
    nums.push_back(8);

    Solution ob;
    vector<int> out=ob.sortEvenOdd(nums);
    // print output
    for(int x: nums)
        cout<<x<<" ";
    return 0;
}
/*
input:
3 5 2 9 1 8
output
1 9 2 8 3 5
*/