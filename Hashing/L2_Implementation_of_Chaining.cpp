#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct MyHash
{
    int BUCKET;
    list<int> *table;
    MyHash(int b)
    {
        BUCKET=b;
        table=new list<int> [b];
    }
    void insert(int key)
    {
        int i=key%BUCKET;
        table[i].push_back(key);
    }
    void remove(int key)
    {
        int i = key%BUCKET;
        table[i].remove(key);
    }
    bool search(int key)
    {
        int i = key%BUCKET;
        for(auto x:table[i])
        {
            if(x==key)
                return true;
        }
        return false;
    }
};
int main(){
    // struct MyHash mh(7);
    //     or   ---> Any of both can use
    // MyHash mh(7);
    MyHash mh(7);
    mh.insert(10);
    mh.insert(20);
    mh.insert(15);
    mh.insert(7);
    cout<<mh.search(10)<<endl;
    mh.remove(20);
    cout<<mh.search(20)<<endl;
    
    return 0;
}