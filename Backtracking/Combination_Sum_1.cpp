class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int>& candidates, int target, int currSum, vector<int> &currCandidate, int index)
    {
        // base case 
        if(index>=candidates.size() || currSum>target)
            return;
        // check if current sum is equal to targetsum
        if(currSum==target){
            res.push_back(currCandidate);
            return;
        }
            
        
        for(int i=index; i<candidates.size(); i++)
        {
            if(i > index && candidates[i] == candidates[i-1]) continue;
            currCandidate.push_back(candidates[i]);
            solve(candidates, target, currSum+candidates[i], currCandidate, i);
            currCandidate.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()==0)
            return res;
        
        // sort the candidate array
        sort(candidates.begin(), candidates.end());
        vector<int> currCandidate;
        solve(candidates, target, 0, currCandidate, 0);
        return res;
    }
};
