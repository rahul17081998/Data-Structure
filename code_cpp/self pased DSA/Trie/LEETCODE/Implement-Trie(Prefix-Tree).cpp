/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
*/


// video link: https://www.youtube.com/watch?v=BN-SUKeOYC0
class TrieNode {
public:
    bool isEnd; // Flag to indicate end of word
    TrieNode *child[26]; // Array of pointers to child nodes for each character

    TrieNode() {
        isEnd = false;
        memset(child, 0, sizeof(child)); // Set all child pointers to NULL
    }
};

class Trie {
private:
    TrieNode *root; // Pointer to the root of the Trie

public:
    Trie() {
        root = new TrieNode(); // Create a new root node with no character value
    }
    
    // Function to insert a word into the Trie
    void insert(string word) {
        TrieNode* curr = root; // Start from the root node
        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if(curr->child[ch-'a'] == NULL) { // If the character node doesn't exist
                curr->child[ch-'a'] = new TrieNode(); // Create a new node
            }
            curr = curr->child[ch-'a']; // Move to the next child node
        }
        curr->isEnd = true; // Mark the last node as the end of a word
    }
    
    // Function to search for a word in the Trie
    bool search(string word) {
        TrieNode* curr = root; // Start from the root node
        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if(curr->child[ch-'a'] == NULL) { // If the character node doesn't exist
                return false; // The word doesn't exist in the Trie
            }
            curr = curr->child[ch-'a']; // Move to the next child node
        }
        if(curr->isEnd == false) { // If the last node isn't marked as the end of a word
            return false; // The word doesn't exist in the Trie
        }
        return true; // The word exists in the Trie
    }
    
    // Function to search for words starting with a given prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root; // Start from the root node
        for(int i = 0; i < prefix.length(); i++) {
            char ch = prefix[i];
            if(curr->child[ch-'a'] == NULL) { // If the character node doesn't exist
                return false; // No word exists in the Trie with the given prefix
            }
            curr = curr->child[ch-'a']; // Move to the next child node
        }
        return true; // At least one word exists in the Trie with the given prefix
    }
};
