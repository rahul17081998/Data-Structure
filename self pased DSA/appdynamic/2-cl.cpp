#include<bits/stdc++.h>
using namespace std;

void solve(string pattern, int index, int patSize, int oneDayWork, vector<string> &ans, int resWork, int count)
{
    if(resWork<0) return;
    if(count==0){    
        if(resWork==0){
            ans.push_back(pattern);
        }
        return;
    }

    int i;
    for (i = index; i < patSize; i++){
        
        if(pattern[i]== '?'){
            for(int j=0;j<=oneDayWork;j++)
            {
                char ch=(char)(j+'0');
                pattern[i]=ch;
                solve(pattern,i+1,patSize,oneDayWork,ans, resWork-j, count-1);
                pattern[i]='?';
            }
        }
    }
}



int main()
{
    // input
    int d = 4; // maximum work in a day
    int workHours = 24; // total work hours
    string pattern = "08??840";
    

    vector<string> ans;
    int n = pattern.length();

    int count=0;
    int workDone=0; // work done
    for (int i = 0; i < n; i++)
    {
        if(pattern[i]=='?')
            count++;
        else{
            workDone += (pattern[i]-'0');
        }
    }

    int rem = workHours-workDone;

    int i;
    for ( i = 0; i < pattern.length(); i++){
        if(pattern[i]=='?'){
            for(int j=0;j<=d;j++){
                char ch=(char)(j+'0');
                pattern[i]=ch;
                solve(pattern,i+1,n,d,ans, rem-j, count-1);
                pattern[i]='?';
            }
        }
    }
    

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    
    return 0;
}

