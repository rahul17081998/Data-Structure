class Solution {
public:
    int result; // variable to store the longest path

    int dfs(vector<vector<int>> &adj, int curr, int parent, string &s){
        int longest=0; // variable to store the longest path in the subtree of the current node
        int secLongest=0; // variable to store the second longest path in the subtree of the current node

        for(int &child: adj[curr]){ // iterate through the children of the current node
            if(child==parent) continue; // skip the parent node
            int child_longest_length= dfs(adj, child, curr, s); // recursively call dfs on the child node

            if(s[child]==s[curr]) continue; // if the characters at the child and current node are the same, skip

            if(child_longest_length > secLongest) // update second longest path if necessary
                secLongest = child_longest_length;
            if(secLongest > longest) // swap longest and second longest if necessary
                swap(longest, secLongest);
        }

        int koi_ek_accha = max(secLongest, longest)+1; // case where only one branch is selected from the current node
        int only_root_accha = 1; // case where only the current node is selected
        int neeche_hi_mil_gye_answer = 1+secLongest+longest; // case where both branches are selected from the current node

        result = max({result, koi_ek_accha, only_root_accha, neeche_hi_mil_gye_answer}); // update the result if necessary
        return max(koi_ek_accha, only_root_accha); // return the maximum of the two cases
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        // make adjacent graph
        for(int i=1; i<n; i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }


        result=0;
        dfs(adj, 0, -1, s); // call dfs on the root node with -1 as the parent
       
        return result;
    }
}; 
