/*
Problem Summary:
Given an integer array nums and an integer k, determine if the array contains a "good" subarray.
A "good" subarray has:
- length at least 2
- sum of elements is a multiple of k (including zero)

Approach:
- Use prefix sums and their modulo k remainders.
- If at two different indices the prefix sums have the same remainder modulo k,
  then the subarray between those indices sums to a multiple of k.
- Handle the special case when k=0 by checking for at least two consecutive zeros.
- Use a HashMap to store the earliest occurrence index of each remainder.
- If we find the same remainder again and the subarray length is at least 2, return true.
- Otherwise, return false.
*/

import java.util.HashMap;

public class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        // Corner case: if k is 0, check if there are at least two consecutive zeros
        if (k == 0) {
            for (int i = 1; i < nums.length; i++) {
                if (nums[i] == 0 && nums[i - 1] == 0) {
                    return true;
                }
            }
            return false;
        }

        HashMap<Integer, Integer> remainderIndexMap = new HashMap<>();
        remainderIndexMap.put(0, -1); // remainder 0 at index -1 to handle prefix sums divisible by k

        long sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            int remainder = (int)(sum % k);

            // If remainder seen before and subarray length > 1, return true
            if (remainderIndexMap.containsKey(remainder)) {
                if (i - remainderIndexMap.get(remainder) > 1) {
                    return true;
                }
            } else {
                remainderIndexMap.put(remainder, i);
            }
        }

        return false;
    }
}