#include<bits/stdc++.h>
using namespace std;

//write your function here

// TC = O(1)
// SC = O(1)
int rangeBitwiseAnd(int left, int right) 
{
    int count=0; // keep count of right shift
    while(left!=right)
    {
        left >>=1; // right shift[removing from lsb]
        right>>=1; // right shift
        count++;
    }
    return left<<=count; // left shift -->adding zeros
}


int main(){
  
    cout<<rangeBitwiseAnd(5, 7)<<endl;
    return 0;
}