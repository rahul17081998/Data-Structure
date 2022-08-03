#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(10);
    s.insert(51);
    s.insert(5);
    s.insert(20);
    s.insert(30);
    s.insert(24);
    // unoredered_set doesnot maintain order of element
    for(int x:s)
        cout<<x<<" ";
    // An other way to iterate
    cout<<"\nother way to iterate\n";
    for(auto it=s.begin(); it!=s.end(); it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;
    // find() function
    if(s.find(51)==s.end())
        cout<<"Not found"<<endl;
    else
        cout<<"found "<<*(s.find(51))<<endl;
    // count() function--> count function can be used of find function
    // Alternative of found function
    // count() function, when element present return 1 else 0 
    if(s.count(20))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
    // Erase function
    cout<<"Size before erase "<<s.size()<<endl;
    s.erase(5);
    cout<<"Size after erase "<<s.size()<<endl;
    // Erase using other way
    auto it=s.find(24);
    s.erase(it);
    cout<<"Size after again erase "<<s.size()<<endl;
    // we can also use erase function to erase set of element
    s.erase(s.begin(),s.end());
    cout<<"Size after fully erasing "<<s.size()<<endl;
    //clear the array
    s.clear();// erase everything
    cout<<"After clearing size "<<s.size()<<endl;
    
    return 0;
}