#include<bits/stdc++.h>
using namespace std;

//write your function here
// Generate all perfect square number  from 1 to n
vector<int> perfectSquare(int n)
{
    vector<int> square;
    for(int i=1; i*i<=n; i++){
        cout<<i*i<<" ";
        square.push_back(i*i);
    }
    return square;
}

int main(){
    // input
    int n = 19;
    vector<int> square = perfectSquare(n);
    return 0;
}