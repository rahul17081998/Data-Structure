// LEETCODE LINK: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/submissions/
#include <iostream>
using namespace std;
int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

int gcd(int a, int b){
   if(b==0) return a;
   else{
      return gcd(b, a%b);
   }
}
int main() {
   int a = 105, b = 30;
   cout<<"GCD of "<< a <<" and "<< b <<" is "<< gcd(a, b);
   return 0;
}