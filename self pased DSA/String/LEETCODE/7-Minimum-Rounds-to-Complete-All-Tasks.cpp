class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // Create an unordered_map to store the frequency of each task
        unordered_map<int,int> taskFrequency;
        
        // Iterate through the tasks vector, counting the frequency of each task
        for(int i=0; i<tasks.size(); i++){
            taskFrequency[tasks[i]]++;
        }

        // Initialize variable to store the total number of rounds required
        int totalRound=0;
        
        // Iterate through the taskFrequency map
        for(auto it: taskFrequency){
            int taskCount = it.second;
            // If a task only appears once, it cannot be completed in multiple rounds
            if(taskCount==1) return -1;
            // If the taskCount is divisible by 3, increment totalRound by taskCount/3
            if(taskCount%3==0)
                totalRound += taskCount/3;
            // If the taskCount is not divisible by 3, increment totalRound by (taskCount/3 +1)
            else 
                totalRound += taskCount/3 +1;
        }
        // Return the total number of rounds required
        return totalRound;
    }
};
