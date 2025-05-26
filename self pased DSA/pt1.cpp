#include<bits/stdc++.h>
using namespace std;
int minimumKeypadClickCount(string input)
{
       char right[9][3] = {
           {'a', 'j', 's'},
           {'b', 'o', 't'},
           {'c', 'p', 'u'},
           {'d', 'k', 'v'},
           {'h', 'm', 'z'},
           {'g', 'l', '@'},
           {'e', 'n', 'w'},
           {'f', 'q', 'x'},
           {'i', 'r', 'y'}};
         int n, count1 = 0, count2 = 0;
            n = input.length();
            for (int i = 0; i < n; i++)
            {
                int d = input[i] - 97;
                d = d % 3;
                count1 += (d + 1);
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        if (right[j][k] == input[i])
                        {
                            count2 += (k + 1);
                        }
                    }
                }
            }
            return count2;
            
}
int solve(string s)
{
    char t[9][3]={{'a','b','c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r'},
    {'s', 't', 'u'}, {'v', 'w', 'x'}, {'y', 'z', '@'}};

    

    int n = s.length();
    int count1=0;
    int count2=0;

    // loop to find out key count in left keypad
    for (int i = 0; i < n; i++)
    {
        int d = s[i]-97;
        d = d%3;
        count1 += d+1;
    }

    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<9; j++)
        {
            for(int k=0; k<3; k++)
            {
                if(t[j][k]==s[i])
                    count2 += k+1;
            }
        }
    }

    return count1;
    // return count2;
}
int main(){
    string s = "abcghdiefjoba";
    // string s = "hello";
    // cout<<solve(s)<<endl;
    cout<<minimumKeypadClickCount(s)<<endl;
    return 0;
}