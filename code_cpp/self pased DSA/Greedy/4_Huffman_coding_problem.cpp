// C++ program for Huffman Coding with STL
#include<bits/stdc++.h>
using namespace std;
struct Node {

	// One of the input characters
	char data;
	// Frequency of the character
	unsigned freq;
	// Left and right child
	Node *left, *right;

	Node(char data, unsigned freq, Node* l = NULL, Node* r = NULL)
	{
		this->left = l;
		this->right = r;
		this->data = data;
		this->freq = freq;
	}
};
// compare  frequency-- lowest frequency first
// For comparison of
// two heap nodes (needed in min heap)
struct compare{
    bool operator()(Node *l, Node *r)
    {
        return (l->freq) > (r->freq);
    }
};
// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(Node *root, string str)
{
    if (!root)
		return;
    if(root->data!='$')
    {
        cout<<(root->data)<<" "<<str<<"\n";
        return;
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void printHCode(char arr[], int freq[], int n)
{
    // Create a min heap & inserts all characters of data[]
    priority_queue<Node*, vector<Node*>, compare> h;
    for(int i=0; i<n; i++){
        h.push(new Node(arr[i],freq[i]));
    }
    while(h.size()>1){      //// Iterate while size of heap doesn't become 1
    	// Extract the two minimum
		// freq items from min heap
        Node *l = h.top(); h.pop();
        Node *r = h.top(); h.pop();
        	// Create a new internal node with
		// frequency equal to the sum of the
		// two nodes frequencies. Make the
		// two extracted node as left and right children
		// of this new node. Add this node
		// to the min heap '$' is a special value
		// for internal nodes, not used
        Node *node = new Node('$',l->freq + r->freq, l, r);
        h.push(node);
    }
    // Print Huffman codes using
    printCodes(h.top(), "");
}
// Driver Code
int main(){
    
    char arr[] = {'a', 'd', 'e', 'f'};
    int freq[] = {30, 40, 80, 60};
    int n = sizeof(freq)/sizeof(freq[0]);
    printHCode(arr, freq, n);
    return 0;
}

/*
output: 
        e 0
        f 10
        a 110
        d 111
*/


