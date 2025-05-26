/*
You are given a 0-indexed integer array nums.

The concatenation of two numbers is the number formed by concatenating their numerals.

For example, the concatenation of 15, 49 is 1549.
The concatenation value of nums is initially equal to 0. Perform this operation until nums becomes empty:

If there exists more than one number in nums, pick the first element and last element in nums respectively and add the value of their concatenation to the concatenation value of nums, then delete the first and last element from nums.
If one element exists, add its value to the concatenation value of nums, then delete it.
Return the concatenation value of the nums.

*/


class Solution {
public:
    int doconCal(int n1, int n2){
        // find how many digit n2 have
        int count=1;
        int temp = n2;
        while(n2>0){
            n2 = n2/10;
            count = count*10;
        }
        return n1*count+temp;
    }

    long long findTheArrayConcVal(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        long long conVal=0;
        int s=0, e=nums.size()-1;
        while(s<=e){
            if(s!=e){
                conVal += doconCal(nums[s], nums[e]);
                s++; e--;
            }
            else{
                conVal += nums[s];
                s++;
            }
        }
        return conVal;


    }
};