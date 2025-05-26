/*
Date: 26/08/2022

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // method 2: Much more efficient
    int solve2(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> leftspan(n, -1); // default vale as before first index (-1)
        vector<int> rightspan(n, n); // default vale as after last index (size of arrar)
        // create a stack
        stack<int> st;
        
        // calculate left Span for each height
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                rightspan[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        
        // clear the stack
        while(!st.empty()) st.pop();
        // calculate rightSpan for each height
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                leftspan[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        
        // now calulate maximum rectange area in array
        int maxres=0;
        for(int i=0; i<n; i++)
        {
            maxres = max(heights[i] * (rightspan[i]-leftspan[i]-1), maxres);
        }
        return maxres;
    }
    
    
    
    
    
    
    
    
    
    
    // Method 1:
    int solve1(vector<int>& heights)
    {
        int n = heights.size();
        // Your code here
        int  leftSmaller[n];
        int  rightSmaller[n];
        stack<int> st; // strore index of building
        // calculate left smaller for each tower
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) leftSmaller[i] = 0;
            else leftSmaller[i] = st.top() +1;
            st.push(i);
        }
        // clear the stack
        while(!st.empty()) st.pop();
        // calculate right smaller for each tower
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) rightSmaller[i] = n-1;
            else rightSmaller[i] = st.top()-1;
            st.push(i);
            
        }
        // now calculate area for each tower and take maximum of them
        int maxA=0;
        for(int i=0; i<n; i++)
        {
            maxA = max(maxA, heights[i]*(rightSmaller[i] - leftSmaller[i] + 1));
        }
        return maxA;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        // Method 2
        return solve2(heights);
        
        // Method 1
        // return solve1(heights);
        
    }
};


int main(){
    vector<int> heights;
    // Input: heights = [2,1,5,6,2,3]
    // Output: 10
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);

    Solution ob;
    cout<<ob.largestRectangleArea(heights)<<endl;
    return 0;
}