/*
This problem is also called "Josephus Problem". populer in os

There are n friends that are playing a game. The friends are sitting in a circle and 
are numbered from 1 to n in clockwise order. More formally, moving clockwise from the 
ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from 
the nth friend brings you to the 1st friend.

The rules of the game are as follows:

Start at the 1st friend.
Count the next k friends in the clockwise direction including the friend you started at. 
The counting wraps around the circle and may count some friends more than once.
The last friend you counted leaves the circle and loses the game.
If there is still more than one friend in the circle, go back to step 2 starting from the 
friend immediately clockwise of the friend who just lost and repeat.
Else, the last friend in the circle wins the game.
Given the number of friends, n, and an integer k, return the winner of the game.
*/

#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    int findTheWinner(int n, int k) {
        // create a queue and insert all the elements from 1 to n
        queue<int> q;
        for(int i=1; i<=n; i++){
            q.push(i);
        }

        // now remove first k-1 elemts from queue and again insert it into queue
        // and then remove 1 elements, do this operation while queue size is greater than 1
        while(q.size()>1){

            int size=k-1;
            while(size-->0){
                // remove the friend
                int frnd = q.front();
                q.pop();
                // inset this friend again from front of queue
                q.push(frnd);
            }
            q.pop(); // remove the kth friend
        }

        return q.front();// only 1 friend ll left in the queue
    }
};

int main(){
    Solution obj;
    cout<<obj.findTheWinner(5,2)<<endl;
    return 0;
}