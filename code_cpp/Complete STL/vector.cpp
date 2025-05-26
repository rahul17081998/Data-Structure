/*
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    vector<int> a(5,1); 
    vector<int> last(a);

    cout<<"print last "<<endl;
    for(int i:last){
        cout<<i<<" ";
    }cout<<endl;
    
    cout<<"Capacity-> "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    v.push_back(3);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    cout<<"Size-> "<<v.size()<<endl;  
    // Size -> How many elements are inside this vector
    // Capacity -> How many memory locations assigned
    cout<<"element at 2nd position-> "<<v.at(2)<<endl;
    
    cout<<"firts element-> "<<v.front()<<endl;
    cout<<"last element-> "<<v.back()<<endl;

    cout<<"Before pop"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    v.pop_back();

    cout<<"After pop"<<endl;
    for(int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"before clear "<<v.size()<<endl;  
    v.clear();
    cout<<"after clear "<<v.size() <<endl;

    return 0;
}
*/

// #include<iostream>
// using namespace std;

// int main(){
//     std::vector<std::int> vec1;
//     int element;
//     for(int i=0; i<4; i++)
//     {
//         cout<<"Enter an element to add to this vector";
//         cin>>element;
//         vec1.push_back(element);
//     }
//     return 0;
// }



#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    uint_least8_t i; // trying to be conscious of the size of the int
    vector<int> v;
    // for(i = 0; i < 5; ++i) 
    // {
    //     vect.push_back(i+2);
    // }
    v.push_back(3);
    v.push_back(31);
    v.push_back(13);
    v.push_back(21);
    v.push_back(23);
    v.push_back(13);
    v.push_back(63);
    v.push_back(30);
    for(int i : v) 
    {
        cout << i <<" ";
    }
    cout<<"print after sorting: ";
    reverse(v.begin()+1, v.begin()+4);
    for(int i : v) 
    {
        cout << i <<" ";
    }
    return 0;
}