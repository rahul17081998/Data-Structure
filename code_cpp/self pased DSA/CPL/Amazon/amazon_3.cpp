#include <bits/stdc++.h>
using namespace std;
void tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out)
{
    size_t start;
    size_t end = 0;
 
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}
int main()
{
    // int n;
    // cin>>n;
    // vector<string>requests(n);
    // for(int i=0;i<n;i++)
    // {
    //     getline(cin,requests[i]);
    // }
    vector<string> requests = {"register david david123" , "register saurabh sathe" , 
	                        "login david david123" , "login saurabh david1234" , "logout david" } ;
    unordered_map<string,pair<string,int>>map;
    for(int i=0;i<5;i++)
    {
        string s=requests[i];
        vector<string>str;
        tokenize(s,' ',str);
        
        if(str[0]=="register")
        {
            string user=str[1];
            string pass=str[2];
            // cout<<str[2]<<endl;
            if(map.find(user)!=map.end())
            {
                cout<<"Username already exists"<<endl;
            }
            else 
            {
                pair<string ,int>p;
                p.first=pass;
                p.second=0;
                map[user]=p;
                // cout<<map[user].first<<endl;
                cout<<"Registered Successfully"<<endl;
            }
        }
        else if(str[0]=="login")
        {
            string user=str[1];
            string pass=str[2];
            if(map.find(user)==map.end())
            {
                cout<<"Login Unsuccessful"<<endl;
            }
            else 
            {
                pair<string,int>p=map[user];
                // cout<<p.first<<endl;
                if(pass!=p.first || p.second==1)
                {
                    // cout<<pass<<" fggggggggggg"<<p.first<<endl;
                    cout<<"Login Unsuccessful"<<endl;
                }
                else 
                {
                    map[user]={pass,1};
                    cout<<"Login Successful"<<endl;
                }
            }
        }
        else 
        {
            string user=str[1];
            if(map.find(user)==map.end())
            {
                cout<<"Logout Unsuccessful"<<endl;
            }
            else 
            {
                 pair<string,int>p=map[user];
                if(p.second==0)
                {
                    cout<<"Logout Unsuccessful"<<endl;
                }
                else 
                {
                    map[user]={p.first,0};
                    cout<<"Logout Successful"<<endl;
                }
            }
        }
 
    }
}