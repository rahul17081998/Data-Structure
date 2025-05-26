#include<bits/stdc++.h>
using namespace std;

/*
Theory of left and right shift
Link: https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/

Left Shift :
Denoted as : << 
Eg: N<<i (N: first operand, i: second operand)

Takes two numbers, left shifts the bits of the first operand, the second operand decides 
the number of places to shift. Or in other words left shifting an integer “x” with an 
integer “y” denoted as ‘(x<<y)’ is equivalent to multiplying x with 2^y (2 raised to power y). 
x = x*(x^y)

eg: lets take N=22; which is 00010110 in Binary Form.

      Now, if “N is left-shifted by 2” i.e N=N<<2 then N will become N=N*(2^2). 
      Thus, N=22*(2^2)=88 which can be written as 01011000.


Right Shift :
Denoted as : >>
Eg: N>>i (N: first operand, i: second operand)

Takes two numbers, right shifts the bits of the first operand, the second operand decides 
the number of places to shift. In other words right shifting an integer “x” with an 
integer “y” denoted as ‘(x>>y)‘ is equivalent to dividing x with 2^y. 
x = x/(2^y)
eg: lets take N=32; which is 100000 in Binary Form.

     Now, if “N is right-shifted by 2” i.e N=N>>2 then N will become N=N/(2^2). 
     Thus, N=32/(2^2)=8 which can be written as 1000.


*/






//write your function here
// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
// TC = O(1)
// SC = O(1)
int rangeBitwiseAnd(int left, int right) 
{
    int count=0; // keep count of right shift
    while(left!=right)
    {
        left >>=1; // right shift[removing from lsb]
        right>>=1; // right shift
        cout<<"Left = "<<left <<"  right"<<right<<endl;
        count++;
    }
    cout<<"count "<<count<<endl;
    return left<<count; // left shift -->adding zeros
}

// revision
int solve(int left, int right){
    int count=0;
    while(left !=right){
        // do left shift
        left>>1; // divideing the number with 2^1
        right>>1;
        // keep counting how many left shift you have did
        count++;
    }
    return left<<count; // adding 'count' zeros left size --> multipling the number with 2^count 
}

int main(){
  
    cout<<rangeBitwiseAnd(5, 7)<<endl;
    return 0;
}