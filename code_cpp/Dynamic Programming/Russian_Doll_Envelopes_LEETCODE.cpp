class Solution {
public:
    // comparision function to sort the 2D array
    static bool comp(vector<int> &a, vector<int> &b)
    {
        // check if width is smaller----> means we need to sort the array on the basis of increasing width
        if(a[0] < b[0])
            return true;
        // check if width is same
        else if(a[0]==b[0]){
            // higher height will come first--> means sort on decresing height
            if(a[1]>b[1])
                return true;
            else return false;
        }
        return false;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Tc=O(NlogN)
        // application of LIS
        // sort the envelopes array on the basis of increasing width,
        // (if width same then sort on the basis of decreasing height)
        sort(envelopes.begin(), envelopes.end(), comp);
        int n = envelopes.size();
        // vector<int> dp(n+1, INT_MAX); // this dp array will store the maximum height so far
        // dp[0]=0;
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        
        for(int i=1; i<n; i++)
        {
            // check if current height is greater than last height in temp array
            if(envelopes[i][1] > temp.back())
                temp.push_back(envelopes[i][1]);
            else{
                int index =lower_bound(temp.begin(), temp.end(), envelopes[i][1])-temp.begin(); 
                temp[index]=envelopes[i][1];
            }
        }
        return temp.size();
    }
};
