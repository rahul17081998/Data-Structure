class Solution {
public:
    int trap(vector<int>& height) {
        // calculate left max and right maxelement for each 
        // height
        int n=height.size();
        vector<int> lmax;
        vector<int> rmax;
        
        int leftmax=0, rightmax=0;
        
        // left max
        for(int i=0; i<n; i++)
        {
            leftmax = max(leftmax, height[i]);
            lmax.push_back(leftmax);
        }
        
        // right max
        for(int i=n-1; i>=0; i--)
        {
            rightmax = max(rightmax, height[i]);
            rmax.push_back(rightmax);
        }
        reverse(rmax.begin(), rmax.end());
        // calculate rain water
        int sum=0;
        for(int i=0; i<n; i++)
        {
            // int trapwater = min(lmax[i], rmax[i])-height[i];
            int trapwater = min(lmax[i], rmax[i])-height[i];
            if(trapwater<0)
                continue;
            
            sum += trapwater;
        }
        
        return sum;
    }
};
