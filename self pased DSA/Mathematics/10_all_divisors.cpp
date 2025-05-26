#include<iostream>
using namespace std;

int divisors1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if(n%i == 0)
        {
            cout<<i<<"  ";
        }
    }
    
}

int main(){
    cout<<divisors1(100);
    return 0;
}