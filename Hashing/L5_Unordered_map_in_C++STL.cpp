#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> m;
    // insert elements in random order
    m["gfg"]=20;
    m["ide"]=30;
    m["course"]=12;
    m["geeks"]=35;
    // m.insert({"dsd",24});

    // Iterate method 1           
    for(auto x:m)
        cout<<x.first<<" "<<x.second<<endl;
    // iterate method 2
    cout<<"\nMethod 2: To iterate the loop\n";
    for(auto itr=m.begin(); itr!=m.end(); ++itr)
         cout<<itr->first<<" "<<itr->second<<endl;
    // search elerment using find() function
    if(m.find("ide")!=m.end())
        cout<<"Found\n";
    else
        cout<<"Not Found\n";
    // search elerment using count() function
    if(m.count("rfj")>0)
        cout<<"Found\n";
    else
        cout<<"Not Found\n";
    
    cout<<"size "<<m.size()<<endl;

    m.erase("ide");
    cout<<"size after erase "<<m.size()<<endl;

    m.erase(m.begin()); // erase first element
    cout<<"size after erase begining "<<m.size()<<endl;

    m.erase(m.begin(),m.end()); // erase everything from start to last( m.end()-1)
    cout<<"size after erase everything "<<m.size()<<endl;
    return 0;
}