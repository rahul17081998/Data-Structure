#include<bits/stdc++.h>
using namespace std;
const int CHAR=256;
// Method 1 
bool areAnagram(string &pat,string &txt,int i)
{
    int count[CHAR]={0};
    for (int j = 0; j < pat.length(); j++)
    {
        count[pat[j]]++;    // counting individual characters counts in pat
        count[txt[i+j]]--;  // decreasing count of individual characters
    }
    for (int j = 0; j < CHAR; j++)
    {
        if(count[j]!=0) // if count is 0 for each character than it is[the window we chose] match with the pat give
            return false;
    }
    return true;
}
bool isPresent(string &txt, string &pat)
{
    int n=txt.length();
    int m=pat.length();
    for (int i = 0; i <=n-m; i++)
    {
        if(areAnagram(pat,txt,i))
            return true;
    }
    return false;

}

// Effective method
// method 2
// time = O(n*CHAR), aux.space=O(CHAR)


// check if both have same characters and equal counts than match(true)
bool areSame(int CT[],int CP[])
{
    for (int i = 0; i < CHAR; i++)
    {
        if(CT[i]!=CP[i])
            return false;
    }
    return true;
}
bool IsPresent(string &txt,string &pat)
{
    int CT[CHAR]={0},CP[CHAR]={0};
    for (int i = 0; i < pat.length(); i++)
    {
        CT[txt[i]]++;// counting individual characters counts in txt and store into CT array
        CP[pat[i]]++;// counting individual characters counts in pat and store into CP array
    }
    for (int i = pat.length(); i < txt.length(); i++)
    {
        // if both have same characters count than match--> Return true
        if(areSame(CT,CP))
            return true;
        // if noh match than
        CT[txt[i]]++;// take next character from txt string and count 
        CT[txt[i-pat.length()]]--;// decrese starting index charecter
    }
    return false;
}

int main(){
    string txt="geeksforgeeks";
    string pat="frog";
    // Method 1
    cout<<isPresent(txt,pat);
    cout<<endl;
    // Method 2
    if(IsPresent(txt,pat))
        cout<<"Anagram search found";
    else
        cout<<"Anagram search not found";
    return 0;
}