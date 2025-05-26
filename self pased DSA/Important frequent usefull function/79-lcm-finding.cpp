#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
    {
        if(b==0) return a;
        return gcd(b, a%b);
    }
    
    
int lcm(vector<int> nums)
{
    int n = nums.size();
    long long ans=nums[0];
    // Formula: LCM(a,b) = (a*b)/gcd(a,b)
    for(int i=1; i<n; i++)
    {
        ans = ((ans*(long long)nums[i]))/gcd(ans,(long long)nums[i]);
    }
    return (int)ans;
} 


int main(){
    
    return 0;
}