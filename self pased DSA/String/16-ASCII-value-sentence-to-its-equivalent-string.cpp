#include<bits/stdc++.h>
using namespace std;

//write your function here
void asciiToSentence(string str)
{
    string ans="";
    int num=0;
    for(int i=0; i<str.length(); i++)
    {
        num = num*10 + (str[i]-'0');
        // check if the number is within the range
        if(num >= 32 && num<=122)
        {
            // convert num to char
            char ch = (char)num;
            ans.push_back(ch);
            num=0; // reset the num
        }
    }
    cout<< ans<<endl;
}

int main(){
    string str = "7110110110711510211111471101101107115";
    asciiToSentence(str);
    return 0;
}