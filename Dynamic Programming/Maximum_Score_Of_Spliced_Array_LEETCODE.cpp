class Solution {
public:
    // kadane algorithm: maximum consecutive sum
    int maxConsecutiveSum(vector<int> temp)
    {
        int res=0;
        int sum=0;
        for(int i=0; i<temp.size(); i++)
        {
            sum += temp[i];
            res = max(res, sum);
            if(sum < 0)
                sum=0;
            
        }
        return res;
    }
    
    // get maximum profit array after swaping the elements
    vector<int> getProfitArray(vector<int> arr1, vector<int> arr2)
    {
        vector<int> ans;
        // let arr1 as a base array
        for(int i=0; i<arr1.size(); i++)
        {
            ans.push_back(arr2[i]-arr1[i]);
        }
        return ans;
    }
    
    // main function
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1=0, sum2=0; 
        // calculate sum of all element of array and array2 and store into sum1 and sum2
        for(int i=0; i<nums1.size(); i++)
        {
            sum1 += nums1[i];
            sum2 += nums2[i];
        }
        
        // find profit array for both the input array
        vector<int> temp1, temp2;
        // assume nums1 as a base array
        temp1 = getProfitArray(nums1, nums2);
        // assume nums2 as a base array
        temp2 = getProfitArray(nums2, nums1);
        
        // apply kadane algorithm on temp1 and temp2 and find maximum consecutive that can we get
        int profitSum1 = maxConsecutiveSum(temp1);
        int profitSum2 = maxConsecutiveSum(temp2);
        
        // update the sum1 and sum2
        sum1 = sum1 + profitSum1;
        sum2 = sum2 + profitSum2;
        
        return max(sum1, sum2);
       
    }
};
