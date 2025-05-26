#include<iostream>
#include<utility>
using namespace std;

int main(){
    pair<int, string> pair1(20,"Shivam Kumar");
    cout<<"content of pair1"<<endl;
    cout<<"Name: "<<pair1.second<<"\nAge: "<<pair1.first<<endl;
    
    
    pair<int , string> pair2 = make_pair(18, "Sonu Kumar");
    cout<<"\ncontent of pair1"<<endl;
    cout<<"Name: "<<pair2.second<<"\nAge: "<<pair2.first<<endl;
    
    
    
    return 0;
}