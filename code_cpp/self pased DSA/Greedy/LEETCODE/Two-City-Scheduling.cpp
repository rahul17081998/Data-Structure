/*A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], 
the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.*/

class Solution {
public:
    bool static cmp(vector<int> &a, vector<int> &b){
        if(a[0]-a[1] < b[0]-b[1]) return true;
        return false;
    }

    

    int twoCitySchedCost(vector<vector<int>>& costs){
        // sort the costs array besed on profit 
        sort(costs.begin(), costs.end(), cmp);
        int n = costs.size();

        int mincost=0;
        for(int i=0; i<n; i++){
            if(i<n/2){
                mincost += costs[i][0];
            }
            else{
                mincost += costs[i][1];
            }
        }
        return mincost;
    }
};