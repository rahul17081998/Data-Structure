
#include <bits/stdc++.h>
using namespace std;

// Structure of a Node
struct Node
{
	int data;
	Node* left, *right;

	// Constructor of the class
	Node(int item)
	{
		data = item;
		left = right = NULL;
	}
};

// Stores the count of required pairs
int result = 0;

// Function to perform dfs to find pair of
// leaf nodes at most K distance apart
vector<int> dfs(Node* root, int distance)
{
	
	// Return empty array if node is NULL
	if (root == NULL)
	{
		vector<int> res(distance + 1, 0);
		return res;
	}

	// If node is a leaf node and return res
	if (root->left == NULL &&
	root->right == NULL)
	{
		vector<int> res(distance + 1, 0);
		res[1]++;
		return res;
	}

	// Traverse to the left
	vector<int> left = dfs(root->left,
						distance);

	// Traverse to the right
	vector<int> right = dfs(root->right,
							distance);

	vector<int> res(distance + 1, 0);

	// Update the distance between left
	// and right leaf node
	for(int i = res.size() - 2;
			i >= 1; i--)
		res[i + 1] = left[i]+ right[i];

	// Count all pair of leaf nodes
	// which are at most K distance apart
	for(int l = 1;l < left.size(); l++)
	{
		for(int r = 0;r < right.size(); r++)
		{
			if (l + r <= distance)
			{
				result += left[l] * right[r];
			}
		}
	}

	// Return res to parent node
	return res;
}

// Driver Code
int main()
{
	
	/*
		1
		/ \
	  2     3
	/  \
	4   14
	*/

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(14);
	// root->right->left = new Node(9);

	// Given distance K
	int K = 3;

	// Function call
	dfs(root, K);

	cout << result;
}

// This code is contributed by mohit kumar 29
