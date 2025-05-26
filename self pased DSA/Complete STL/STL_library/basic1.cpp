#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>   // for accumulation operation
using namespace std;
int mul(int x,int y)
{
    return x*y;
}
void printarr(vector<int> vect)
{
    for(int i=0; i<vect.size(); i++)
        cout<<vect[i]<<" ";
}
int main()
{
    int arr[]={10,20,5,2,43,23,8,15,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr,arr+n);
    // count occurance of perticular number in vector array
    cout<<"\ncount occurance of 20 is: "<<count(vect.begin(),vect.end(),20);
    cout<<"\n Distance from first position i.e index of element: "<<distance(vect.begin(),max_element(vect.begin(), vect.end()))<<endl;
    cout<<"\nprint vector: ";
    for(int i=0; i<n; i++)
        cout<<vect[i]<<" ";
    // maximum element in a vector
    cout<<"\nmaximum element in a vector: "<<*max_element(vect.begin(),vect.end());
    cout<<"\nminimum element in a vector: "<<*min_element(vect.begin(),vect.end());
    cout<<"\nsum: "<<accumulate(vect.begin(),vect.end(),0);
    cout<<"\nusing predefined function: "<<accumulate(vect.begin(),vect.end(),1,mul);
    // sort the vector in ascending order
    sort(vect.begin(),vect.end());
    cout<<"\nAfter sorting: ";
    printarr(vect);
    // search element using binary search this will work only after sorting
    cout<<"\nBinary search: find element---> "<<binary_search(vect.begin(),vect.end(),15);
    // reverse a vector
    cout<<"\nfun o/p: ";
    printarr(vect);
    cout<<"\nAfter reversing the vector"; 
    reverse(vect.begin(),vect.end());
    printarr(vect);
    // check availablity of element --- a element is present or not in vector array
    find(vect.begin(),vect.end(),20)!=vect.end()?cout<<"\n Element present": cout<<"\n element not found";
    
    

    return 0;
}