
class Solution {
    vector<int> par;
    vector<int> rank;
    
    // initialize the parent array and rank array
    void initialize(int &size)
    {
        par.resize(size+1); // define size of parent array
        rank.resize(size+1); // define size of rank array
        for(int i=0; i<size; i++)
        {
            par[i]=i;
            rank[i]=0;
        }
    }
    // find parent of x using rank by union and path compression
    int find(int x)
    {
        if(par[x]==x)
            return x;
        else{
            // recursively find parent of x
            par[x] = find(par[x]);
            return par[x];
        }
    }
    
    // union of two element
    void unions(int x, int y)
    {
        int x_rep=find(x);
        int y_rep=find(y);
        if(x_rep==y_rep)
            return;
        
        // check renk
        if(rank[x_rep]<rank[y_rep]) 
            par[x_rep]=y_rep;
        
        else if(rank[x_rep]>rank[y_rep]) 
            par[y_rep]=x_rep;
        
        else{ // both have equal rank
            par[x_rep]=y_rep;
            rank[y_rep]++;
        }
    }
public:
    int largestComponentSize(vector<int>& nums) {
        // initialize(nums);
        
        
         // find maximum element
        int size = *max_element(nums.begin(), nums.end());
        initialize(size);
        
        for(auto &val : nums)
        {
            for(int k=2;k<=sqrt(val);k++)
            {
                if(val%k == 0)
                {
                    unions(val,k);
                    unions(val,val/k);
                }
            }
        }
        
        unordered_map<int,int> mp;
        for(auto &val: nums)
        {
            mp[find(val)]++;
        }
        
        int len=0;
        for(auto &[key, val]: mp)
        {
            if(val > len)
                len=val;
        }
        return len;
    }
};


