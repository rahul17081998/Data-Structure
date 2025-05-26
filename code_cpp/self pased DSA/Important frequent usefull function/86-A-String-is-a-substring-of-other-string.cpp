#include<bits/stdc++.h>
using namespace std;

//write your function here
//check string x is a subsequence of y or not
// check all char is present into other string y or not 
bool isSubsequence(string x, string y)
{
    if(x.length() > y.length()) return false;
    int i=0, j=0;
    while(j < y.size())
    {
        if(x[i]==y[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    if (i==x.length())
        return true;
    return false;
}

int main(){
    // input
    string x = "abca";
    string y = "cdandbncjsda";
    // o/p: 1
    cout<<isSubsequence(x, y)<<endl;
    return 0;
}