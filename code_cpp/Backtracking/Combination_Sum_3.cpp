class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int> comb, int target, vector<int> &curr, int &sum, int index, int k)
    {
        if(sum > target || curr.size() > k)
            return;
        if(sum==target && curr.size()==k)
        {
            result.push_back(curr);
            return;
        }
        
        for(int i=index; i<comb.size(); i++)
        {
            if(i!=index && comb[i]==comb[i-1])
                continue;
            sum += comb[i];
            curr.push_back(comb[i]);
            solve(comb, target, curr, sum, i+1, k);
            sum -= comb[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        // making a combination array from 1...9
        vector<int> comb;
        for(int i=0; i<9; i++)
        {
            comb.push_back(i+1);
        }
        
        
        vector<int> curr;
        int sum=0;
        
        solve(comb, n, curr, sum, 0, k);
        return result;
    }
};
