/*
https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/submissions/
Count "AAA" and "BBB" and compare them

You can only remove an A that is surrounded by two other A's.
So if you keep on removing valid A's, then the valid B's are not affected. Same goes for all valid B's.
You just count all the valid A's and valid B's. At each turn, Alice removes a valid A and the count of all valid A's (countA) decreases by one. Similarly after Bob's turn, countB decreases by one.
So if countA > countB, then a turn comes when Bob has no valid B's to remove. So he loses and Alice wins. You return TRUE.
Else if countA == countB, then at some point Alice has no valid A's to remove, So Bob wins and you return FALSE.
Else (countA < countB), then at some point Alice has no valid A's to remove. So Bob wins and you return FALSE.

In either case, if countA <= countB, then you return FALSE.
So just return countA > countB
*/
class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int a=0, b=0;
        for(int i=1; i<colors.length(); i++){
            if(colors[i-1] == colors[i] && colors[i] == colors[i+1]){
                if(colors[i]=='A')
                    a++;
                else
                    b++;
            }
        }
        return a>b;
    }
};