/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two 
endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/

class Solution {
public:
    // we are using here two pointer approach
    int maxArea(vector<int>& height) {
        int i=0; // left pointer
        int j = height.size()-1; // right pointer
        int area=0;

        while(i<j){
            int width = j-i; // width 
            int H = min(height[i], height[j]); // minimum height find
            area = max(area, width*H);
            // CHECK which side(left or right) has smaller side. if left side is smaller increase left printer or if right side is smaller compaire to left then decrease right pointer
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return area;
    }
};