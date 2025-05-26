#include<bits/stdc++.h>
using namespace std;

 // convert number into bits
string intToBits(int a)
{
    string s="";
    while(a){
        if(a%2==0)
            s.push_back('0');
        else
            s.push_back('1');
        a = a/2;
    }
    
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    int x=95;
    string s = intToBits(x);
    cout<<s<<endl;
    return 0;
}
