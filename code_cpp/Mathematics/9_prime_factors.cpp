#include<iostream>
#include<math.h>
using namespace std;

void primefact(int n)
{
    while(n%2==0)
    {
        cout<<"2\t";
        n = n/2;
    }

    for (int i = 3; i*i <= n; i = i+2)
    {
        while(n%i == 0)
        {
            cout<<i<<"\t";
            n = n/i;
        }
    }
    if (n>2)
    {
        cout<<n<<"\t";
    }
}

int main(){
    primefact(2632);
    
    return 0;
}