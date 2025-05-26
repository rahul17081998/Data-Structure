#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "this string contains many alphabets";
    int count[26]={0};
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]-'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if(count[i]>0)
        {
            cout<<char(i+'a')<<" ---> "<<count[i]<<endl;
        }
        // cout<<char(i+'a')<<" ---> "<<count[i]<<endl; // This will print all A-Z
    }
    
    
    return 0;
}