// sequence.
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

#include<iostream>
using namespace std;

int fab(int n)
{   /*          // base case
    if(n==0){
        return 0;
    }
    
    if(n==1){
        return 1;
    }*/

    if (n<=1)
    {
        return n;
    }
    
    
    return fab(n-1)+fab(n-2);
}


int main(){
    int a = 5;
    cout<<fab(a);
    return 0;
}


