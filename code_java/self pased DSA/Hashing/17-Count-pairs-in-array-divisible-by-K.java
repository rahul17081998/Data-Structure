/*
Problem: Given an array A[] and positive integer K, count total number of pairs whose sum is divisible by K.
Approach:
- For each element, compute its remainder with K. For each new element, count how many previous elements have the complementary remainder. Use a HashMap to store remainder counts.
*/
import java.util.*;

public class CountPairsDivisibleByK {
    static long countKdivPairs(int[] A, int K) {
        Map<Integer, Integer> mp = new HashMap<>();
        long ans = 0;
        for (int value : A) {
            int r = value % K;
            int c = (K - r) % K;
            if (mp.containsKey(c)) ans += mp.get(c);
            else if (r == 0) ans += mp.getOrDefault(0, 0);
            mp.put(r, mp.getOrDefault(r, 0) + 1);
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] A = {2, 2, 1, 7, 5, 3};
        int K = 4;
        System.out.println(countKdivPairs(A, K));
    }
} 