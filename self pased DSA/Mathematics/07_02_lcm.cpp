#include<iostream>
using namespace std;

int Lcm2(int a, int b)
{
    int lcm = 1;
    while(lcm>0)
    {
        if(lcm%a == 0 and lcm%b == 0)
        {
            break;
        }
        lcm++;
    }
    return lcm;
}


int main(){
    cout<<Lcm2(7,6);
    return 0;
}