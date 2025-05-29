/*
Problem: Find the length of the longest subarray with a given sum.
Approach:
1. Naive: Check all subarrays. O(n^2)
2. Efficient: Use prefix sum and HashMap to store first occurrence of prefix sums. O(n)
*/
import java.util.*;

public class L13_Longest_subarray_with_given_sum {
    // Naive method
    static int longestSubarraySum(int[] arr, int x) {
        int res = 0;
        for (int i = 0; i < arr.length; i++) {
            int sum1 = 0;
            for (int j = i; j < arr.length; j++) {
                sum1 += arr[j];
                if (sum1 == x) res = Math.max(res, j - i + 1);
            }
        }
        return res;
    }
    // Efficient method
    static int longestSubarraySumEfficient(int[] arr, int sum) {
        Map<Integer, Integer> m = new HashMap<>();
        int pre_sum = 0, res = 0;
        for (int i = 0; i < arr.length; i++) {
            pre_sum += arr[i];
            if (pre_sum == sum) res = i + 1;
            if (!m.containsKey(pre_sum)) m.put(pre_sum, i);
            if (m.containsKey(pre_sum - sum)) res = Math.max(res, i - m.get(pre_sum - sum));
        }
        return res;
    }
    public static void main(String[] args) {
        int[] arr = {3, 1, 1, 8, 2, 3, 6};
        int sum = 5;
        System.out.println(longestSubarraySum(arr, sum));
        System.out.println(longestSubarraySumEfficient(arr, sum));
    }
} 