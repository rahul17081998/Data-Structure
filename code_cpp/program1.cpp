#include<bits/stdc++.h>
#include<unordered_set>

// #include<string>

using namespace std;

class Solution {
public:
    string solve(string &A, string &B)
    {
        unordered_set<char> s;
        // store all characters which are present in B
        for(int i=0; i<B.length(); i++)
        {
            s.insert(B[i]);
        }

        // store result
        string C="";
        // subtract all characters from A which are found in B

        for(int i=0; i<A.length(); i++)
        {
            // check if char of A is not in B
            if(s.find(A[i])==s.end())
            {
                C.push_back(A[i]);
            }
        }
        return C;
    }
};
int main()
{
	// take input
    string A;
    string B;
    cin>> A;
    cin>> B;

    // string A = "talent";
    // string B = "tens";
    
    Solution ob;
    cout<<ob.solve(A, B)<<endl;
    return 0;
}
