/**
 * Date: 25/08/2022
 * Minimum Time to Remove All Cars Containing Illegal Goods:
 * problem statement:
 * 
 * You are given a 0-indexed binary string s which represents a sequence of train cars. 
    s[i] = '0' denotes that the ith car does not contain illegal goods and s[i] = '1' 
    denotes that the ith car does contain illegal goods.
    As the train conductor, you would like to get rid of all the cars containing illegal goods. 
    You can do any of the following three operations any number of times:
    Remove a train car from the left end (i.e., remove s[0]) which takes 1 unit of time.
    Remove a train car from the right end (i.e., remove s[s.length - 1]) which takes 1 unit of time.
    Remove a train car from anywhere in the sequence which takes 2 units of time.
    Return the minimum time to remove all the cars containing illegal goods.
    Note that an empty sequence of cars is considered to have no cars containing illegal goods.


 * 
 * 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(string s) {
        
        int n = s.length();
        // create an array for store input in number array
        int nums[n];
        for(int i=0; i<n; i++)
            nums[i]=s[i]-'0';
        
        // calculate left cost
        int leftcost[n];
        leftcost[0]=nums[0];
        for(int i=1; i<n; i++)
        {
            // take min of cost removing train car from left end cost
            // and cost if we remove it as middle (previous cost + cost of goods[ that is  if char is 0 then 0 if char is 1 then cost 2] )
            leftcost[i]=min(i+1, leftcost[i-1] + (nums[i]==1?2:0));
        }
        
        // calculate right cost
        int rightcost[n];
        rightcost[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            // take min of cost removing train car from right end cost
            // and cost if we remove it as middle[previous cost that is rightcost[i+1] + cost of goods[ that is  if goods is legal then 0 if illegal then cost 2] ]
            rightcost[i] = min(n-i, rightcost[i+1] + (nums[i]==1?2:0));
        }
        
        // merge these two array and find minimum of ther
        // merge[i] = left[i] + right[i+1]
        // take min of cost associated with left array i.e leftcost[i] and  cost asscocited with right array(rightcost[i+1])
        int mini = rightcost[0] + 0; // take first cost of roght array
        for(int i=0; i<n; i++)
        {
            int left = leftcost[i];
            int right;
            if(i==n-1) // last cost of left 
                right=0;
            else
                right=rightcost[i+1];
            mini = min(mini, left+right);
        }
        
        return mini;
    }
};

int main(){
    // input
    string s="1100101";
    // o/p: 5
    Solution ob;
    cout<<ob.minimumTime(s)<<endl;
    return 0;
}