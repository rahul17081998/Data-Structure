/*
convert Roman to integer
28 dec 2021
*/
#include<bits/stdc++.h>
using namespace std;
int romanToInt(string s) {
        int res=0;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            if(i>0)
            {
                if(s[i]=='V' && s[i-1]=='I')
                    res=res-2*1;
                else if(s[i]=='X' && s[i-1]=='I')
                    res=res-2*1;
                else if(s[i]=='L' && s[i-1]=='X')
                    res=res-2*10;
                else if(s[i]=='C' && s[i-1]=='X')
                    res=res-2*10;
                else if(s[i]=='D' && s[i-1]=='C')
                    res=res-2*100;
                else if(s[i]=='M' && s[i-1]=='C')
                    res=res-2*100;
            }
            if(s[i]=='M')
                // m=1000;
                res=res+1000;
            else if(s[i]=='D')
                // m=1000;
                res=res+500;
            else if(s[i]=='C')
                // m=1000;
                res=res+100;
            else if(s[i]=='L')
                // m=1000;
                res=res+50;
            else if(s[i]=='X')
                // m=1000;
                res=res+10;
            else if(s[i]=='V')
                // m=1000;
                res=res+5;
            
            else if(s[i]=='I')
                // m=1000;
                res=res+1;
            
        }    
        return res;
    }
int main(){
    string str = "XXIV";

    cout<<romanToInt(str);
    return 0;
}