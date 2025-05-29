/*
Problem: Demonstrate basic operations of unordered_set (C++)/HashSet (Java) such as insertion, iteration, search, erase, and size.
Approach:
- Use Java's HashSet to perform similar operations as C++ unordered_set.
*/
import java.util.*;

public class L4_Unordered_set_in_Java {
    public static void main(String[] args) {
        Set<Integer> s = new HashSet<>();
        s.add(10);
        s.add(51);
        s.add(5);
        s.add(20);
        s.add(30);
        s.add(24);
        // HashSet does not maintain order
        for (int x : s)
            System.out.print(x + " ");
        System.out.println("\nOther way to iterate");
        for (Iterator<Integer> it = s.iterator(); it.hasNext(); ) {
            System.out.print(it.next() + " ");
        }
        System.out.println();
        // find() equivalent: contains
        if (!s.contains(51))
            System.out.println("Not found");
        else
            System.out.println("found 51");
        // count() equivalent: contains
        if (s.contains(20))
            System.out.println("Found");
        else
            System.out.println("Not Found");
        System.out.println("Size before erase " + s.size());
        s.remove(5);
        System.out.println("Size after erase " + s.size());
        s.remove(24);
        System.out.println("Size after again erase " + s.size());
        s.clear();
        System.out.println("After clearing size " + s.size());
    }
} 