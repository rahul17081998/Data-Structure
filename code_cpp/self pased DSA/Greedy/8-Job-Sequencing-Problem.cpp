/*
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.*/

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, cmp);
        vector<int> vis(n, 0);
        int maxprofit = 0;
        int countJob=0;
        for(int i=0; i<n; i++)
        {
            int dline = arr[i].dead;
               // Find a free slot for this job (Note that we start
                // from the last possible slot)
            for(int r=min(dline, n)-1; r>=0; r--){
                if(vis[r]==0)
                {
                    maxprofit += arr[i].profit;
                    vis[r]=1;
                    countJob++;
                    break;
                }
            }
            
        }
        
        vector<int> ans;
        ans.push_back(countJob);
        ans.push_back(maxprofit);
        return ans;
        
    } 
};