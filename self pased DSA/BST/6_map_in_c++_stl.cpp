/*  


compile:
    g++ -std=c++0x 6_map_in_c++_stl.cpp -o 6_map_in_c++_stl
run:
    ./6_map_in_c++_stl  

*/

#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int,int> m;
    m.insert({10,200});
    m[5]=100;
    m.insert({3,300});
    m.insert({6,600});
    m.insert({8,800});
    m.insert({7,700});
    m.insert({3,400});  // element inserted with duplicate value will completely ignored
    cout<<"Size: "<<m.size()<<endl;
    cout<<"If key is not present in map container: "<<m[20]<<endl;
    cout<<"Size: "<<m.size()<<endl;
    m[10]=500;  // square bracket can also used to update the value of a perticular key.
    m.at(6)=300;    // update value
    // cout<<"\nsearch an element not present: "<<m.at(9)<<endl;   //it throws out_of_range error,key not found
    cout<<"search an element if present return value: "<<m.at(7)<<endl;
    
    
    




    
    // begin(), end(),clear()
    cout<<"Print values using iterators\n";
    for(auto it=m.begin(); it!=m.end(); it++)
        cout<<(*it).first<<" : "<<(*it).second<<endl;
    // clear map
    m.clear();
    cout<<"Size after clear: "<<m.size()<<endl;











    // print
    /*
    cout<<"\nPrint all key value pair"<<endl;
    for(auto x:m)
        cout<<x.first<<" : "<<x.second<<endl;   */
    return 0;
}