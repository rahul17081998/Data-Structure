#include <bits/stdc++.h>
using namespace std;

// Defining our own structure
typedef struct node {
    int val;
    int l;
    int r;
    int idx;
} Node;

// Writing our own comparator function
bool compare(Node a, Node b){

    // If both values are equal, query will come first
    if (a.val == b.val){
        return a.l > b.l;
    }

    // Otherwise, sort in descending order
    return a.val > b.val;
}

// Function to update the BIT
void update(int * BIT, int n, int idx){
    while (idx <= n){
        BIT[idx]++;
        idx += idx & (-idx);
    }
}

/*
This function will return the count of
elements present till index 'idx'.
*/
int query(int * BIT, int idx){
    int ans = 0;
    while (idx){
        ans += BIT[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

// Driver code
int main(){
    int n = 7;
    int arr[] = { 5, 3, 6, 2, 4, 7, 6 };
    int q = 3;
    vector<int> Q1;
    vector<int> Q2;
    vector<int> Q3;
   
    Q1.push_back(1);
    Q1.push_back(4);
    Q1.push_back(4);

    Q2.push_back(3);
    Q2.push_back(7);
    Q2.push_back(5);

    Q3.push_back(3);
    Q3.push_back(7);
    Q3.push_back(6);

    // vector<int> queries[n] = { {1, 4, 4}, {3, 7, 5}, {3, 7, 6} };
    vector<vector<int> > queries;
    queries.push_back(Q1);
    queries.push_back(Q2);
    queries.push_back(Q3);
    // Creating structure for combining arr and queries
    Node a[n+q+1];

    // Iterating over array elements
    for(int i=1; i<=n; i++){
        a[i].val = arr[i-1];
        a[i].idx = i;
        a[i].l = -1;
        a[i].r = -1;
    }

    // Iterating over query elements
    for (int i=n+1; i<=n+q; i++){
        a[i].val = queries[i-n-1][2];
        a[i].l = queries[i-n-1][0];
        a[i].r = queries[i-n-1][1];
        a[i].idx = i-n;
    }

    // Sorting the structure using our comparator function
    sort(a+1, a+n+q+1, compare);

    // Creating Binary Indexed Tree
    int BIT[n+1];
    memset(BIT, 0, sizeof(BIT));
    int ans[q+1];

    // Iterating over the combined structure
    for (int i = 1; i <= n + q; ++i) {
      
        // Updating BIT if it is an array element
        if (a[i].l == -1){
            update(BIT, n, a[i].idx);
        }
        else{

            // Counting number of elements greater than K
            int curAns = query(BIT, a[i].r) - query(BIT, a[i].l - 1);
            ans[a[i].idx] = curAns;
        }
    }
  
    // Printing the answer array
    for (int i=1; i<=q; i++){
        cout << ans[i] << ' ';
    }
    cout<<endl;

    return 0;
}