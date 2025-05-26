// Edit distance problem : recursive approch
// you have given 2 string you have to make string 1 as string 2 by doing insert, delete and replacement operation
// using each operation edit distance will be considered as 1.

#include<bits/stdc++.h>
using namespace std;

// minimum of three number
int minimum(int d1, int d2, int d3)
{
        int mini1 = min(d1, d2);
        int mini2 = min(d2, d3);
        return min(mini1, mini2);
}

// recursive approch to find edit distnce problem
int editD(string s1, string s2, int m, int n)
{
    // base cases: 
    
    if(m==0) return n;  // if srting s1 is null, it requires n insert operations
    if(n==0) return m;  // if srting s2 is null, it requires m insert operations
    // if both last character matched
    if(s1[m-1] == s2[n-1]){
        return editD(s1, s2, m-1, n-1);
    }
    else{
        // compare min
        return 1 + minimum(editD(s1, s2, m, n-1), // insert 
                            editD(s1, s2, m-1, n), // delete
                            editD(s1, s2, m-1, n-1));  // replace
    }
}


int main(){
    string s1,s2;
    s1 = "SATURDAY";
    int m = s1.length();
    s2 = "SANDAY";
    int n = s2.length();
    /*
    o/p: AZ matches from s1 and s2 thats why its lcs is 2
    */
    cout<< "Edit distance is: "<<editD(s1,s2,m,n)<<endl;
    return 0;
}