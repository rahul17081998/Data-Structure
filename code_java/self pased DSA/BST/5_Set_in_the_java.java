
/**
 * Problem: Demonstrate usage of Set in Java, equivalent to C++ STL `set`.
 *
 * Features:
 * - Insert elements into a TreeSet.
 * - Understand that duplicates are automatically ignored.
 * - Use `clear()` to remove all elements.
 * - Demonstrate lower_bound and upper_bound equivalent using TreeSet methods.
 * - Find and erase elements.
 * - Check existence of elements using `contains`.
 * - Use iterator and reverse iterator to traverse the set.
 *
 * Approach:
 * We use `TreeSet` in Java which maintains elements in sorted order (natural ordering).
 * - `add()` is used to insert elements.
 * - `higher(x)` gives strict upper bound (similar to `upper_bound` in C++).
 * - `ceiling(x)` gives lower bound (like `lower_bound` in C++).
 * - `contains(x)` checks for presence.
 * - `remove()` deletes an element.
 *
 * Why this approach:
 * TreeSet in Java is a Red-Black Tree internally, providing O(log n) time for insertion, deletion, and lookup.
 * This closely matches the behavior of C++ `set`.
 *
 * This approach works because TreeSet inherently supports the operations needed
 * while preserving the order and uniqueness of elements.
 */

import java.util.*;

public class SetDemo {
    public static void main(String[] args) {
        TreeSet<Integer> st = new TreeSet<>();
        st.add(10);
        st.add(5);
        st.add(20);
        st.add(7);
        st.clear();  // clear all elements

        for (int x : st) {
            System.out.print(x + " ");
        }
        System.out.println();

        TreeSet<Integer> s = new TreeSet<>();
        s.add(10);
        s.add(5);
        s.add(34);
        s.add(24);
        s.add(7);
        s.add(50);
        // duplicates are ignored by TreeSet

        // lower_bound equivalent
        Integer lb = s.ceiling(7);
        if (lb != null)
            System.out.println(lb);
        else
            System.out.println("Given element is greater than highest element in set");

        // upper_bound equivalent
        Integer ub = s.higher(7);
        if (ub != null)
            System.out.println(ub);
        else
            System.out.println("Given element is greater than highest element in set");

        // find and erase elements >= 7
        SortedSet<Integer> tail = s.tailSet(7);
        if (s.contains(7)) {
            s.removeAll(tail);
            System.out.println("Found");
        } else {
            System.out.println("Not found");
        }

        for (int val : s) {
            System.out.print(val + " ");
        }
        System.out.println();

        // check if element exists
        if (s.contains(20)) {
            System.out.println("found");
        } else {
            System.out.println("Not found");
        }

        s.remove(5); // remove value

        // reverse iteration
        Iterator<Integer> revIt = s.descendingIterator();
        while (revIt.hasNext()) {
            System.out.print(revIt.next() + " ");
        }
        System.out.println();
    }
}