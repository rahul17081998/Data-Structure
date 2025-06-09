
/**
 * Problem: Demonstrate usage of Map in Java, equivalent to C++ STL `map`.
 *
 * Features:
 * - Insert key-value pairs into a HashMap.
 * - Understand behavior when inserting duplicate keys.
 * - Use different methods to update values.
 * - Demonstrate behavior of accessing a non-existing key.
 * - Use iterator to traverse and print the map.
 * - Clear all elements from the map.
 *
 * Approach:
 * We use Java's HashMap which maps keys to values and does not maintain order.
 * - `put(k, v)` is used to insert or update values.
 * - `getOrDefault(k, default)` is used to mimic behavior of accessing keys that may not exist.
 * - `get(k)` retrieves the value, returns null if key doesn't exist.
 * - `entrySet()` is used to iterate through key-value pairs.
 *
 * Why this approach:
 * HashMap offers average-case O(1) time complexity for insertions, deletions, and lookups.
 * It behaves similarly to unordered_map in C++, and can simulate the behavior of `map` with sorted order using TreeMap.
 *
 * This approach works because it covers basic map operations using idiomatic Java code
 * while preserving logical functionality from the C++ example.
 */

import java.util.*;

public class MapDemo {
    public static void main(String[] args) {
        Map<Integer, Integer> m = new HashMap<>();

        m.put(10, 200);
        m.put(5, 100);
        m.put(3, 300);
        m.put(6, 600);
        m.put(8, 800);
        m.put(7, 700);
        m.putIfAbsent(3, 400);  // won't override existing key

        System.out.println("Size: " + m.size());
        System.out.println("If key is not present in map container: " + m.getOrDefault(20, 0));
        System.out.println("Size: " + m.size());

        m.put(10, 500);  // update key 10
        m.put(6, 300);   // update key 6

        // safely access key 7
        if (m.containsKey(7)) {
            System.out.println("search an element if present return value: " + m.get(7));
        }

        System.out.println("Print values using iterators");
        for (Map.Entry<Integer, Integer> entry : m.entrySet()) {
            System.out.println(entry.getKey() + " : " + entry.getValue());
        }

        m.clear();
        System.out.println("Size after clear: " + m.size());
    }
}