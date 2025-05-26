
class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>&comb, vector<int> &temp, int target, int &sum, int index)
    {
        // base case 
        if(sum==target){
            res.push_back(temp);
            return;
        }
        
        if(sum > target)
            return;
        
        for(int i=index; i<comb.size(); i++)
        {
            if(i!=index && comb[i]==comb[i-1])
                continue;
            sum += comb[i];
            temp.push_back(comb[i]);
            solve(comb, temp, target, sum, i+1);
            sum -= comb[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> temp;
        int sum=0;
        sort(candidates.begin(), candidates.end());
        solve(candidates, temp, target, sum, 0); // 0->index
        return res;
    }
};
