#include<iostream>
using namespace std;

int count1=0;
void Toh(int n, char A,char B, char C)
{
    if(n == 1)
    {
        cout<<"move 1 from "<<A<<" to "<<C<<endl;
        count1++;
        return;
    }

    Toh(n-1, A, C, B);
    cout<<"move "<<n<<" from "<<A<<" to "<<C<<endl;
    count1++;
    Toh(n-1, B, A, C);
}

int main(){
    int x=3;
    // int count
    Toh(x, 'A', 'B', 'C');
    cout<<count1<<endl;
    return 0;
}