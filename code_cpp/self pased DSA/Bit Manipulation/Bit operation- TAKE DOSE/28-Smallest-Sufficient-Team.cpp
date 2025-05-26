/*
In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.
Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.
For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.

It is guaranteed an answer exists.

Example 1:

Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]
*/

class Solution {
public:
    // time complexity O(m*n^2)
    // space complexity O(n^2)
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> skillMap;

        // makkiping each skills with a unique set bit position
        for(int i=0; i<req_skills.size(); i++){
            skillMap[req_skills[i]]=i;
        }

        // for each person we are assigning all the skills in a signle integer(bit position)
        vector<int> peopleMask;
        for(int i=0; i<people.size(); i++){

            int tempMask=0;
            for(int j=0; j<people[i].size(); j++){
                int skillBit = skillMap[people[i][j]];
                tempMask = tempMask | (1<<skillBit);
            }
            peopleMask.push_back(tempMask);
        }
        
        int n = req_skills.size();
        int m = people.size();
        int target = (1<<n)-1; // all 1's

        vector<int> dp(1<<n, INT_MAX);
        vector<vector<int>> ans(1<<n, vector<int>());
        dp[0]=0;

        for(int mask=0; mask<(1<<n); mask++){
            if(dp[mask]==INT_MAX) continue; // this state can not be reached

            for(int j=0; j<m; j++){
                int nmask = mask | peopleMask[j];
                // check if new state can be reaced
                if(dp[nmask]>1+dp[mask]){
                    dp[nmask]=1+dp[mask];
                    ans[nmask]=ans[mask];   // then add all teams included in old state
                    ans[nmask].push_back(j);   // add new team also
                }
            }
        }
        return ans[target];
    }
};


// Method 1:  TLE Occurs
class Solution {
public:
    vector<int> sol;
    void solve(vector<int> peopleMask, int noSkiils, int cp, vector<int> &curr_sol, int sMask){
        // cp--> current perosn
        // if(curr_sol.size()>sol.size()) return;

        if(sMask==((1<<noSkiils)-1)){
                if(sol.size()==0 || curr_sol.size()<sol.size()){
                    sol = curr_sol;
                }
                return;
        }
        if(cp==peopleMask.size()) return;
            
        solve(peopleMask, noSkiils, cp+1, curr_sol, sMask); // current people not selecting
        curr_sol.push_back(cp);
        solve(peopleMask, noSkiils, cp+1, curr_sol, (sMask |peopleMask[cp])); // we are selecting current people
        curr_sol.pop_back();


    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> skillMap;

        // makkiping each skills with a unique set bit position
        for(int i=0; i<req_skills.size(); i++){
            skillMap[req_skills[i]]=i;
        }

        // for each person we are assigning all the skills in a signle integer(bit position)
        vector<int> peopleMask;
        for(int i=0; i<people.size(); i++){

            int tempMask=0;
            for(int j=0; j<people[i].size(); j++){
                int skillBit = skillMap[people[i][j]];
                tempMask = tempMask | (1<<skillBit);
            }
            peopleMask.push_back(tempMask);
        }
        vector<int> curr_sol;
        // cout<<people.size()<<" "<<peopleMask.size()<<endl;
        solve(peopleMask, req_skills.size(), 0, curr_sol, 0); // mask array, total_skill, current_person, curr_solution, skill_at_present
        return sol;
        
    }
};