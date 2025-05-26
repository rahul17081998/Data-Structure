/*
Simple Union and Find operation
TC=(N) --> For both find(x) and union(x,y) operation
*/



#include<iostream>
using namespace std;
#define n 5

int parent[n];

// initialize parent array such that parent of i is itself 'i'
void initialize()
{
    for(int i=0; i<n; i++)
        parent[i]=i;
}

// find parent of a node
int find(int x)
{
    if(parent[x]==x)
        return x;
    else 
        return find(parent[x]); // recursively find parent
}

void unions(int x, int y)
{
    int x_rep=find(x);
    int y_rep=find(y);

    if(x_rep==y_rep)
        return;
    // else 
    parent[y_rep]=x_rep;
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