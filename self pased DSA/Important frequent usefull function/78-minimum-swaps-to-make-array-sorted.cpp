#include<bits/stdc++.h>
using namespace std;
Approach:
This can be easily done by visualizing the problem as a graph. We will have n nodes and an edge directed from node i to node j if the element at i’th index must be present at j’th index in the sorted array. 


// Minimum swap required to make array sorted
// time = O(N*logN), space = O(N)

int miniSwap(vector<int> arr)
{
    int n = arr.size();
    vector<pair<int,int> > arrPos;
    for(int i=0; i<n; i++){
        arrPos.push_back(make_pair(arr[i], i));
    }
    sort(arrPos.begin(), arrPos.end());
    int ans=0;
    vector<bool> vis(n, false);

    for(int i=0; i<n; i++){
        if(vis[i] || arrPos[i].second==i)
            continue;
        
        int cycle_size=0;
        int j=i;
        while(!vis[j]){
            vis[j]=1;
            j = arrPos[j].second;
            cycle_size++;
        }

        if(cycle_size > 0){
            ans += cycle_size-1;
        }
    }
    return ans;
}

int main(){
    // 1, 5, 4, 3, 2
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    cout<<miniSwap(arr)<<endl;
    return 0;
}