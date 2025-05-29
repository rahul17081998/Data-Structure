/*
Problem: Count the frequency of each distinct element in an array.
Approach:
1. Naive: For each element, count its frequency and mark as visited. O(n^2)
2. HashMap: Use a map to count frequencies in one pass. O(n)
*/
import java.util.*;

public class L7_Count_distict_element_frequency {
    // Method 1: HashMap
    static void countFreq(int[] arr) {
        Map<Integer, Integer> h = new HashMap<>();
        for (int value : arr) h.put(value, h.getOrDefault(value, 0) + 1);
        for (Map.Entry<Integer, Integer> entry : h.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }
    }
    public static void main(String[] args) {
        int[] arr = {10, 12, 10, 15, 10, 20, 12, 12};
        System.out.println("Using HashMap method:");
        countFreq(arr);
    }
} 