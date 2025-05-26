#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        for(int i=2; i<=n; i++){
            if(n%i==0) return i + minSteps(n/i);
        }
        return n;
    }
};

int main(){
    Solution ob;
    int n =40;
    // o/p: 11
    cout<<ob.minSteps(n)<<endl;
    return 0;
}