#include<iostream>
#include<utility>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
    pair<int,  char>pair1;  // define pair
    pair1.first=4;  // assign value
    pair1.second='d';   // assign value
    cout<<pair1.first<<", "<<pair1.second<<endl;
    
    pair<int, int>g1(4,2);
    cout<<g1.first<<", "<<g1.second<<endl;

    pair<int, string> g2;
    g2 = make_pair(3, "now");
    cout<<g2.first<<","<<g2.second<<endl;
    
    // mapping 
    unordered_map<string,int>map1;
    map1["one"] = 1;
    map1["two"] = 2;
    for(auto x:map1)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    if(map1.find("two")!=map1.end())
        cout<<"Found"<<endl;
    else
        cout<<"not found\n";

    return 0;
}