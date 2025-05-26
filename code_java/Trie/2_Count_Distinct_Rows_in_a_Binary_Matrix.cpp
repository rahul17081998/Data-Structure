#include<bits/stdc++.h>
using namespace std;
#define M 4
#define N 3
// Effective approch
static int mat[M][N]= { {1, 0, 0},
                        {1, 1, 1},
                        {1, 0, 0},
                        {0, 1, 0} };


struct TrieNode{
    TrieNode *child[2];
    TrieNode()
    {
        child[0] = NULL;
        child[0] = NULL;
    }
};

bool insert(TrieNode *root, int row)
{
    TrieNode *curr = root;
    bool flag=false;
    for(int i=0; i<N; i++)
    {
        int index = mat[row][i];
        if(curr->child[index]==NULL)
        {
            curr->child[index] = new TrieNode();
            flag = true;
        }
        curr = curr->child[index];
    }
    return flag;
}

int countDistinct()
{
    TrieNode *root = new TrieNode();
    int res = 0;
    for(int row=0; row<M; row++)
    {
        if(insert(root, row)==true)
            res++;
    }
    return res;
}

int main(){

    cout<<"No of distinct rows are: "<<countDistinct()<<endl;
    return 0;
} 