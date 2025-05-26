/*
You are given an integer n indicating there are n specialty retail stores. 
There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, 
where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). 
Let x represent the maximum number of products given to any store. You want x to be as 
small as possible, i.e., you want to minimize the maximum number of products that are given 
to any store.
Return the minimum possible x.
*/


class Solution {
private:
    bool isSuccessful(int mid, vector<int> &quantities, int n){
        
        int countShopRequires=0;
        for(int i=0; i<quantities.size(); i++){
            int val = quantities[i];
            // split this values into stores
            if(val%mid!=0) countShopRequires++;
            countShopRequires += val/mid;
            // check if we requires more shopes then given to distribute the products thn this is not the a successful way to distribute
            if(countShopRequires>n) return false;
        }
        return true;
    }

public:
    // Capacity To Ship Packages Within D Days(same question)
    // minimum book allocation(same question)
    // TC = O(NlogN), SC = O(1)
    int minimizedMaximum(int n, vector<int>& quantities){
        int maxi=0;
        for(int val: quantities){
            maxi = max(maxi, val);
        }         

        if(quantities.size()==n) return maxi;

        int lo=1, hi=maxi;
        int ans = 0;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(isSuccessful(mid, quantities, n)){
                ans = mid; // a possible product distribution size
                hi = mid-1; // to reduce the product distribution
            }
            else{ // we requires more bigger size to distribute all product amond n stores, we are left with the some product if we use mid size
                lo=mid+1;
            }
        }
        return ans;
    }
};

