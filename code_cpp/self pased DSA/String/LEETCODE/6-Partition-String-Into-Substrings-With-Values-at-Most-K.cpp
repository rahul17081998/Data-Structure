#include<bits/stdc++.h>
using namespace std;

//write your function here

class Solution {
public:
    long long int stringToNum(string s){
        long long int num=0;
        for(int i=0; i<s.length(); i++){
            long long int val = s[i]-'0';
            num = num*10+val;
        }
        return num;
    }
    int minimumPartition(string s, int k) {
        int i=0, j=0;
        int n = s.length();
        int count=0;
        // corner case : if 1<=k<=9
        if(k>0 && k<=9){
            for(int l=0; l<n; l++){
                int x=s[l]-'0';
                if(x>k)
                    return -1;
            } 
        }

        while(j<n){
            string sub = s.substr(i, j-i+1);
            long long int val = stringToNum(sub);
            if(val>k){
                count++;
                i=j;
            }
            j++;

            if(j==n){
                if(i!=j){
                    count++;
                }
            }
        }
        return count;
    }
};



int main(){
     Solution obj;
     string s = "1533525";
     int k=24;

     cout<<obj.minimumPartition(s, k)<<endl;
    return 0;
}