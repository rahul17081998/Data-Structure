#include<bits/stdc++.h>
using namespace std;


struct TrieNode{
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(int i=0; i<26; i++)
            child[i] = NULL;
    }

};
// deletion a word/string in trie
// TC = O(n) ,   where n is the length of string
bool isEmpty(TrieNode *root)
{
    for (int i = 0; i < 26; i++)
    {
        if(root->child[i]!=NULL)
            return false;
    }
    return true;
}

TrieNode *deleteKey(TrieNode *root, string key, int i)
{
    if(root == NULL) return NULL;
    if(i==key.length()){
        root->isEnd = false;
        if(isEmpty(root) == false){
            delete(root);
            root=NULL;
        }
        return root;
    }

    int index = key[i] -'a';
    root->child[index] = deleteKey(root->child[index], key, i+1);
    if(isEmpty(root) && root->isEnd==false)
    {
        delete(root);
        root=NULL;
    }
    return root;
}
// insert operation in trie data struecture
// TC = 𝜃(n) ,   where n is the length of string
void insert(TrieNode *root, string key)
{
    TrieNode *curr = root;
    for(int i=0; i<key.length(); i++)
    {
        int index = key[i] - 'a';
        if(curr->child[index]==NULL)
        {
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
    }
    curr->isEnd = true;
}
// search operation in trie data structure
// TC = O(n) ,   where n is the length of string
bool search(struct TrieNode *root, string key)
{
    TrieNode *curr = root;
    for(int i=0; i<key.length(); i++)
    {
        int index = key[i] - 'a';
        if(curr->child[index]==NULL)
        {
            return false;
        }
        curr = curr->child[index];
    }
    return (curr->isEnd);
}




int main(){
    TrieNode *root = new TrieNode();
    
    // string keys[] = {"bad", "bat", "geeks", "geeks", "cat", "cut"};
    // int n = sizeof(keys)/sizeof(keys[0]);
    
    // insert words in trie ds
    /**/
    // for (int i = 0; i < n; i++) 
    //     insert(root, keys[i]);  

    // insert string in trie
    insert(root, "cricket");
    insert(root, "boll");
    insert(root, "geek");
    insert(root, "geeks");
    insert(root, "cat");
    insert(root, "cut");

    // search string in tris
    cout<<search(root, "boll")<<endl;
    cout<<search(root, "cat")<<endl;
    cout<<search(root, "gee")<<endl;

    // delete a string from trie
    cout<<"befor delete word cricket present? "<<search(root, "cricket")<<endl;
    deleteKey(root, "cricket", 0);
    cout<<"After deletion word cricket present? "<<search(root, "cricket")<<endl;
    
    
    return 0;
} 