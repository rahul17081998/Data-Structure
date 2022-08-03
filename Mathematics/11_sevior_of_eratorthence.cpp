#include<iostream>
using namespace std;

int sieve(int n){
    if (n>=2)
    {
        cout<<2<<" ";
    }
    if (n>=3)
    {
        cout<<3<<" ";
    }
    
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if(i%j != 0)
            {
                
              continue;
                // break;
            }
            cout<<i<<" ";
            break;
        }
        
    }
}

int main(){
    sieve(50);
    return 0;
}