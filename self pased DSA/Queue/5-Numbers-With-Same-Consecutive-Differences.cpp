/*
Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.
Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.
You may return the answer in any order.
*/

#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        queue<int> q;
        for(int i=1; i<=9; i++)
        {
            q.push(i);
        }
        
        int level=1;
        while(!q.empty())
        {
            int size= q.size();
            while(size-->0)
            {
                int p = q.front();
                q.pop();
                int r = p%10; // last digit of p
                
                if(r+k <= 9) q.push(p*10 + r+k);
                if(k!=0)
                    if(r-k >= 0) q.push(p*10 + r-k);
            }
            level++;
            if(level==n) break;
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            ans.push_back(p);
        }
        return ans;
    }
};

int main(){
    Solution ob;
    vector<int> ans = ob.numsSameConsecDiff(3, 7);
    for(int x: ans) cout<<x<<" ";
    return 0;
}
/*
Example
Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.

*/