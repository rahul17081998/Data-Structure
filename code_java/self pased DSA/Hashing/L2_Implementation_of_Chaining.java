/*
Problem: Implement a hash table using chaining for collision resolution.
Approach:
- Use an array of linked lists (ArrayList of LinkedLists) to store keys. Insert, search, and remove use chaining.
*/
import java.util.*;

public class L2_Implementation_of_Chaining {
    static class MyHash {
        int BUCKET;
        List<LinkedList<Integer>> table;
        MyHash(int b) {
            BUCKET = b;
            table = new ArrayList<>(b);
            for (int i = 0; i < b; i++) table.add(new LinkedList<>());
        }
        void insert(int key) {
            int i = key % BUCKET;
            table.get(i).add(key);
        }
        void remove(int key) {
            int i = key % BUCKET;
            table.get(i).remove((Integer) key);
        }
        boolean search(int key) {
            int i = key % BUCKET;
            return table.get(i).contains(key);
        }
    }
    public static void main(String[] args) {
        MyHash mh = new MyHash(7);
        mh.insert(10);
        mh.insert(20);
        mh.insert(15);
        mh.insert(7);
        System.out.println(mh.search(10));
        mh.remove(20);
        System.out.println(mh.search(20));
    }
} 