/*
Problem: Given an integer array nums and an integer diff, return the number of unique arithmetic triplets (i, j, k) such that i < j < k and nums[j] - nums[i] == diff and nums[k] - nums[j] == diff.
Approach:
- For each element x, check if x+diff and x-diff exist in the array using a HashMap. O(n)
*/
import java.util.*;

public class NumberOfArithmeticTriplets {
    static int arithmeticTriplets(int[] nums, int diff) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < nums.length; i++) mp.put(nums[i], i);
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            if (mp.containsKey(nums[i] + diff) && mp.containsKey(nums[i] - diff)) ans++;
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] nums = {0, 1, 4, 6, 7, 10};
        int diff = 3;
        System.out.println(arithmeticTriplets(nums, diff));
    }
} 