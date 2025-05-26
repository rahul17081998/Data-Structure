#include<bits/stdc++.h>
using namespace std;
void binaryNum(int N)
{
    int bit[32];
    int count=0;
    while (N>0)
    {
        bit[count]=N%2;
        N=N/2;
        count++;
    }
    // print binary
    for (int i = count-1; i >=0; i--)
    {
        cout<<bit[i]<<" ";
    }
    // complement binary
    cout<<"\ncomplement\n";
    for (int i = 0; i < count; i++)
    {
        if(bit[i]==1)
            bit[i]=0;
        else
            bit[i]=1;
    }
    // print complemented binary
    for (int i = count-1; i >=0; i--)
    {
        cout<<bit[i]<<" ";
    }
    // binary(complemented) to decimal
    int sum=0;
    for (int i=0; i<count; i++)
    {
        sum=sum+pow(2,i)*bit[i];
    }
    cout<<"\ncomplement in decimal: "<<sum;
    
}
int main(){
    int num=5;
    binaryNum(num);
    cout<<endl<<pow(2,1);
    return 0;
}