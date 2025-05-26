class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1; //if the input is 0, there is only 1 number with unique digits, which is 0.
        int ans=10, start=9, curr=9; //initialize the answer as 10, start with 9, and curr as 9

        while(n>1 && start){
            curr = curr*start; // curr = curr * start
            ans += curr; // add the curr value to the answer
            start--; // decrement the start value
            n--; // decrement the n value
        }
        return ans; // return the total number of unique digits
    }
};
