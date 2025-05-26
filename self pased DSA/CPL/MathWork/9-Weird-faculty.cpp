#include<bits/stdc++.h>
using namespace std;
void prt(vector<int> arr){
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
//write your function here
int fun(vector<int> &v)
{
    int n = v.size();
    vector<int> left(n); 
    vector<int> right(n);

    int sum=0;
    for(int i=0; i<n; i++){
        if(v[i]==1){
            sum++;
            left[i]=sum;
        }
        else{
            sum--;
            left[i]=sum;
        }
    }
    sum=0;
    for(int i=n-1; i>=0; i--){
        if(v[i]==1){
            sum++;
            right[i]=sum;
        }
        else{
            sum--;
            right[i]=sum;
        }
    }

    // prt(left);
    // prt(right);

    for(int i=0; i<n; i++){
        if(left[i] > right[i])
            return i;
    }
    return -1;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);

    cout<<fun(v)<<endl;
    return 0;
}