/**
 * Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. 
 * If there is no possible result, return the empty string
 */


#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    static bool cmp(string &s1, string &s2){
        if(s1.length()>s2.length()){
            return true;
        }
        else if(s1.length()==s2.length()){
            int equalOrNot = s1.compare(s2);

            if (equalOrNot == 0) {
                return true;
            } 
            else if (equalOrNot > 0) {
                return false;
            } 
            else {
                return true;
            }
        }
        else{
            return false;
        }

    }

    // check if word can be formed by deleting some of the characters or without deletin from S
    bool isPresent(string s, string word){
        // check if length of s is smaller than word length than word can not form
        if(s.length()<word.length()) 
            return false;

        int i=0, j=0; // take two pointers,  i pointing char of "s", j pointing char of "word"

        while(i<s.length() && j<word.length()){
            if(s[i]==word[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        if(j==word.length()) // check if your jth pointer passes last char of "word" than you find it in 's'
            return true;
        return false;
    }
    // main function call
    string findLongestWord(string s, vector<string>& dictionary) {

        // sort the word: ggreater length words comes first and if two word have same length 
        // then sort with the smallest lexicographical order
        sort(dictionary.begin(), dictionary.end(), cmp);

        for(auto word: dictionary){
            // check if this word is present in s in ordered way
            if(isPresent(s, word))
                return word;
        }
        return ""; // return empty string 
    }
};

int main(){
    string s = "abpcplea";
    vector<string> dictionary;
    dictionary.push_back("ale");
    dictionary.push_back("apple");
    dictionary.push_back("monkey");
    dictionary.push_back("plea");

    Solution obj; // creating an object of solution class
    cout<<obj.findLongestWord(s, dictionary)<<endl;
    return 0;
}

/*
Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
*/
