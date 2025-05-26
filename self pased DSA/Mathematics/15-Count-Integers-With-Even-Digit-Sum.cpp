#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // make a functinon to check wether thee sum of all digits of number is even or not 
     bool isDigitSum(int val)
    {
         int sum=0;
         while(val)
         {
             sum = sum + val%10;
             val = val/10;
         }
         return sum%2==0? true: false;
    }
    
    
    int countEven(int num) {
        
        int count = 0;
        for(int val=num; val>0; val--)
        {
            if(isDigitSum(val)) count++;
        }
        return count;
    }
};


int main(){
    int num=30;
    Solution ob;
    cout<<ob.countEven(num)<<endl;
    // o/p: 14
    return 0;
}