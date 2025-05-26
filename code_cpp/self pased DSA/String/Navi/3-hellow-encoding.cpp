#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//write your function here
string fun(string s)
{
    int n = s.length();
    unordered_map<char, char>mp;
    int count=0;
    for(int i=0; i<s.length(); i++){
        if(mp.find(s[i])==mp.end()){
            mp[s[i]]= 'A'+count;
            count++;
        }
    }
    string str="";
    for(int i=0; i<n; i++){
        str.push_back(mp[s[i]]);
    }
    return str;
}

string solution(string s)
{
    map<char,char>mp;
    string str="";
    for(int i=0;i<s.size();i++)
      {
          if(mp.find(s[i])==mp.end())
            mp[s[i]]='A'+i;
      }
     
     for(int i=0;i<s.size();i++)
         str+=mp[s[i]];
   
     return str;  
}


int main(){
    cout<<fun("HELLO")<<endl;
    cout<<solution("HELLO")<<endl;
    return 0;
}