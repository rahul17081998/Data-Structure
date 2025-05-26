#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l;
    list<int> n(5,100);
    cout<<"Print list n  element "<<endl; 
    for(int i:n){
        cout<<i<<" ";
    }cout<<endl;

    
    l.push_back(1);
    l.push_front(2);

    cout<<"Print list l element "<<endl; 
    for(int i:l){
        cout<<i<<" ";
    }cout<<endl;

    l.erase(l.begin());
    cout<<"after erase  "<<endl; 
    for(int i:l){
        cout<<i<<" ";
    }cout<<endl;
    cout<<"size-> "<<l.size()<<endl;





    return 0;
}