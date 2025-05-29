/*
Problem: Demonstrate basic operations of unordered_map (C++)/HashMap (Java) such as insertion, iteration, search, erase, and size.
Approach:
- Use Java's HashMap to perform similar operations as C++ unordered_map.
*/
import java.util.*;

public class L5_Unordered_map_in_Java {
    public static void main(String[] args) {
        Map<String, Integer> m = new HashMap<>();
        // Insert elements
        m.put("gfg", 20);
        m.put("ide", 30);
        m.put("course", 12);
        m.put("geeks", 35);
        // Iterate method 1
        for (Map.Entry<String, Integer> x : m.entrySet())
            System.out.println(x.getKey() + " " + x.getValue());
        // Iterate method 2
        System.out.println("\nMethod 2: To iterate the loop");
        for (String key : m.keySet())
            System.out.println(key + " " + m.get(key));
        // Search element using containsKey
        if (m.containsKey("ide"))
            System.out.println("Found");
        else
            System.out.println("Not Found");
        // Search element using get
        if (m.get("rfj") != null)
            System.out.println("Found");
        else
            System.out.println("Not Found");
        System.out.println("size " + m.size());
        m.remove("ide");
        System.out.println("size after erase " + m.size());
        // Remove first element (no direct equivalent, so remove by key)
        Iterator<String> it = m.keySet().iterator();
        if (it.hasNext()) {
            String firstKey = it.next();
            m.remove(firstKey);
        }
        System.out.println("size after erase beginning " + m.size());
        m.clear();
        System.out.println("size after erase everything " + m.size());
    }
} 