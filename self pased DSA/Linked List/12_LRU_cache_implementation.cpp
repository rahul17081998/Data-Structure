#include <bits/stdc++.h>
using namespace std;

class LRUCache{
    
    public:
    class node 
    {
        public: 
        int key;
        int value;
        node * prev;
        node * next;
        
        node(int _key,int _value)
        {
            key = _key;
            value = _value;
        }
    };
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    map<int, node *> m;
    
    // Constructor for initializing the
    // cache capacity with the given value.
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node * temp)
    {
        node * dummy = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = dummy;
        dummy->prev = temp;
    }
    
    void deletenode(node * temp)
    {
        node * delnext = temp->next;
        node * delprev = temp->prev;
        delnext->prev = delprev;
        delprev->next = delnext;
    }
    
    // This method works in O(1)
    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            node * res =  m[key];
            m.erase(key);
            int ans = res->value;
            deletenode(res);
            addnode(res);
            m[key] = head->next;
           cout << "Got the value : " << ans 
                << " for the key: " << key << "\n";
            return ans;
        }
        cout << "Did not get any value for the key: " 
             << key << "\n";
        return -1;
    }
    
    // This method works in O(1)
    void set(int key, int value)
    {
        
        cout << "Going to set the (key, value) : (" 
             << key << ", " << value << ")" << "\n";
        if (m.find(key) != m.end())
        {
            node * exist = m[key];
            m.erase(key);
            deletenode(exist);
        }
        
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        m[key] = head->next;
    }
};

// Driver code
int main()
{
    cout << "Going to test the LRU  " 
         << "Cache Implementation\n";
         
    LRUCache * cache = new LRUCache(2);

    // It will store a key (1) with value
    // 10 in the cache.
    cache->set(1, 10);

    // It will store a key (1) with value 10 in the
    // cache.
    cache->set(2, 20);
    cout << "Value for the key: 1 is "
         << cache->get(1) << "\n"; // returns 10

    // Evicts key 2 and store a key (3) with
    // value 30 in the cache.
    cache->set(3, 30);

    cout << "Value for the key: 2 is " 
         << cache->get(2) << "\n"; // returns -1 (not found)

    // Evicts key 1 and store a key (4) with
    // value 40 in the cache.
    cache->set(4, 40);
    cout << "Value for the key: 1 is "
         << cache->get(1) << "\n"; // returns -1 (not found)
    cout << "Value for the key: 3 is "
         << cache->get(3) << "\n"; // returns 30
    cout << "Value for the key: 4 is "
         << cache->get(4) << "\n"; // return 40

    return 0;
}

// TUF video solution
// This code is contributed by CoderSaty

/*

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Note:
// program is running hear something coming error due to unordered_map
// this programm is running prefectally in gfg practice
 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    // private:

    public:
    class node{
        public:
            int key;
            int val;
            node *next;
            node *prev;
            node(int newkey, int newval){
                key = newkey;
                val = newval;
            }
    };
    
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    unordered_map<int, node*> m;
    
   
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity)
    {
        // code here
        cap = capacity;
        head->next = tail;
        tail->next = head;
    }
    
    void addnode(node *newnode){
        node *temp = head ->next;
        newnode ->next = temp;;
        newnode ->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node *delnode){
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(m.find(key)!=m.end()){
            node *resnode = m[key];
            int res = resnode ->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here  
        if(m.find(key)!=m.end()){
            node *existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key, value));
        m[key] = head->next;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends

/*
input format:

2
2
SET 1 2 GET 1

output:
2
*/

