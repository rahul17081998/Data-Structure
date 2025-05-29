/*
Problem: Given an array nums and integer k, count the number of pairs (i, j) such that i < j and nums[i] * nums[j] is divisible by k.
Approach:
- For each number, compute gcd with k. For each previous gcd, if their product is divisible by k, count the pairs. Use a HashMap to store gcd frequencies.
*/
import java.util.*;

public class CountArrayPairsDivisibleByK {
    static long gcd(int x, int y) {
        if (x < y) return gcd(y, x);
        return y == 0 ? x : gcd(y, x % y);
    }
    static long countPairs(int[] nums, int k) {
        Map<Long, Long> mp = new HashMap<>();
        long ans = 0;
        for (int value : nums) {
            long gcd1 = gcd(value, k);
            for (Map.Entry<Long, Long> entry : mp.entrySet()) {
                long gcd2 = entry.getKey();
                long count = entry.getValue();
                if ((gcd1 * gcd2) % k == 0) ans += count;
            }
            mp.put(gcd1, mp.getOrDefault(gcd1, 0L) + 1);
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5};
        int k = 2;
        System.out.println(countPairs(nums, k));
    }
} 