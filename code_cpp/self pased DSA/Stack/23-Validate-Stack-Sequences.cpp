/*
Given two integer arrays pushed and popped each with distinct values, return true if this could have been 
the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
*/



class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int i=0, j=0; // i point pushed array, j point popped array 

        while(i<n){
            st.push(pushed[i]);
            i++;
            // check if top element and popped array at jth position is same then pop from st 
            while(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }

        if(j==n) return true;
        return false;
    }
};