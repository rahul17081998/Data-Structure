// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/sum-of-nodes-in-kth-level/problem


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int convertNum(string str){
    int num=0;
    for(int i=0; i<(int)str.size(); i++){
        num = num*10 + (str[i]-'0');
    }
    return num;
    
}

int solve(string &s, int k)
{
    int n = s.length();
    int level = -1;
    int sum=0;
    
    int i=0;
    while(i<n)
    {
        if( s[i]=='(' )
            level++;
        else if( s[i]==')' )
            level--;
        else{
            if(level==k){
                string num="";
                while(i<n && s[i]!='(' && s[i]!=')'){
                    num.push_back(s[i]);
                    i++;
                }
                i--;
                sum += convertNum(num);
            }
        }
        i++;
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int k;
    string s;
    cin>>k;
    cin>> s;
    
    cout<<solve(s, k)<<"\n";
    return 0;
}
