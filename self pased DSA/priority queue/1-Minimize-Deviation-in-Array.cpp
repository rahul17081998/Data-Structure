/*
You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
*/

class Solution {
public:
    /*
    Approach: here we are doing two operation in the problem, like if a number is odd then we could multiply 
    with 2(after that it becomes even) and in even number we could divide based on our requirement.
    So we will find all the odd number and multiply by 2 so that it becomes even and then all elements of 
    all becomes even and find minimum ele then we will push all elements into priority queue, so that we 
    will always get maximum from top every time we will pop a top elements from the priority queue untill 
    we get a odd value on the top. and that poped element will be maximum element of the array. update minimum 
    diff, 
    diff = min(diff, maximum-minimum) then push maximum/2 into the pq, if maximum if not a odd number.
    we have to update the minimum elements also because when we push the maxEle/2 into pq then it could be 
    minimum in all values.

    */
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        // make all the value of array even and then push them into priority queue
        int minEle = INT_MAX;
        for(int val: nums){
            // check if val is odd, make it even by mul by 2
            if(val%2==1){
                pq.push(val*2);
                minEle = min(minEle, val*2);
            }
            else{ // even elements
                pq.push(val);
                minEle = min(minEle, val);
            }
        }

        int ans = INT_MAX;
        while(!pq.empty()){
            int maxEle = pq.top();
            pq.pop();
            ans = min(ans, maxEle-minEle);
            // if top element of the priority queue is odd then terminate it, we get min diff
            if(maxEle%2==1){
                break;
            }
            pq.push(maxEle/2);
            // we have to update the minimum elements also because when we push the maxEle/2 into pq
            // then it could be minimum in all values
            minEle = min(minEle, maxEle/2);
        }
        return ans;
    }
};
