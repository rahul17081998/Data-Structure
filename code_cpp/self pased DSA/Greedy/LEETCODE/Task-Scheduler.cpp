/*Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // create a map to store the frequency of each task character
        unordered_map<char, int> mp;
        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        } 

        // create a priority queue to store the frequency of each task in decreasing order
        priority_queue<int> pq;
        for(auto it: mp){
            pq.push(it.second);
        }
        int ans=0;
        while(!pq.empty()){
            // find the size of the priority queue
            int size = pq.size();
            // create a temporary vector to store the frequency of each task that is being processed in the current cycle
            vector<int> temp;
            // pick up the 'n+1' most frequent tasks from the priority queue and decrease their frequency by one
            for(int i=0; i<min(n+1, size); i++){
                int p = pq.top();
                pq.pop();
                p=p-1;
                if(p>0)
                    temp.push_back(p);
            }
            // push back the tasks with a frequency greater than zero to the priority queue
            for(int p:temp){
                pq.push(p);
            }
            // if the priority queue is not empty(to avoid the last cycle cooldown preiod) 
            // and its size is less than 'n+1', that means we requres some cooldown preird time calculate the number of idle cycles required to meet the cooldown period and add it to the 'ans' variable
            if(!pq.empty() && size<n+1){
                ans += n+1-size;
            }
        }
        // return the sum of 'ans' and the size of the input 'tasks' array, which gives the total number of cycles required to complete all the tasks with the cooldown period
        return ans+ tasks.size();
    }
};
