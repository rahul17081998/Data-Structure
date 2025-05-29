/*
Problem: Check if there exists a subarray with a given sum in an array.
Approach:
1. Naive: Check all subarrays. O(n^2)
2. Efficient: Use prefix sum and HashSet to check for the sum in O(n).
*/
import java.util.*;

public class L12_Subarray_with_given_sum {
    // Naive method
    static boolean isSumZero(int[] arr, int x) {
        for (int i = 0; i < arr.length; i++) {
            int sum1 = 0;
            if (arr[i] == 0) return true;
            for (int j = i; j < arr.length; j++) {
                sum1 += arr[j];
                if (sum1 == x) return true;
            }
        }
        return false;
    }
    // Efficient method
    static boolean isZeroSubarraySum(int[] arr, int sum) {
        Set<Integer> h = new HashSet<>();
        int pre_sum = 0;
        for (int value : arr) {
            pre_sum += value;
            if (pre_sum == sum) return true;
            if (h.contains(pre_sum - sum)) return true;
            h.add(pre_sum);
        }
        return false;
    }
    public static void main(String[] args) {
        int[] arr = {1, 4, 13, -3, -10, 5};
        int sum = 14;
        System.out.println(isSumZero(arr, sum));
        System.out.println(isZeroSubarraySum(arr, sum));
    }
} 