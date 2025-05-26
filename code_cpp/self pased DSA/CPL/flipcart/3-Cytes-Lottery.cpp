/*#include <bits/stdc++.h>
using namespace std;

bool f(string drawString, string ticket, int i, int j, int k, int flag, vector<vector<vector<vector<int> > > > &dp) {
if(j < 0) return true;
if(i < 0) return false;

if(dp[i][j][k][flag] != -1) return dp[i][j][k][flag];
bool ans = false;
if(drawString[i] == ticket[j] || (drawString[i] == 'a' && ticket[j] == 'o') || (drawString[i] == 'o' && ticket[j] == 'a') || 
(drawString[i] == 't' && ticket[j] == 'l') || (drawString[i] == 'l' && ticket[j] == 't')) {
    ans = ans || f(drawString, ticket, i - 1, j - 1, k, 1, dp);
} else if(k > 0 && flag) {
    ans = ans || f(drawString, ticket, i - 1, j, k - 1, 1, dp);
} else if(flag) {
    ans = ans || f(drawString, ticket, i, j - 1, k, 1, dp);
}

if(!flag && drawString.length() >= ticket.length()) {
    ans = ans || f(drawString, ticket, i - 1, j, k, 0, dp);
} else {
    ans = ans || f(drawString, ticket, i, j - 1, k, 0, dp);
}

return dp[i][j][k][flag] = ans;
}

int main() {
int n;
cin >> n;

vector<string> tickets(n);
for(int i = 0; i < n; i++) {
    cin >> tickets[i];
}

string drawString;
cin >> drawString;

int k;
cin >> k;

int ans = 0;
int m = drawString.length();

for(auto it : tickets) {
    int n = it.length();
    vector<vector<vector<vector<int> > > > dp(m, vector<vector<vector<int> > >(n, vector<vector<int> > (k + 1, vector<int>(2, -1))));
    if(f(drawString, it, m - 1, n - 1, k, 0, dp)) ans++;
}

cout << ans << endl;
}*/

/*
Example1:

2
abcde acmfgtld
aabacd
2 

o/p: 1



Example2:
3
ac zb yhja
xyzabc
1
*/


// /*
#include<bits/stdc++.h>
using namespace std;

bool helper(string str,string s,int k,int i,int j,bool mark){
    if(i > str.length() || j > s.length()) return false;
    if(j == s.length()){
        return true;
    }
    if(i == str.length()){
        return false;
    }
    
    // char ch1 = str.charAt(i);
    // char ch2 = s.charAt(j);
    
    char ch1 = str[i];
    char ch2 = s[j];
    bool flag = false;
    
    if(ch1 == ch2 || (ch1 == 'a' && ch2 == 'o') || (ch1 == 'o' && ch2 == 'a') || (ch1 == 't' && ch2 == 'l') || (ch1 == 'l' && ch2 == 't')){
        flag = flag || helper(str,s,k,i+1,j+1,true);

    }else if(k > 0  && mark){
        flag = flag || helper(str,s,k-1,i+1,j,true);
    }
    
    if(!mark)
     flag = flag || helper(str,s,k,i+1,j,false);
    

    return flag;
}
int lotteryTickets(string matchStr, vector<string> tickets, int k) {
	
    int count = 0;
    int n = matchStr.length();

    for(string str : tickets){
        if(helper(matchStr,str,k,0,0,false)) count++;
    }
    return count;
}


int main(){
    // string matchStr="aabacd";
    // int k = 2;
    // vector<string> tickets;
    // tickets.push_back("abcde");
    // tickets.push_back("acmfgtld");

    string matchStr="xyzabc";
    int k = 1;
    vector<string> tickets;
    tickets.push_back("ac");
    tickets.push_back("zb");
    tickets.push_back("yhja");

// 3
// ac zb yhja
// xyzabc
// 1
    cout<<lotteryTickets(matchStr, tickets, k)<<endl;

    return 0;
}
// */
/*
Eg. 
draw string = aabacd, K=2
tickets = [abcde acmfgtld]

o/p: 1
*/