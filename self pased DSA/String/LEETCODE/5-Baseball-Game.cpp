#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {

        int n = ops.size();
        
        vector<int> score;
        for(int i=0; i<n; i++)
        {
            // Invalidate and remove the previous score 
            if(ops[i]=="C"){
                score.pop_back();
            }
            // check if ops[i]=D then double the previous no and add that
            else if(ops[i]=="D")
            {
                int num = score.back();
                score.push_back(num*2);
            }
            // check if ops[i]="+" then add last two no of score and push into the score
            else if(ops[i]=="+"){
                int z = score.size();
                int l1 = score[z-1];
                int l2 = score[z-2];
                score.push_back(l1+l2);
            }
            else{ // if ops[i] is an integer
                int num = stoi(ops[i]);
                score.push_back(num);
            }
        }
        
        // add all element of score array
        int sum=0;
        for(int i=0; i<score.size(); i++) sum += score[i];
        return sum;
    }
};

int main(){
    vector<string> ops;
    ops.push_back("5");
    ops.push_back("2");
    ops.push_back("C");
    ops.push_back("D");
    ops.push_back("+");

    Solution ob;
    cout<<ob.calPoints(ops)<<endl;
    return 0;
}
/*
Input: ops = ["5","2","C","D","+"]
Output: 30
*/