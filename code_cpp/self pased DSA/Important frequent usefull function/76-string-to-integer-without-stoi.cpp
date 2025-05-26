#include<bits/stdc++.h>
using namespace std;

//write your function here
long long int stringToNum(string s){
    long long int num=0;
    for(int i=0; i<s.length(); i++){
        long long int val = s[i]-'0';
        num = num*10+val;
    }
    return num;
}

int main(){
    cout<<stringToNum("8242")<<endl;
    return 0;
}