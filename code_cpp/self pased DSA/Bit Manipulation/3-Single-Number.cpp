#include<bits/stdc++.h>
using namespace std;

//write your function here
/*
Approach:
As we know the property of xor operation that xor of two same number have 0 and different have 1
we will use here becase in our array except one element every other element have 1 more duplice value so that will cancile each other and finally we will get that single value as answer 
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = nums[0];
        for(int i=1; i<nums.size(); i++)
            ans = ans ^ nums[i]; // do xor operation
        return ans;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(14);
    nums.push_back(12);
    nums.push_back(3);
    nums.push_back(12);
    nums.push_back(14);
    Solution ob;
    cout<<ob.singleNumber(nums)<<endl;
    // o/p = 3
    return 0;
}