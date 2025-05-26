#include<bits/stdc++.h>
using namespace std;
/*
--> multiset are sorted in assending order
-->time complexity

    insertion O(logN)
    searching O(logN)
    deletion O(logN)
these operation supported by multiset

Begin	Returns an iterator pointing to the first element in the multiset.
Cbegin	Returns a const iterator pointing to the first element in the multiset.
End	    Returns an iterator pointing to the past-end.
cend	Returns a constant iterator pointing to the past-end.
rbegin	Returns a reverse iterator pointing to the end.
rend	Returns a reverse iterator pointing to the beginning.
crbegin	Returns a constant reverse iterator pointing to the end.
crend	Returns a constant reverse iterator pointing to the beginning.
*/
int main(){
    multiset<int, greater<int> > ms;
    ms.insert(10);
    ms.insert(12);
    ms.insert(23);
    ms.insert(3);
    ms.insert(3);
    ms.insert(10);
    ms.insert(6);
    ms.insert(16);
    ms.insert(2);

    // output will be in sorted order
    cout<<"print element: ";
    for(auto it:ms){
        cout<<it<<" ";
    }
    cout<<endl;
    // erase an element
    
    // if 10 have multiple copy
    ms.erase(ms.find(10)); // this will delete only one copy of 10



    // here 3 has 2 time it will delete all copy 
    ms.erase(3); // this will delete all copy of 3

    
    cout<<"\nprint deleting 10: ";
    for(auto it:ms){
        cout<<it<<" ";
        // break;
    }
    cout<<endl;
    // int auto top = ms.begin();
    // cout<<top<<endl;
    return 0;
}