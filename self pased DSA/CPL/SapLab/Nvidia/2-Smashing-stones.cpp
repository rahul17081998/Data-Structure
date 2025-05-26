class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        // store all the element into priority queue and each time take two stones 
        // which are at the top of pq and 
        // smash them,  left(not zero) will be push into priority queue
        
        priority_queue<int> pq;
        int n = stones.size();
        if(n ==1) return stones[0]; 
        // store all stones into pq
        for(int i=0; i<n; i++){
            pq.push(stones[i]);
        }
        
        while(pq.size()>1){
            // pick both top two element
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            if(s1!=s2){
                pq.push(s1-s2);
            }
        }
        // check at the last 
        if(pq.size()>0){
            return pq.top();
        }
        return 0;
        
    }
};