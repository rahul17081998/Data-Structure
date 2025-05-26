#include<bits/stdc++.h>
using namespace std;

//write your function here
// Example
// processes = [10, 4, 8, 13, 20)
// m=2

int solve(vector<int> processor, int m)
{
    int n = processor.size();
    int sum=0;
    int i=0;

    while(i<m){
        sum += processor[i];
        i++;
    }
    // sliding window apply here
    int maxSum = sum;
    int j=0; // end pointer of sliding window

    while(i<n){
        sum = sum + processor[i];
        sum = sum - processor[j];
        i++;
        j++;
        maxSum = max(maxSum, sum);
    }

    int totalSum=0;
    for(int i=0; i<n; i++){
        totalSum += processor[i];
    }

    return (totalSum - maxSum);
}

int main(){
    vector<int> processor;
    int m=2;
    processor.push_back(10);
    processor.push_back(4);
    processor.push_back(8);
    processor.push_back(13);
    processor.push_back(20);

    cout<<solve(processor, m)<<endl;
    cout<<"yes"<<endl;
    return 0;
}




/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>process={10,4,8,1};
    int m=2;
    int sum=0;
    int i=0;
    int n=process.size();
    while(i<m)
    {
        sum+=process[i];
        i++;
    }
    int ma=sum;
    int j=0;
    while(i<n)
    {
        sum=sum-process[j];
        sum+=process[i];
        i++;
        j++;
        ma=max(ma,sum);
    }
    int x=0;
    for(auto y:process)
    {
        x+=y;
    }
    cout<<x-ma<<endl;
}
*/