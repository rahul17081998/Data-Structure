#include<iostream>
using namespace std;

int squareroot(int x)
{
    int count = 1;
    for (int i = 0; i <=
     x/2; i++)
    {
        if((count*count)<=x and (count+1)*(count+1)>x)
        {
            return count;
        }
        else
            count++;
    }
    return 0;
}
int main(){
    int x = 5;
    cout<<squareroot(x)<<endl;
    return 0;
}