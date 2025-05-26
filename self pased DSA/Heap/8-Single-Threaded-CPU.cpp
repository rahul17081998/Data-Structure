class Solution {
public:
   /*
   VVI
   Problem link: https://leetcode.com/problems/single-threaded-cpu/description/

   Approach:
    --> Indexing all the tasks so they dont loose their identity while calculating the answer.

    --> Sort the tasks.

    --> Keep pushing tasks into queue while the enqueueing time of next task is lower than the current time.

    --> If queue is empty and still the outer loop is running...then this means we still have tasks and also the queue is empty ---> CPU is idle from 't'(current time) to tasks[i][0](next enqueueing time).

    --> If queue is not empty and also the next enqueueing time is greater than curr time!! that means we do the task having shortest burst time untill our current time is equal of greater than the enqueueing time of next task.

    --> While poping from queue, keep pushing every index in answer vector.

    */
   
   
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        // indexing all the tasks so that they don't loss their identity
        for(int i=0; i<n; i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end()); // sort the task on the basis of enqueueTime
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min heap
        vector<int> ans;
        
        long long t = tasks[0][0]; // current time
        int i=0;

        while(!pq.empty() || i<n){
            // keep pushing tasks into queue while the enqueueing time of 
            // next task is lower than the current time!!
            while(i<n && t>= tasks[i][0]){ 
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            // if queue is empty and still the outer loop is running...then this means we still
            // have tasks and also the queue is empty ---> CPU is idle from 't'(current time) t0
            //  tasks[i][0](next enqueueing time)!!
            if(pq.empty()) 
                t = tasks[i][0];
            else{//queue is not empty and also the next enqueueing time is greater than curr
            // time!! that means we do the task having shortest burst time untill our current
            // time is equal of greater than the enqueueing time of next task
            
                pair<int,int> p = pq.top();
                pq.pop();
                ans.push_back(p.second);
                t =t + p.first;
            }
        }
        return ans;
    }
};