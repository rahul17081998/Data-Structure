
/**
 * Problem: For each element in an array, find the smallest element on the left side of it which is greater than the current element (Ceiling on the left side).
 *
 * Input: An array of integers.
 * Output: For every element, print the ceiling element from the left side. If no such element exists, print -1.
 *
 * Example:
 * Input:  {2, 8, 30, 15, 25, 6}
 * Output: -1 -1 -1 30 30 8
 *
 * Approach:
 * - We use a TreeSet in Java to store the elements we have seen so far (left side elements).
 * - For each element in the array (starting from the second), we insert it into the TreeSet and use `higher()` to find the smallest element greater than the current one.
 * - If `higher()` returns null, print -1; otherwise, print the element.
 *
 * Why this approach:
 * - TreeSet in Java is implemented as a Red-Black Tree which maintains the elements in sorted order.
 * - It allows us to find the next higher element in O(log n) time using `higher()`.
 * - Inserting an element also takes O(log n), so the overall time complexity is O(n log n).
 *
 * This approach works efficiently because it maintains a dynamic set of previous elements and supports fast lookups for the required ceiling value.
 */

import java.util.*;

public class CeilingOnLeftSide {
    public static void ceiling(int[] arr) {
        TreeSet<Integer> s = new TreeSet<>();
        s.add(arr[0]);
        System.out.print("-1 ");
        for (int i = 1; i < arr.length; i++) {
            Integer ceil = s.higher(arr[i]);
            if (ceil == null) {
                System.out.print("-1 ");
            } else {
                System.out.print(ceil + " ");
            }
            s.add(arr[i]);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr = {2, 8, 30, 15, 25, 6};
        ceiling(arr);
    }
}