/*
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray 
of nums with a sum of at least k. If there is no such subarray, return -1.
A subarray is a contiguous part of an array.
*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // we will use dequeue
        // how dequq work?
        // front --> * * * * * <-- back
        // we can pop and push from both side

        deque<pair<long long,long long>> dq; // index,sum
        long long sum = 0;
        long long shortest = INT_MAX;

        for(long long int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum >= k){ // if sum is greater then target
                shortest = min(shortest, i+1);
            }
            // reduce the window size to find minimum window with sum >= target(k)
            pair<int,int> curr = {INT_MIN,INT_MIN};
            while(!dq.empty() && (sum - dq.front().second >= k)){
                curr = dq.front();
                dq.pop_front();
            }
            
            if(curr.second!=INT_MIN)
                shortest = min(shortest, (i-curr.first));

            // maintain monotonic, non-decreasing  order of deque
            while(!dq.empty() && sum<dq.back().second){
                dq.pop_back();
            }
            dq.push_back({i, sum}); // push the current index and sum
        }
       return shortest==INT_MAX?-1:shortest;
    }
};
