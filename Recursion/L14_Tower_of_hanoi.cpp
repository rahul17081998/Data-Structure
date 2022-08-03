#include<iostream>
using namespace std;


void Toh(int n, char A,char B, char C)
{
    if(n == 1)
    {
        cout<<"move 1 from "<<A<<" to "<<C<<endl;
        return;
    }

    Toh(n-1, A, C, B);
    cout<<"move "<<n<<" from "<<A<<" to "<<C<<endl;
    Toh(n-1, B, A, C);
}

int main(){
    int x=3;
    Toh(x, 'A', 'B', 'C');
    return 0;
}