#include <bits/stdc++.h>
using namespace std;

int MaxJobScheduling(int n, int m, int k)
{
    // n: No of processor 
    // m: No of jobs
    // k = kth processor


    if(n==m) return 1;
    vector<int> arr(n, 1);

    m = m-n;
    int count=1, i=k-1;

    int left=i, right=i;
    // arr[i]= arr[i]+1;
    while(m>0)
    {
        // jobs required
        int reqJob = right-left+1;
        if(m >= reqJob){
            count++;
            m = m-reqJob;
            if(right<n-1) right++;
            if(left>0) left--;
        }
        else{
            m=0;
        }
    }
    return count;
}



int main()
{
    int n=5, m=11, k=3; // n: No of processor,  m: No of jobs,  k = kth processor
    cout<<MaxJobScheduling(n,m,k)<<endl;
    return 0;
}