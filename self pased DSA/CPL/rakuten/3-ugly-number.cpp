#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        
        int nextUglyNo=1;
        int i2=0,i3=0,i5=0;
        int nmo2 = 2; // next multiple of 2
        int nmo3 = 3; // next multiple of 3
        int nmo5 = 5; // next multiple of 5
        
        ugly[0]=1;
        
        for(int i=1; i<n; i++)
        {
            nextUglyNo = min(nmo2, min(nmo3, nmo5));
            ugly[i]=nextUglyNo;   
            
            if(nextUglyNo == nmo2)
            {
                i2 = i2+1;
                nmo2 = ugly[i2]*2;
            }
            if (nextUglyNo == nmo3)
            {
                i3 = i3+1;
                nmo3 = ugly[i3]*3;
            }
            if(nextUglyNo == nmo5)
            {
                i5 = i5+1;
                nmo5 = ugly[i5]*5;
            }
        }
        return nextUglyNo;
       
    }
};


int main(){
    Solution obj;
    int n=6;
    cout<<obj.nthUglyNumber(n)<<endl;
    return 0;
}