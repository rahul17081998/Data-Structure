/*
You are given a 0-indexed string expression of the form "<num1>+<num2>" where <num1> and <num2> represent positive integers.

Add a pair of parentheses to expression such that after the addition of parentheses, expression is a valid mathematical expression and evaluates to the smallest possible value. The left parenthesis must be added to the left of '+' and the right parenthesis must be added to the right of '+'.

Return expression after adding a pair of parentheses such that expression evaluates to the smallest possible value. If there are multiple answers that yield the same result, return any of them.

The input has been generated such that the original value of expression, and the value of expression after adding any pair of parentheses that meets the requirements fits within a signed 32-bit integer.
*/


class Solution {
public:
    string minimizeResult(string expression) {
        int smallestVal = INT_MAX;
        int leftIndex = -1;
        int rightIndex = -1;
        int plusIndex = -1;

        // find the plus index
        for(int i=0; i<expression.length(); i++){
            if(expression[i]=='+')
            {
                plusIndex=i;
                break;
            }
        }


        // now check every combination 
        for(int i=0; i<plusIndex; i++){
            for(int j=plusIndex+1; j<expression.length(); j++){
                string n1str = expression.substr(0, i);
                int n1 = 1;
                if(n1str.length()>0) 
                    n1 = stoi(n1str);

                string n2str = expression.substr(i, plusIndex-i);
                int n2 = stoi(n2str);

                string n3str = expression.substr(plusIndex+1, j+1 -(plusIndex+1));
                int n3 = stoi(n3str);

                string n4str = expression.substr(j+1);
                int n4=1;
                if(n4str.length()>0) 
                    n4 = stoi(n4str);

                int currentVal = n1*(n2+n3)*n4;
                if(currentVal < smallestVal){
                    smallestVal = currentVal;
                    leftIndex=i;
                    rightIndex=j+1;
                }
            }
        }

        string ans="";
        ans += expression.substr(0, leftIndex);
        ans += "(";
        ans += expression.substr(leftIndex, rightIndex-leftIndex);
        ans += ")";
        ans += expression.substr(rightIndex);
        return ans;
    }
};