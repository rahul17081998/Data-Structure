class Solution {
public:
    int unfairness = INT_MAX;
    
    void backTracking(vector<int>& cookies, int k, vector<int> &cookiesDistribution, int index)
    {
        // termineting condition
        if(index==cookies.size())
        {
            int maxi=0;
            // calculate maximum if cookidistribution sum
            for(auto cookie: cookiesDistribution) maxi = max(maxi, cookie);
            // update the unfairness if you got minimum
            unfairness = min(unfairness, maxi);
            return;
        }
        
        for(int i=0; i<k; i++)
        {
            cookiesDistribution[i] =  cookiesDistribution[i] + cookies[index];
            backTracking(cookies, k, cookiesDistribution, index+1);
            cookiesDistribution[i] =  cookiesDistribution[i] - cookies[index];
        }
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        // time = O(K^n)
        vector<int> cookiesDistribution(k, 0);
        backTracking(cookies, k, cookiesDistribution, 0); // 0-> starting index
        return unfairness;
    }
};
