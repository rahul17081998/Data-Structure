/*
Union by rank operations
TC=(logN) --> For both find(x) and union(x,y) operation
*/



#include<iostream>
using namespace std;
#define n 5

// create a parent and rank array
int parent[n];
int Rank[n];

void initialize()
{   
    // initialize parent array such that parent of i is itself 'i'
    // initialize rank of each node is 0
    for(int i=0; i<n; i++){
        parent[i]=i;
        Rank[i]=0;
    }
}
// find parent of a node
int find(int x)
{
    if(parent[x]==x)
        return x;
    else 
        return find(parent[x]); // recursively find parent
}

// union two node x and y
void unions(int x, int y)
{
    int x_rep=find(x);
    int y_rep=find(y);
    // same as simple union implementation
    if(x_rep==y_rep) return;
   
    // now rank comes into picture
    // compare rank of x_rep and rank of y_rep 
    // whoever is smaller rank make tham child of higher rank representative

    // check if x_rep rank is smaller than y_rep rank then make y_rep as parent of x_rep
    if(Rank[x_rep]<Rank[y_rep])
        parent[x_rep]=y_rep;

    // check if y_rep rank is smaller than x_rep rank then make x_rep as parent of y_rep
    else if(Rank[y_rep]<Rank[x_rep])
        parent[y_rep]=x_rep;

    // if both have same rank
    // in this case you can make anyone as parent of any body and increase the rank of parent
    else
    { 
        parent[y_rep] = x_rep;
        Rank[x_rep]++;
    }
}

// main function
int main(){
    
    initialize();   // {0 ,1, 2, 3, 4}
    unions(0,2);    // {{0, 2}, 1, 3, 4}
    unions(0,4);    // {{0, 2, 4}, 1, 3}

    cout<<find(4)<<endl;
    cout<<find(3)<<endl;
    return 0;
}