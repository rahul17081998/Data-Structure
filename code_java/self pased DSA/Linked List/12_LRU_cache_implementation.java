

/**
 * Problem Statement:
 * Implement a Least Recently Used (LRU) Cache that supports the following operations:
 * - get(key): Fetch the value of the key if it exists in the cache, otherwise return -1.
 * - set(key, value): Insert or update the value of the key. If the cache reaches its capacity,
 *   remove the least recently used item before inserting the new item.
 *
 * Constraints:
 * - Each operation must be done in O(1) time complexity.
 *
 * Approach:
 * - Use a combination of a HashMap and a Doubly Linked List.
 * - The Doubly Linked List stores the elements in the order of their usage,
 *   with the most recently used at the front and least recently used at the back.
 * - The HashMap provides O(1) access to any node in the list based on the key.
 *
 * Time Complexity:
 * - get: O(1)
 * - set: O(1)
 *
 * Space Complexity:
 * - O(capacity) for the HashMap and the linked list nodes.
 */

import java.util.*;

class LRUCache {
    class Node {
        int key;
        int value;
        Node prev;
        Node next;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    private Node head;
    private Node tail;
    private int capacity;
    private Map<Integer, Node> map;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head.next = tail;
        tail.prev = head;
    }

    private void addNode(Node node) {
        Node temp = head.next;
        head.next = node;
        node.prev = head;
        node.next = temp;
        temp.prev = node;
    }

    private void deleteNode(Node node) {
        Node prevNode = node.prev;
        Node nextNode = node.next;
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    }

    public int get(int key) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            deleteNode(node);
            addNode(node);
            map.put(key, head.next);
            System.out.println("Got the value : " + node.value + " for the key: " + key);
            return node.value;
        }
        System.out.println("Did not get any value for the key: " + key);
        return -1;
    }

    public void set(int key, int value) {
        System.out.println("Going to set the (key, value) : (" + key + ", " + value + ")");
        if (map.containsKey(key)) {
            Node existing = map.get(key);
            map.remove(key);
            deleteNode(existing);
        }

        if (map.size() == capacity) {
            map.remove(tail.prev.key);
            deleteNode(tail.prev);
        }

        Node newNode = new Node(key, value);
        addNode(newNode);
        map.put(key, head.next);
    }

    public static void main(String[] args) {
        System.out.println("Going to test the LRU Cache Implementation");

        LRUCache cache = new LRUCache(2);

        cache.set(1, 10);
        cache.set(2, 20);
        System.out.println("Value for the key: 1 is " + cache.get(1)); // returns 10

        cache.set(3, 30); // evicts key 2
        System.out.println("Value for the key: 2 is " + cache.get(2)); // returns -1

        cache.set(4, 40); // evicts key 1
        System.out.println("Value for the key: 1 is " + cache.get(1)); // returns -1
        System.out.println("Value for the key: 3 is " + cache.get(3)); // returns 30
        System.out.println("Value for the key: 4 is " + cache.get(4)); // returns 40
    }
}