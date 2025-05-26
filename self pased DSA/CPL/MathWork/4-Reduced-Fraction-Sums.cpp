//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
/*You are required to complete this function*/
void addFraction(int num1, int den1, int num2,int den2)
{
//Your code here
    int nx = num1*den2 + num2*den1;
    int dx = den1*den2;
    int gcf = gcd(nx,dx);
    // cout<<endl;
    // cout<<nx/gcf<<"/"<<dx/gcf<<endl;
    string ans = "";
    ans = to_string(nx/gcf) + "/" + to_string(dx/gcf);
    cout<<ans<<endl;
 }

void solve1(string s){
    int num1, den1,num2,den2;
    vector<int> v;
    int i=0;
    int n = s.length();


    string sn="";
    int start=0;
    while(i<n)
    {
       
        if(s[i]!='/' || s[i]!='+')
            sn = sn + s[i];
        else if(s[i]=='+' || s[i]=='/'){
            cout<<sn<<" ";
            sn="";
        }
        
        if(s[i]=='/' || s[i]=='+'){
        
        // cout<<s.substr(start, i-start)<<" ";
        string st = s.substr(start, i-start);
        int a = stoi(st);
        v.push_back(a);
        start=i+1;
        }
        i++;
        
    }
    // cout<<s.substr(start, i-start)<<" ";
    string st = s.substr(start, i-start);
    int a = stoi(st);
    v.push_back(a);
    addFraction(v[0], v[1], v[2], v[3]);
}

void fun(vector<string> num)
{
    for(int i=0; i<num.size(); i++){
        solve1(num[i]);
        cout<<endl;
    }
}
int main()
{
   



    string s1 = "722/148+360/176";
    vector<string> num;
    num.push_back("722/148+360/176");
    num.push_back("978/1212+183/183");
    num.push_back("358/472+301/417");
    num.push_back("780/309+684/988");
    num.push_back("258/840+854/686");
    fun(num);
    return 0;
}
// 722/148+360/176
// 978/1212+183/183
// 358/472+301/417
// 780/309+684/988
// 258/840+854/686
// } Driver Code Ends




 /*
 
2
384 887 778 916
794 336 387 493

o/p:
520915/406246
260737/82824
 */