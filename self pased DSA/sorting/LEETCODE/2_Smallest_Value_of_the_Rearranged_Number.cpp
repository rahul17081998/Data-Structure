// Date: 25/08/2022
// Easy
// LeeCode

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long arrToNum(long long num, vector<int> &arr, int zero, bool flag)
    {
        long long newNum=0;
        // positive no
        if(flag)
        {
            sort(arr.rbegin(), arr.rend());
            // add smallest number which is greater then 0;
            while(arr.back()==0){
                arr.pop_back();
            }
            
            newNum=arr.back();
            arr.pop_back();
            
            for(int i=0; i<zero; i++){
                newNum = newNum*10;
            }
            sort(arr.begin(), arr.end());
            
            
            for (int i = 0; i < arr.size(); i++) 
            {
                int nu = arr[i];
                if (nu != 0) 
                {
                    while (nu > 0) 
                    {
                        newNum *= 10;
                        nu /= 10;
                    }
                    newNum += arr[i];
                } 
                else {
                    newNum *= 10;
                }
            }
        }
        // negative no
        else{
            sort(arr.rbegin(), arr.rend());

            for (int i = 0; i < arr.size(); i++) 
            {
                int nu = arr[i];
                if (nu != 0) {
                    while (nu > 0) {
                        newNum *= 10;
                        nu /= 10;
                    }
                    newNum += arr[i];
                } else {
                    newNum *= 10;
                }
            }
            
            newNum = -newNum;
        }
        
        return newNum;
    }
    
    
    // number to array conversion
    vector<int> numToArray(long long num)
    {
        vector<int> arr;
        while(num){
            arr.push_back(num%10);
            num = num/10;
        }
        
        return arr;
    }
    
    
    long long smallestNumber(long long num) {
        
        
        // num to array
        if(num==0)
            return num;
        bool flag=true;
        if(num < 0)
        {
            flag=false;
            num = -num;
        }
        vector<int> arr;
        arr = numToArray(num);
        // count zeros
        int zero=0;
        // return arr.size();
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]==0)
                zero++;
        }
        // return zero;
        // arr to number
        return arrToNum(num, arr, zero, flag);
        
        
    }
};

int main(){
    // input
    // num can be -ve or +ve
    long long num=342310042;

    Solution ob;
    cout<<ob.smallestNumber(num)<<endl;
    
    return 0;
}
/*
input:
3 5 2 9 1 8
output
1 9 2 8 3 5
*/