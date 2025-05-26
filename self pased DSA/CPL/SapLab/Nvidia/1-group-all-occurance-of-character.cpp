#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*
Given a string of lowercase characters, the task is to print the string in a
manner such that a character comes first in string displays first with all
its occurrences in the string.
Examples:
Input : str = "occurrence"
output : occcurreen
         occcurreen
Input : str = "cdab"
Output : cdab
Assume only lower case alphabets.
Locate and fix the errors in the implementation of the
function printGrouped
*/


class Solution{
public:
    string printGrouped(string str){
        // store all the char freq int a map
        unordered_map<char, int> mp;
        for(int i=0; i<str.length(); i++){
            mp[str[i]]++;
        }

        string nstr =""; // new string 
        unordered_set<char> st;
        for(int i=0; i<str.length(); i++){
            // check if char present
            if(mp.find(str[i])!=mp.end())
            {
                int count = mp[str[i]];
                for(int j=0; j<count; j++){
                    nstr.push_back(str[i]);
                }
                mp.erase(str[i]); // delete the char from map so that we can use it further
            }
        }
        return nstr;
    }
};

int main(){
    string str = "occurrence";
    Solution obj;
    cout<<obj.printGrouped(str)<<endl;
    return 0;
}
