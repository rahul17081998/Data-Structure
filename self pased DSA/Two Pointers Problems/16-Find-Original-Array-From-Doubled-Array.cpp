/*

You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.
*/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // if size of changed array is odd then 
       if(changed.size()%2!=0) return {}; 
       vector<int> freq(100001, 0);
       // count the frequency of each elements 
       for(int x: changed){
           freq[x]++;
       }
        vector<int> ans; // create a array to store the answer its size will be half of side of change array
       for(int no=0; no<freq.size(); no++){
           // for each number which is present into changed array
           //check if freq[no]>0 and freq[no*2]>0 then decrease  and push 'no' into answer array then simaltineously
           while(freq[no]>0 && no*2<100001 && freq[no*2]>0){
               freq[no]--;
               freq[no*2]--;
               ans.push_back(no);
           }
       }
        // check if any of number has frequency other than zero(either +ve/-ve) then its is not possible to find the original array
       for(int i=0; i<freq.size(); i++){
           if(freq[i]!=0) return {};
       }
       return ans;

    }
};