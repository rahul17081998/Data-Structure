/*
Problem: Count the number of distinct elements in an array.
Approach:
- Use a HashSet to store unique elements and return its size. O(n)
*/
import java.util.*;

public class L6_count_distict_element {
    static int distinctCount(int[] arr) {
        Set<Integer> uns = new HashSet<>();
        for (int value : arr) uns.add(value);
        return uns.size();
    }
    public static void main(String[] args) {
        int[] arr = {10, 11, 12};
        System.out.println("Distinct elements: " + distinctCount(arr));
    }
} 