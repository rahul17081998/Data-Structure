/*
You have an initial power of power, an initial score of 0, and a bag of tokens where tokens[i] is the value of the ith token (0-indexed).

Your goal is to maximize your total score by potentially playing each token in one of two ways:

If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.
If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.
Each token may be played at most once and in any order. You do not have to play all the tokens.

Return the largest possible score you can achieve after playing any number of tokens.

 
*/
// TC = O(NlogN), SC = O(1)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // sort the tokens array
        sort(tokens.begin(), tokens.end());
        // take two pointers left and right
        int l=0, r=tokens.size()-1;
        int score=0,  ans = 0;
        while(l<=r){
            // power down: decrese the power: p = p-tokens[left], score=score+1, left = left+1
            if(power>= tokens[l]){
                power = power-tokens[l];
                l++;
                score++;
            }
            else{
                /* Two cases here can occurs
                 1. if score is > 0 then pickup the tocken from right side and 
                 increse the power and reduce the score
                 2. if score is 0 then terminate the while loop and return best answer 
                 till now we get */
                 if(score>0){
                     power = power + tokens[r];
                     r--;
                     score--;
                 }
                 else break;
            }
            ans = max(ans, score);
        }
        return ans;
    }
};