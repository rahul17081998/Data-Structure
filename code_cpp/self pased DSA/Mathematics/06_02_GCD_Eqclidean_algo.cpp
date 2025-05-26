#include<iostream>
#include<math.h>
using namespace std;
                                // Eucliden algorithm optimeised version
// int gcdEa(int a, int b){
//     if(b == 0){
//         return a;
//     }
//     else{
//         return gcdEa(b, a%b);
//     }
// }

                                // Eucliden algorithm

// int gcd1(int a, int b){
//     while(a != b)
//     {
//         if(a>b)
//         {
//             a = a-b;
//         }
//         else
//         {
//             b = b-a;
//         }
//     }
//     return a;
// }

                                // GCD using general method 
int gcd2(int a, int b)
{
    int res = min(a,b);
    while(res>0)
    {
        if(a%res == 0 and b%res == 0)
        {
            break;
        }
        res--;
    }
    return res;
}

int main(){
    // cout<<gcdEa(3,15);
    // cout<<gcd1(30,15);
    cout<<gcd2(3,5);
    return 0;
}