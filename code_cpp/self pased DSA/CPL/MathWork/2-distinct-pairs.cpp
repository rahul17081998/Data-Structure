// link gfg: https://www.geeksforgeeks.org/count-distinct-pairs-with-given-sum/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

//write your function here
int cntDisPairs(vector<int> arr, int target)
{
    unordered_set<int> set, seen;
    // int count=0;
    // for(int i=0; i<arr.size(); i++)
    // {
    //     if(st.find(target-arr[i])!=st.end() && seen.find(arr[i])==seen.end()){
    //         seen.insert(arr[i]);
    //         seen.insert(target-arr[i]);
    //         count++;
    //     }
    //     st.insert(arr[i]);
    // }
    // return count;
    int count = 0;
     
    for(int num : arr) {
        if(set.find(target-num) != set.end() && seen.find(num) == seen.end() ) {
            count++;
            seen.insert(num);
            seen.insert(target-num);
        }
        set.insert(num);
    }
    return count;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(45);
    arr.push_back(46);
    arr.push_back(46);
    int target = 47;
    cout << cntDisPairs(arr, target);
    return 0;
}
/*
Input: nums = [1, 1, 2, 45, 46, 46], target = 47
Output: 2
Explanation:
1 + 46 = 47
2 + 45 = 47
*/