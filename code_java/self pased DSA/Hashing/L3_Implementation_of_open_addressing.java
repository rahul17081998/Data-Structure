/*
Problem: Implement a hash table using open addressing (linear probing) for collision resolution.
Approach:
- Use an array to store keys. For insert/search/delete, use linear probing to resolve collisions.
*/
public class L3_Implementation_of_open_addressing {
    static class MyHash {
        int[] arr;
        int cap, size;
        MyHash(int c) {
            cap = c;
            size = 0;
            arr = new int[cap];
            for (int i = 0; i < cap; i++) arr[i] = -1;
        }
        int hash(int key) {
            return key % cap;
        }
        boolean search(int key) {
            int h = hash(key);
            int i = h;
            while (arr[i] != -1) {
                if (arr[i] == key) return true;
                i = (i + 1) % cap;
                if (i == h) return false;
            }
            return false;
        }
        boolean insert(int key) {
            if (size == cap) return false;
            int i = hash(key);
            while (arr[i] != -1 && arr[i] != -2 && arr[i] != key) {
                i = (i + 1) % cap;
            }
            if (arr[i] == key) return false;
            else {
                arr[i] = key;
                size++;
                return true;
            }
        }
        boolean erase(int key) {
            int h = hash(key);
            int i = h;
            while (arr[i] != -1) {
                if (arr[i] == key) {
                    arr[i] = -2;
                    return true;
                }
                i = (i + 1) % cap;
                if (i == h) return false;
            }
            return false;
        }
    }
    public static void main(String[] args) {
        MyHash mh = new MyHash(7);
        mh.insert(49);
        mh.insert(56);
        mh.insert(72);
        System.out.println(mh.search(49) ? "Yes" : "No");
        mh.erase(56);
        System.out.println(mh.search(56) ? "Yes" : "No");
    }
} 