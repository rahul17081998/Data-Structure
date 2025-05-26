// 6-Activity-selection
// activity-selection-problem-grefaceedy-algo-1
class Solution
{
    public:
    
    static bool cmp(pair<int,int> a, pair<int,int> b)
    {
        return a.second < b.second;
    }
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> jobs;
        for(int i=0; i<n; i++){
            jobs.push_back({start[i], end[i]});
        }
        // sort the jobs array on the basis of end time 
        sort(jobs.begin(), jobs.end(), cmp);
        
        int ans=1;
        int prev=0;
        for(int curr=1; curr<jobs.size(); curr++)
        {
            if(jobs[curr].first > jobs[prev].second){
                ans++;
                prev = curr;
            }
        }
        return ans;
    }
};