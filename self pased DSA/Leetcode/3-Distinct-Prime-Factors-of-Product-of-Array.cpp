class Solution {
public:

    unordered_map<int,int> mp;
    void primeFactor(int n){

        int c = 2;
        while(n>1){
            if(n%c==0){
                mp[c]++;
                n = n/c;
            }
            else c++;
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++){
            primeFactor(nums[i]);
        }

        return mp.size();
    }
};