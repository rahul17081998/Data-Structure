/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

*/

class Solution {
public:
    // check if it's possible to eat all the piles of bananas in mid hours
    bool isPossibleEatAll(int mid, vector<int> &piles, int h){
        long long requiredHours=0;
        for(int val: piles){
            if(val%mid==0) // if bananas in a pile can be eaten in exactly mid hours
                requiredHours += val/mid;
            else // round up to the nearest integer
                requiredHours += val/mid+1;
        }
        if(requiredHours>h) return false; // if required hours are greater than given hours
        return true;
    }
    
    // find the minimum eating speed required to eat all the bananas in the given time
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=0; // maximum number of bananas in a pile
        int n = piles.size();
        for(auto val: piles){
            maxi = max(maxi, val);
        }

        if(n==h) return maxi; // if the number of piles is same as given hours

        int low = 1, high=maxi; // initialize the range of possible eating speeds
        while(low<=high){
            int mid = low + (high-low)/2; // calculate the mid point
            if(isPossibleEatAll(mid, piles, h)){ // if all piles can be eaten in mid hours
                high = mid-1; // continue search in the lower half of the range
            }
            else{
                low = mid+1; // continue search in the upper half of the range
            }
        }
        return low; // return the minimum eating speed
    }
    
};

