/*
VVI

A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship 
with packages on the conveyor belt (in the order given by weights). We may not load more weight 
than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor 
belt being shipped within days days.
*/

class Solution {

private:
    bool isSuccessFull(int mid, vector<int> &weights, int givenDays){
        int d=1;// atleast one day requires
        int sum=0;
        
        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
            if(sum > mid){
                d++; // we need to take one more days
                sum = weights[i];
            }
        }

        // if with given mid value, we requires less than or equal to the given days then this is a successful distribution
        return d<=givenDays; 
    }


public:
    // TC = O(NlogN), SC = O(1)
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=0;
        int sum=0;

        for(int val: weights){
            sum += val;
            maxi = max(maxi, val);
        }

        // if size of weight array is same as days then we have to put atleast one item on conveyor belt so maximum capicity = mamimum weight of item
        if(weights.size()==days) return maxi;

        int lo=maxi, hi=sum;
        int ans=0;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(isSuccessFull(mid, weights, days)){
                ans = mid;
                hi=mid-1; // decrese the days now
            }
            else{
                // increse the days so that mid will increase
                lo = mid+1;
            }
        }
        return ans;
    }
};
