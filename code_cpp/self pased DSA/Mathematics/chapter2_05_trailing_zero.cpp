#include<iostream>
using namespace std;

int countzaro(int n){
    if (n<=1){
    return 1;
    }
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact = fact*i;
    }

    int zeros = 0;
    /******** This method overflow with higher value of n like n=20 *******/
    // while(fact%10 == 0){
    //     zeros++;
    //     fact = fact/10;
    // } 
    // return zeros;

    // Perfect method
    for(int i = 5; i <= n; i = i*5){
        zeros = zeros+n/i;
    }
    return zeros;
}

int main(){
    cout<<countzaro(100);
    return 0;
}