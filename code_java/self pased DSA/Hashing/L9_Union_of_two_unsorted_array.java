/*
Problem: Find the number of distinct elements present in the union of two unsorted arrays.
Approach:
1. Naive: Merge both arrays, sort, and count unique elements. O((n+m)log(n+m))
2. HashSet: Insert all elements from both arrays into a set. O(n+m)
*/
import java.util.*;

public class L9_Union_of_two_unsorted_array {
    // Method 1: HashSet
    static int unionSet(int[] a, int[] b) {
        Set<Integer> s = new HashSet<>();
        for (int value : a) s.add(value);
        for (int value : b) s.add(value);
        return s.size();
    }
    // Method 2: Naive (merge, sort, count unique)
    static int unionNaive(int[] a, int[] b) {
        int n = a.length, m = b.length;
        int[] temp = new int[n + m];
        System.arraycopy(a, 0, temp, 0, n);
        System.arraycopy(b, 0, temp, n, m);
        Arrays.sort(temp);
        int count = 1;
        for (int i = 1; i < temp.length; i++) {
            if (temp[i] != temp[i - 1]) count++;
        }
        return count;
    }
    public static void main(String[] args) {
        int[] a = {10, 12, 15};
        int[] b = {18, 12};
        System.out.println("Method 1 (Set): Union size = " + unionSet(a, b));
        System.out.println("Method 2 (Naive): Union size = " + unionNaive(a, b));
    }
} 