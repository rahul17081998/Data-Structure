/*
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique 
element appears at most twice. The relative order of the elements should be kept the same.
Since it is impossible to change the length of the array in some languages, you must instead have the result be 
placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, 
then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
Return k after placing the final result in the first k slots of nums.
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

class Solution {
public:
    // TC = O(N), SC = O(1)
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // Take two pointers 's' and 'e'
        int s=0,e=0;

        // Continue the loop until 'e' reaches the end of the input array
        while(e<n){
            // Store the current element
            int temp=nums[e];
            // Initialize the frequency of the current element
            int SameValuefreq=0;
            // Count the frequency of the current element
            while(e<n && nums[e]==temp){
                SameValuefreq++;
                e++;
            }

            // If the frequency is greater than or equal to 2
            if(SameValuefreq>=2){
                // Keep the first two occurrences of the current element
                nums[s]=temp;
                nums[s+1]=temp;
                // Advance the 's' pointer by 2
                s= s+2;
            }
            // If the frequency is less than 2
            else{
                // Keep all occurrences of the current element
                while(SameValuefreq-->0){
                    nums[s]=temp;
                    s++;
                }
            }

        }
        // Return the length of the new vector after duplicates have been removed
        return s;
    }
};

