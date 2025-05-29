/*
Problem: Find the number of distinct elements present in the intersection of two unsorted arrays.
Approach:
1. Naive: For each element in the first array, check if it appears in the second and hasn't been counted before. O(n*m)
2. HashMap: Count frequencies in both arrays, then count common keys. O(n+m)
3. HashSet: Insert all elements of the first array into a set, then for each element in the second, if present in set, count and remove. O(n+m)
*/
import java.util.*;

public class L8_Intersection_of_unsorted_array {
    // Method 1: Naive
    static int intersectionNaive(int[] a, int[] b) {
        int res = 0;
        for (int i = 0; i < a.length; i++) {
            boolean flag = false;
            for (int j = 0; j < i; j++) {
                if (a[i] == a[j]) {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            for (int value : b) {
                if (a[i] == value) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
    // Method 2: HashMap
    static int intersectionHashMap(int[] a, int[] b) {
        Map<Integer, Integer> u = new HashMap<>();
        Map<Integer, Integer> v = new HashMap<>();
        for (int value : a) u.put(value, u.getOrDefault(value, 0) + 1);
        for (int value : b) v.put(value, v.getOrDefault(value, 0) + 1);
        int count = 0;
        for (int key : u.keySet()) {
            if (v.containsKey(key)) count++;
        }
        return count;
    }
    // Method 3: HashSet
    static int intersectionSet(int[] a, int[] b) {
        Set<Integer> s = new HashSet<>();
        for (int value : a) s.add(value);
        int res = 0;
        for (int value : b) {
            if (s.contains(value)) {
                res++;
                s.remove(value);
            }
        }
        return res;
    }
    public static void main(String[] args) {
        int[] a = {10, 15, 20, 5, 30, 80, 80};
        int[] b = {30, 5, 30, 80};
        System.out.println("Method 3 (Set): Intersection count = " + intersectionSet(a, b));
        System.out.println("Method 2 (HashMap): Intersection count = " + intersectionHashMap(a, b));
        System.out.println("Method 1 (Naive): Intersection count = " + intersectionNaive(a, b));
    }
} 