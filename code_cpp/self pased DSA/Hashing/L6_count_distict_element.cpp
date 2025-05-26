#include<iostream>
#include<unordered_set>
using namespace std;
void DistintCount(int arr[], int n, unordered_set<int> &uns)
{
    for(int i=0; i<n; i++)
        uns.insert(arr[i]);
    cout<<"distinct element "<<uns.size()<<endl;
}
int main(){
    int arr[]={10,11,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    unordered_set<int> uns;
    DistintCount(arr,n,uns);
    return 0;
}