/*
There are n people standing in a line labeled from 1 to n. The first person in the line is 
holding a pillow initially. Every second, the person holding the pillow passes it to the 
next person standing in the line. Once the pillow reaches the end of the line, the direction 
changes, and people continue passing the pillow in the opposite direction.
For example, once the pillow reaches the nth person they pass it to the n - 1th person, then 
to the n - 2th person and so on.
Given the two positive integers n and time, return the index of the person holding the pillow 
after time seconds.

Example 1:
I/p: n = 4, time = 5
O/p: 2
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
Afer five seconds, the pillow is given to the 2nd person.
*/

class Solution {
public:
    int passThePillow(int n, int time) {
        // check if no of people is greater than pillow passing time
        if (n>time){
            return 1+time;
        }

        
        int rem = time % (n-1);
        int div = time/(n-1);
        if(div%2 ==1){
            int start = (n-1)-rem;
            return start+1;
        }
        else{
            return 1 + rem;
        }
        return -1;
    }
};

