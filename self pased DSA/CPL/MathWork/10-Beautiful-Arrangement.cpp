// link: https://leetcode.com/problems/beautiful-arrangement/

class Solution {
public:
    int countArrangement(int n) {
        vector<int> vs;
        for(int i=0; i<n; i++) vs.push_back(i+1);
        return count(n, vs);
    }
    
    int count(int n, vector<int> &vs){
        
        if(n<=0) return 1;
        
        int ans=0;
        for(int i=0; i<n; i++){
            if(vs[i]%n==0 || n%vs[i]==0){
                swap(vs[i], vs[n-1]);
                ans += count(n-1, vs);
                swap(vs[i], vs[n-1]);
            }
        }
        return ans;
    }
};