/*
Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. 
Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime 
where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
Return the minimum time Bob needs to make the rope colorful.
*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost=0;
        for(int i=1; i<colors.length(); i++){
            // check if two consecutive balloon have same colors
            if(colors[i]==colors[i-1]){
                // we are removeing the balloon which have minimum needtime among (i, i-1) positin so one will left, 
                // now that left balloon need time will be maxmimim of (neededTime[i], neededTime[i-1]), 
                // because we have all ready removed the minimum needtime balloon
                int minCost = min(neededTime[i], neededTime[i-1]);
                cost += minCost; 
                // so how to updtate neededtime ?
                // just update as below
                neededTime[i]=max(neededTime[i], neededTime[i-1]);

            }
        }
        return cost;
    }
};
