/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.


*/


class Solution {
public:

    vector<vector<int>> ans;
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        // intervels are already sorted
        if(intervals.size()==0) return ans;

        vector<int> prevIntervel = intervals[0];

        for(auto currIntervel: intervals){
            if(currIntervel[0]<=prevIntervel[1]){ // merge intervel 
                prevIntervel[1] = max(prevIntervel[1], currIntervel[1]);
            }
            else{
                ans.push_back(prevIntervel);
                prevIntervel = currIntervel;
            }
        }

        ans.push_back(prevIntervel);
        return ans;
    }
    


    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // first of all we will introduce our newly intervel into already sorted intervel 
        // then we will merge them
        
        if(intervals.size()==0){// check if intervals is empty: corner case
            ans.push_back(newInterval);
            return ans;
        }
        // create a intervel vector
        vector<vector<int>> intervel1;
        bool flag= false;

        for(auto v: intervals){
            if(flag==false && v[0]<newInterval[0])
                intervel1.push_back(v);
            else{
                intervel1.push_back(newInterval);
                intervel1.push_back(v);
                flag = true;
            }
        }
        if(flag==false){ // check if newlyintervel is not included :corner case 
            intervel1.push_back(newInterval);
        }
        return merge(intervel1);
    }
};