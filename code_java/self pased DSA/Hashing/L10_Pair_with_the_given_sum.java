/*
Problem: Check if there exists a pair in the array with a given sum.
Approach:
- Use a HashSet to store visited elements. For each element, check if (sum - element) exists in the set. O(n)
*/
import java.util.*;

public class L10_Pair_with_the_given_sum {
    static boolean isPair(int[] arr, int sum) {
        Set<Integer> h = new HashSet<>();
        for (int value : arr) {
            int x = sum - value;
            if (h.contains(x)) return true;
            h.add(value);
        }
        return false;
    }
    public static void main(String[] args) {
        int[] arr = {3, 2, 8, 15, -8};
        int sum = 5;
        System.out.println(isPair(arr, sum));
    }
} 