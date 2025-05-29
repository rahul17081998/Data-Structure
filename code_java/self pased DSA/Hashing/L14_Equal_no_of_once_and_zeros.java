/*
Problem: Find the length of the longest subarray with equal number of 0s and 1s.
Approach:
1. Naive: For each subarray, count 0s and 1s. O(n^2)
2. Efficient: Replace 0 with -1, then find the longest subarray with sum 0 using HashMap. O(n)
*/
import java.util.*;

public class L14_Equal_no_of_once_and_zeros {
    // Naive method
    static int equalOneZero(int[] arr) {
        int res = 0;
        for (int i = 0; i < arr.length; i++) {
            int ones = 0, zeros = 0;
            for (int j = i; j < arr.length; j++) {
                if (arr[j] == 0) zeros++;
                if (arr[j] == 1) ones++;
                if (ones == zeros) res = Math.max(res, ones * 2);
            }
        }
        return res;
    }
    // Efficient method
    static int equalOneZeroEfficient(int[] arr) {
        int n = arr.length;
        int[] temp = new int[n];
        for (int i = 0; i < n; i++) temp[i] = (arr[i] == 0 ? -1 : 1);
        Map<Integer, Integer> map = new HashMap<>();
        int sum = 0, maxLen = 0;
        for (int i = 0; i < n; i++) {
            sum += temp[i];
            if (sum == 0) maxLen = i + 1;
            if (map.containsKey(sum)) maxLen = Math.max(maxLen, i - map.get(sum));
            else map.put(sum, i);
        }
        return maxLen;
    }
    public static void main(String[] args) {
        int[] arr = {0, 0, 1, 0, 1, 1, 1};
        System.out.println("Naive: " + equalOneZero(arr));
        System.out.println("Efficient: " + equalOneZeroEfficient(arr));
    }
} 