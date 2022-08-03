#include<bits/stdc++.h>
using namespace std;
int maxRectangleArea(int height[], int n)
{
    int max_area=0;
    stack<int> s;
    s.push(-1);
    for(int i=0; i<n; i++)
    {
        while(s.top()!=-1 && height[i] <= height[s.top()])
        {
            int curr_height = height[s.top()];
            s.pop();
            int curr_width = i - s.top() - 1;
            max_area = max(max_area, curr_height*curr_width);

        }
        s.push(i);
    }

    while(s.top()!=-1)
    {
        int curr_height = height[s.top()];
        s.pop();
        int curr_width = n - s.top() - 1;
        max_area = max(max_area, curr_height*curr_width);
    }
    return max_area;
}
/*

int largestRectangleArea(vector < int > & heights) {
  stack < int > stk;
  stk.push(-1);
  int max_area = 0;
  for (size_t i = 0; i < heights.size(); i++) {
    while (stk.top() != -1 and heights[stk.top()] >= heights[i]) {
      int current_height = heights[stk.top()];
      stk.pop();
      int current_width = i - stk.top() - 1;
      max_area = max(max_area, current_height * current_width);
    }
    stk.push(i);
  }
  while (stk.top() != -1) {
    int current_height = heights[stk.top()];
    stk.pop();
    int current_width = heights.size() - stk.top() - 1;
    max_area = max(max_area, current_height * current_width);
  }
  return max_area;
}
*/

int main(){
    int height[] = {6, 7, 5, 2, 4, 5, 9, 3};
    int n = sizeof(height)/sizeof(height[0]);
    cout<<"\nMaximum rectangular area: "<<maxRectangleArea(height, n)<<endl;

    // vector<int> arr;
    // arr.push_back(6);
    // arr.push_back(7);
    // arr.push_back(5);
    // arr.push_back(2);
    // arr.push_back(4);
    // arr.push_back(5);
    // arr.push_back(9);
    // arr.push_back(3);
    // cout<<"\nMaximum rectangular area: "<<largestRectangleArea(arr)<<endl;

    return 0;
}