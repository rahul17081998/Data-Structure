/*
Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.

Return the root of the Quad-Tree representing the grid.

Notice that you can assign the value of a node to True or False when isLeaf is False, and both are accepted in the answer.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's.
isLeaf: True if the node is leaf node on the tree or False if the node has the four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.
*/

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* constructQuadTree(vector<vector<int>>& grid, int rowStart, int rowEnd, int colStart, int colEnd){
        if(rowStart>rowEnd || colStart>colEnd){
            return NULL;
        }

        bool isLeaf=true;
        int val = grid[rowStart][colStart];
        // check if all the values of grid are same or not
        for(int i=rowStart; i<=rowEnd; i++){
            for(int j=colStart; j<=colEnd; j++){
                if(grid[i][j]!=val){
                    isLeaf=false;
                    break;
                }
            }
            if(isLeaf==false) break;
        }
        // if all values are same then this a leaf node with value=val
        if(isLeaf==true){
            return new Node(val, true);
        }

        // all values are not same then split the grid into four parts
        int rowMid = (rowStart+rowEnd)/2;
        int colMid = (colStart+colEnd)/2;

        Node* topLeft = constructQuadTree(grid,rowStart ,rowMid, colStart, colMid);
        Node* topRight = constructQuadTree(grid,rowStart ,rowMid, colMid+1, colEnd);
        Node* bottomLeft = constructQuadTree(grid,rowMid+1 ,rowEnd, colStart, colMid);
        Node* bottomRight = constructQuadTree(grid,rowMid+1 ,rowEnd, colMid+1, colEnd);
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }


    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructQuadTree(grid, 0, n-1, 0, n-1);
    }
};