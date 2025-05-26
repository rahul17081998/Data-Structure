#include<iostream>
using namespace std;

int prime1(int n)
{
    if(n ==1 )
    {
        return false;
    }

    if(n == 2)
    {
        return true;
    }

    for (int i = 2; i < n; i++)
    {
        if (n%i == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
}

int main(){
    cout<<prime1(17);
    return 0;
}
