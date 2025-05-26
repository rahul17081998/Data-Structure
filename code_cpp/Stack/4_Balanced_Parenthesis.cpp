// #include<iostream>
// #include<bits/stdc++.h>
// #include<stack>
// using namespace std;

// void checkBalPar(string &str1)
// {
//     // if(str1.length()%2 !=0)
//     // {
//     //     cout<<"No\n";
//     //     exit(1);
//     // }
//     stack<char> s1;
//     int curr=0;
//     for(char str:str1)
//     {
//         if(s1.empty())
//         {
//             s1.push(str);
//         }
//         else if (str==s1.top())
//         {
//             s1.pop();
//         }
//         else 
//         {
//             s1.push(str);
//         }
//     }
//     if(s1.empty()==0)
//     {
//         cout<<"Yes\n";
//     }
//     else 
//     {
//         cout<<"No\n";
//         // cout<<s1.empty();
//     }
// }

// int main(){
//     string s1;
//     cout<<"Enter input: ";
//     cin>>s1;
//     // cout<<s1[0]<<endl;
//     // cout<<s1.length()<<endl;
//     checkBalPar(s1);
//     return 0;
// }

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool matching(char a, char b)
{
    return ((a=='(' && b==')')||
            (a=='{' && b=='}')||
            (a=='[' && b==']'));
}
bool isBalance(string &str)
{
    stack<char> s;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            s.push(str[i]);
        else
        {
            if(s.empty()==true)
                return false;
            else if (matching(s.top(),str[i])==false)
                return false;
            else 
                s.pop();
            
        }
    }
    return (s.empty()==true);
}
int main(){
    string str="{}(([]))";
    if (isBalance(str)) 
        cout << "Balanced"; 
    else
        cout << "Not Balanced"; 
    return 0;
}