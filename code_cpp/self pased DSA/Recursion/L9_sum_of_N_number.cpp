#include<iostream>
using namespace std;

int sumNo(int n)
{
    if(n==0){
        return 0;
    }
    return n+sumNo(n-1);
}


int main(){
    int a = 10;
    cout<<sumNo(a);
    return 0;
}