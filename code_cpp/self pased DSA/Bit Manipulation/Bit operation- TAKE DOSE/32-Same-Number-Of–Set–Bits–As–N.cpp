/*
GFG => Article link: https://www.geeksforgeeks.org/number-set-bits-n/
Given a positive integer N, find out how many positive integers strictly less than N have the same number of set bits as N.

Examples:  

Input : 8
Output :3
Explanation: Binary representation of
8 : 1000, so number of set bits in 8 is 1.
So the integers less than 8 with same number 
of set bits are : 4, 2, 1

Input :1
Output :0

Input :4
Output :2 
*/

// TC = O(NlogN)
// SC = O(1)
#include<bits/stdc++.h>
using namespace std;


int countSetBits(int num){
    int set=0;
    int mask=1;
    while(num){
        if(mask&num){
            set++;
        }
        num = num>>1; // right shift
    }
    return set;
}

int solve(int n){
    int ans = 0;
    int setn = countSetBits(n);
    for(int i=0; i<n; i++){
        int countset = countSetBits(i);
        if(countset==setn) ans++;
    }
    return ans;
}


int main(){
    int n=12;
    cout<<solve(n)<<endl;
    return 0;
}


// method2: use dp here
// find the just smaller number than n that has same number of set bits


#include<bits/stdc++.h>
using namespace std;

class Solve{

public:
    int solve(int n)
    

};


int main(){
    
    return 0;
}