#include<iostream>
using namespace std;

int binary1(int n)
{
    while(n>0){

    if(n%2 != 0){
        cout<<1;
    }
    else{
    cout<<0;
    }
    n = n/2;
    }
}

int main(){
    cout<<binary1(15);
    return 0;
}