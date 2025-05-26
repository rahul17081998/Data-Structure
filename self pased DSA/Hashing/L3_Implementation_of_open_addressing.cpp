#include<bits/stdc++.h>
using namespace std;
struct MyHash
{
    int *arr;
    int cap,size;
    MyHash(int c)
    {
        cap=c;
        size=0;
        arr=new int[cap];
        // initially fill array with -1
        for(int i=0; i<cap; i++)
        {
            arr[i]=-1;
        }
    }
    // hash function
    int hash(int key)
    {
        return key%cap;
    }
    // search function
    bool search(int key)
    {
        int h=hash(key);
        int i=h;
        // condition: when array is not empty
        while(arr[i]!=-1)
        {
            if(arr[i]==key) // if key is found
                return true;
            i=(i+1)%cap;
            if(i==h)
            {
                return false;
            }
        }
        return false;
    }
    // insert key into array
    bool insert(int key)
    {
        if(size==cap)
        {
            return false;
        }
        int i=hash(key);
        // int i=h;
        // when at position of i
        // Not empty,Not deleted,and not same element present
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key)
        {
            i=(i+1)%cap;
        }
        if(arr[i]==key)
        {
            return false;
        }
        else
        {
            arr[i]=key;
            size++;
            return true;
        }
    }
    // delete the key
    bool erase(int key)
    {
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1)
        {
            if(arr[i]==key)
            {
                arr[i]=-2;
                return true;
            }
            i=(i+1)%cap;
            if(i==h)
            {
                return false;
            }
        }
        return false;
    }

};
int main(){
    struct MyHash mh(7);
    mh.insert(49);
    mh.insert(56);
    mh.insert(72);

    if(mh.search(49)==true)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    // cout<<mh.search(49);

    mh.erase(56);

    if(mh.search(56)==true)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    // cout<<mh.search(56);
    return 0;
}