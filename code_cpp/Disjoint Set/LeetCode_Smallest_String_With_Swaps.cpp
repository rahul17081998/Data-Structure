class Solution {
public:
    
    // union by rank
    vector<int> par;
    vector<int> rank;
    
    // initialize the parent array and rank array
    void initialize(int &size)
    {
        par.resize(size); // define size of parent array
        rank.resize(size);
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
        else
           return par[x] = find(par[x]);  
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
    
    // main
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n=s.length();
        initialize(n);

        // union and makes groups
        for(auto pair: pairs)
        {
            unions(pair[0], pair[1]);
        }
        
        // make groupings
        // 0<-[0,1,3], 2<-[2,4]   something like this
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++)
        {
            mp[find(i)].push_back(i);
        }
     
        for (auto &p : mp) {
           string temp = "";
            for (int i : p.second) 
                temp += s[i];
            
            sort(temp.begin(), temp.end());
            int k = 0;
            for (int i : p.second)
                s[i] = temp[k++];
        }
        return s;
        
    }
};









