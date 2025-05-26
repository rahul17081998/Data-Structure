#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> st; 
    st.insert(10);
    st.insert(5);
    st.insert(20);
    st.insert(7);
    st.clear();
    for(int x:st)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    
    // greater function reverse the set order
    // duplicates are ignored by set
    // set<int,greater<int> > s;
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(34);
    s.insert(24);
    s.insert(7);
    s.insert(50);
    // s.insert(10);   //Duplicate
    // s.insert(5);    //Duplicate
    

    // upper_bound:
    // element 8 is not present then it will return just above the element
    auto it1=s.lower_bound(7); 
    if(it1!=s.end())
        cout<<(*it1)<<endl;
    else
        cout<<"\nGiven element is greater than highest element in set\n";
    // lower_bound
    auto it2=s.upper_bound(7); 
    if(it1!=s.end())
        cout<<(*it2)<<endl;
    else
        cout<<"\nGiven element is greater than highest element in set\n";
    
    auto itrr=s.find(7);    // if an element is present itr pointing that else itr pointing end of array
    s.erase(itrr,s.end());  
    //
    if(itrr==s.end())
        cout<<"\nNot found\n";
    else 
        cout<<"\nFound\n";

    for(auto it=s.begin(); it!=s.end(); it++)
    {
        cout<<(*it)<<" ";
    }

    //
    if(s.count(20)) // if an element is present return 1 else 0
    {
        cout<<"found\n";
    }
    else
    {
        cout<<"Not found\n";
    }
    s.erase(5); // rease value
    
    // iter iterator in c++ stl
    cout<<endl;
    // reverse iterator in c++ stl    o/p: 5 10 20
    // for(auto it=s.rbegin(); it!=s.rend();it++)
    // {
    //     cout<<(*it)<<" ";   
    // }
    return 0;
}