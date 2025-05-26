/* C++ program to find the length of the smallest
substring consisting of maximum distinct characters */
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// brute force approach
#define NO_OF_CHARS 256
 
// Find maximum distinct characters in any string
int max_distinct_char(string str, int n){
 
    // Initialize all character's count with 0
    int count[NO_OF_CHARS] = {0};
     
    // Increase the count in array if a character
    // is found
    for (int i = 0; i < n;  i++)
        count[str[i]]++;
     
    int max_distinct = 0;
    for (int i = 0; i < NO_OF_CHARS;  i++)
        if (count[i] != 0)     
            max_distinct++;    
     
    return max_distinct;
}
 
int smallesteSubstr_maxDistictChar(string str){
 
    int n = str.size();     // size of given string
 
    // Find maximum distinct characters in any string
    int max_distinct = max_distinct_char(str, n);
    int minl = n;   // result
     
    // Brute force approach to find all substrings
    for (int i=0 ;i<n ;i++){
        for (int j=0; j<n; j++){
            string subs =  str.substr(i,j);
            int subs_lenght = subs.size();
            int sub_distinct_char = max_distinct_char(subs, subs_lenght);
             
            // We have to check here both conditions together
            // 1. substring's distinct characters is equal
            //    to maximum distinct characters
            // 2. substring's length should be minimum
            if (subs_lenght < minl && max_distinct == sub_distinct_char){
                minl = subs_lenght;
            }
        }
    }
    return minl;
}

// A function which accepts a string and returns length of
// the smallest substring consisting of maximum distinct
// characters
int smallesteSubstr_maxDistictChar(string str)
{
	// to get the number of unique characters
	unordered_set<char> st;
	// traverse the string once and store the characters
	for (int i = 0; i < str.length(); i++)
		st.insert(str[i]);
	// number of unique characters
	int unique = st.size();
	unordered_map<char, int> mp;
	// to store the result
	int res = INT_MAX;
	int j = 0; // starting index of window
	for (int i = 0; i < str.length(); i++) {
		// add the current chararcter in window
		mp[str[i]]++;
		// while number of distinct elements in the map is
		// equal to unique characters and starting element
		// of the window has frequency more than one we keep
		// reducing its frequency and increasing the
		// starting point of the window
		while (mp.size() == unique && mp[str[j]] > 1) {
			mp[str[j]]--;
			j++;
		}
		// if size of map is equal to unique elements update
		// the result
		if (mp.size() == unique)
			res = min(i - j + 1, res);
	}
	return res;
}

int solve(string str){
    unordered_set<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        st.insert(str[i]);
    }
    int unique = st.size();

    unordered_map<char,int> mp;
    int res = INT_MAX;
    int j = 0; // starting index of window

    for (int i = 0; i < str.length(); i++)
    {
        mp[str[i]]++;
        while(mp.size()==unique && mp[str[j]]>1)
        {
            mp[str[j]]--;
            j++;
        }
        if(mp.size()==unique)
            res = min(i-j+1, res);
    }
    return res;
}
/* Driver program to test above function */
int main()
{
	// Input String
	string str = "AABBBCBB";

	int len = smallesteSubstr_maxDistictChar(str);
	cout << " The length of the smallest substring"
			" consisting of maximum distinct "
			"characters : "
		<< len<<endl;
    cout<< solve(str)<<endl;
	return 0;
}

// This code was contributed by Abhijeet Kumar(abhijeet19403)
