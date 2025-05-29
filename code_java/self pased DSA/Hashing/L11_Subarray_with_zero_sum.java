/*
Problem: Check if there exists a subarray with sum zero in an array.
Approach:
1. Naive: Check all subarrays. O(n^2)
2. Efficient: Use prefix sum and HashSet to check for sum zero in O(n).
*/
import java.util.*;

public class L11_Subarray_with_zero_sum {
    // Naive method
    static boolean isSumZero(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int sum = 0;
            if (arr[i] == 0) return true;
            for (int j = i; j < arr.length; j++) {
                sum += arr[j];
                if (sum == 0) return true;
            }
        }
        return false;
    }
    // Efficient method
    static boolean isZeroSubarraySum(int[] arr) {
        Set<Integer> h = new HashSet<>();
        int pre_sum = 0;
        for (int value : arr) {
            pre_sum += value;
            if (h.contains(pre_sum) || pre_sum == 0) return true;
            h.add(pre_sum);
        }
        return false;
    }
    public static void main(String[] args) {
        int[] arr = {1, 4, 13, -3, -10, 5};
        System.out.println(isSumZero(arr));
        System.out.println(isZeroSubarraySum(arr));
    }
} 