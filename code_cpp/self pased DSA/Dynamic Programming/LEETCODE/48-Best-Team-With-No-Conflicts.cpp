class Solution {
public:
    
    /*
    Approach;
    i have used LIC approach
    1. sort the scores value according to the edges
    now if scrore of a player(jth index) <= scores of a players(ith index)
    where [0=<j<i] then if(lisScore[j]+scores[i]>lisScore[i])
    then lisScore[i] = lisScore[j]+scores[i]
    */
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages){
        vector<pair<int,int>> players;
        int n = ages.size();
        for(int i=0; i<n; i++){
            players.push_back({ages[i], scores[i]});
        }
        
        sort(players.begin(), players.end());
        
        vector<int> lis(n);
        lis[0]=players[0].second;
        for(int i=1; i<n; i++){
            lis[i]=players[i].second;
            for(int j=0; j<i; j++)
            {
                if(players[i].second>=players[j].second){
                    lis[i]=max(lis[i], lis[j]+players[i].second);
                }
            }
        }
        
        int maxScore=lis[0];
        for(int i=0; i<n; i++){
            maxScore = max(maxScore, lis[i]);
        }
        return maxScore;
        
    }
};