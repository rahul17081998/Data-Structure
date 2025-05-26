/*
Question:
The Teacher wants to divide the group of students for singing competition . Each group will have 
one mic . If the number of mic is greater than the number of groups then teacher can select group 
and divide it such that the largest group among all groups is as small as possible .
Test case 1 :
n = 5 , k =7 ; k is number of groups mics and n is number of groups initially
[10 , 8 , 6 , 3 ,2 ] – > initially number of students in each group .
Output = 6 ;
we can divide the group of 10 into 5 ,5 —> [5,5, 8 ,6 ,3, 2]
again we divide the group of 8 into 4, 4 – > [5 ,5 , 4 ,4 ,6,3 ,2]
The numbers of groups equals to the number of mics Hence the largest group is of size 6 .

Test case 2 :
n = 5 ,k =9
[100 , 80 , 60 ,40 , 30] – > initially number of students in each group .
Output = 40
First divide the group of 100 into 80 , 20 – > [80 ,20 ,80 , 60 , 40 ,30]
Now divide the group of 80 into 40 ,40 --> [40 , 40 , 20 , 80 , 60 ,40 ,30]
again divide the group of 80 into 40, 40 – > [40 , 40 ,20 ,40 ,40 ,60 ,40 ,30]
divide the group of 60 into 30 ,30 --> [40, 40 , 20 , 40 ,40 , 30 ,30 ,40 ,30]
The numbers of groups equals to the number of mics Hence the largest group is of size 40 .



Approach:
This problem can be solved by normal binary search, you can divide the groups (k-n) times.
Now do a binary search on your answer values, first i would try the value 1 , i would count the 
number of divisions required over the array, if it is >(n-k), it is not a possible ans, now search 
on mid value that is 50 as max is 100 in your case,it is possible, next try 25 , not possible, 
next 37 not possible, next 43 possible, next 40 ,possible, next 41 not possible, so 40 will be 
your ans.

Time complexity , O(n logn).
*/
#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &groups, int mics, int n)
{
    // hi can be write as the maximum of groups element
    int lo = 1, hi = 1e10;
    while(lo < hi){
        int mid = (lo + hi)/2; // find a mid val
        int r = 0;
        for(int i=0; i<n; i++){
            r += ceil((double)groups[i]/mid);
        }
        if(r<= mics)
            hi = mid;
        else
            lo = mid+1;
    }
    return hi;
}


int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> groups(n);
    for(int i=0; i<n; i++){
        cin >> groups[i];
    }

    /*
    int n =5;
    vector<int> groups;
    groups.push_back(100);
    groups.push_back(80);
    groups.push_back(60);
    groups.push_back(40);
    groups.push_back(30);
    int k = 9;
    */
    cout<<solve(groups, k, n)<<endl;
    return 0;
}
/*

Test case 2 :
n = 5
k = 9
[100 80 60 40 30]


Test case 1 :
n = 5 , k =7 ; k is number of groups mics and n is number of groups initially
[10 , 8 , 6 , 3 ,2 ] – > initially number of students in each group .
Output = 6 ;


5 7
10 8 6 3 2





5 9
100 80 60 40 30


*/