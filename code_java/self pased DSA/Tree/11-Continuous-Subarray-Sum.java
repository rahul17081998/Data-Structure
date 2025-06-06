/**
 * Problem Summary:
 * Given an integer array nums and an integer k, determine if there exists a "good" subarray.
 * A "good" subarray has length at least 2 and its sum is a multiple of k (including zero).
 *
 * Approach:
 * - Use prefix sums and modulo k to identify subarrays with sums divisible by k.
 * - Store the earliest index of each prefix sum remainder in a HashMap.
 * - If the same remainder appears again and the distance between indices is > 1, return true.
 * - Handle special case when k == 0 by checking for consecutive zeros.
 *
 * Why it works:
 * - If prefixSum[j] % k == prefixSum[i] % k, then sum of subarray (i+1 to j) is divisible by k.
 * - HashMap allows O(1) checks for repeated remainders.
 * - Checking distance > 1 ensures subarray length >= 2.
 */
import java.util.HashMap;

public class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        // Special case: k == 0, check for at least two consecutive zeros
        if (k == 0) {
            for (int i = 1; i < nums.length; i++) {
                if (nums[i] == 0 && nums[i - 1] == 0) {
                    return true;
                }
            }
            return false;
        }

        HashMap<Integer, Integer> remainderIndexMap = new HashMap<>();
        remainderIndexMap.put(0, -1); // remainder 0 at index -1 to handle subarrays starting at index 0

        long sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            int remainder = (int)(sum % k);

            if (remainderIndexMap.containsKey(remainder)) {
                int prevIndex = remainderIndexMap.get(remainder);
                // Check subarray length is at least 2
                if (i - prevIndex > 1) {
                    return true;
                }
            } else {
                remainderIndexMap.put(remainder, i);
            }
        }

        return false;
    }
}