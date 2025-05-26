#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> d;

    d.push_back(1);
    d.push_front(2);
    for(int i: d){
        cout<<i<<" "; 
    }
    cout<<endl; 
    //d.pop_front();
  
    cout<<endl;  
 
    cout<<"Print 1st index element-> "<<d.at(1)<<endl; 
    cout<<"front-> "<<d.front()<<endl;
    cout<<"back-> "<<d.back()<<endl;
    cout<<"Empty or Not-> "<<d.empty()<<endl;
    cout<<"Before Erase size-> "<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout<<"After Erase size -> "<<d.size()<<endl;
    for(int x:d){
        cout<<x<<" ";
    }cout<<endl;
    



    return 0;
}