/*
Print longest common substring(LCS)
Example

string a = "acbcf"
string b = "abcdaf"

o/p: abcf

*/

#include<bits/stdc++.h>
using namespace std;

// int LCS(string s1, string s2, int m, int n, int t)
string LCS_print(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    //******* Pert 1 ---> LCS table creation ********//
    // create a t array of size (m+1)x(n+1)
    int t[m+1][n+1];
    // base case 
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }
    // write choice diagram code for LCS
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s1[i-1] == s2[j-1])
                t[i][j] = 1+t[i-1][j-1];
            else 
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    // table created 
    // **** Part2 ---> print LCS ******//

    // now we will traverse from last cell of 
    // table and print LCS

    int i = m;
    int j = n;
    string ans="";

    while(i>0 && j>0)
    {
        if(s1[i-1] == s2[j-1]) //  if char matches, store and go to t[i-1][j-1] position
        {
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        // go to that column which have maximum value(left and upper)
        else{ // char not matches
            if(t[i][j-1] > t[i-1][j]){ // if left side value is greater than upper side
                j--;
            }
            else{
                i--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    string s1 = "abaaa";
    string s2 = "baabaca";

    cout<<"Print LCS: "<<LCS_print(s1, s2)<<endl;
    return 0;
}
