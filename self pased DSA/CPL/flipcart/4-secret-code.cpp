// #include<bits/stdc++.h>
// using namespace std;

// /*  problem:
// Bob has to send a secret code S to his boss. He designs a method to encrypt the code using two key 
// values N and M. The formula that he uses to develop the encrypted code is shown below:
// (((S^N%10)^M)%1000000007)
// Write an algorithm to help Bob to encrypt the code.

// Input:
// The input to the function/method consists of three arguments secretCode, an integer representing the
//  secret code (S) valueN, an integer representing the key valueN.
// valueM. An integer representing the key value M.
// Output:
// Return an integer representing the code encrypted by BOB

// Constraints:
// 1<=secret code<=10⁹
// 0<=value N<=10¹⁰
// 0<=value M<=10¹⁰
// */
// int solve(int s, int n, int m){
//     long long int ans1 = pow(s,n);
//     ans1 = ans1%10;
//     long long int ans2 = pow(ans1, m);
//     ans2 = ans2%1000000007;
//     return (int)ans2;    
// }

// int main(){
//     int s ,n, m;
//     s = 100004;
//     n = 3;
//     m = 4;
//     cout<<solve(s,n,m)<<endl;
//     return 0;
// }
// 
// Testcase 1:
// Input:
// 2, 3, 4

// Expected Return Value:
// 4096
// 


#include <iostream>
using namespace std;

int power(int base, int exponent)
{
  int mul=1;
  for(int i=0; i<exponent; i++) mul *= base;
  return mul;
}
int main() 
{
    int s,n,m; cin>>s>>n>>m;
  	int res = power( power(s,n)%10, m) % 1000000007;
  	cout<<res;
    return 0;
}

// 3 1000000007 4