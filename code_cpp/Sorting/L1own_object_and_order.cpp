#include<iostream>
#include<algorithm>
using namespace std;
struct point
{
    int x,y;
};

bool myCmp(point p1, point p2)
{
    return (p1.x < p2.x);  // sorting Lower x value first
    // return (p1.y < p2.y);  // sorting Lower y value first
}
int main(){
    point arr[] = {{3,10}, {2,8}, {5,4}};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,myCmp);
    for(auto i : arr)
    {
        cout<<i.x<<" "<<i.y<<endl;
    }
    return 0;
}