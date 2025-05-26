#include<iostream>
using namespace std;

int jos(int n, int k)
{
    if(n==1)
    {
        return 0;
    }
    return (jos(n-1, k)+k)%n;   // circle starts with 0
}

int myjos(int n, int k)
{
    return jos(n,k)+1;  // circle starts with 1
}

int main(){
    int n = 5, k = 2;
    cout<<myjos(n, k)<<endl;    // for int function to call use cout
                                // for void function to call not required cout just write function name 
    return 0;
}