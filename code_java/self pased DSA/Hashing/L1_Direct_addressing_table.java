/*
Problem: Implement a direct addressing table for integer keys in a fixed range.
Approach:
- Use a boolean array (or int array) to represent the presence of keys. Insert, delete, and search are O(1).
*/
public class L1_Direct_addressing_table {
    static class DAT {
        boolean[] table = new boolean[1000];
        void insert(int i) { table[i] = true; }
        void del(int i) { table[i] = false; }
        boolean search(int i) { return table[i]; }
    }
    public static void main(String[] args) {
        DAT dat = new DAT();
        dat.insert(10);
        dat.insert(20);
        dat.insert(119);
        System.out.println(dat.search(10));
        System.out.println(dat.search(20));
        dat.del(119);
        System.out.println(dat.search(119));
    }
} 