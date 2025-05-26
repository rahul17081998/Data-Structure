#include<bits/stdc++.h>
using namespace std;

/*
    stage can be of two types
    stage 1: you can choose to split one of your heroes into xi heroes or skip this stage
    stage 2:  you have to face the obstacle with an HP = xi you can only cross the obstacle if you have strictly
        more  heroes than HP of the obstacle. You can move on to the next stage if you cross the obstacle


    input:  N = 2
            X = [3, 2]
            type = [1, 2]

    output: 1
*/

class Solution{
public:
    void solve(){
        int N;
        cin>>N;
        vector<int> x(N), type(N), pref(N);
        for(int i = 0; i<N; i++) cin>>x[i];
        for(int i = 0; i<N; i++) cin>>type[i];

        //binarysearch approach - @mellophi
        // pref[0] = type[0] == 2 ? 1 : x[0];
        // for (int i = 1; i < N; i++)
        //     pref[i] = type[i] == 1 ? pref[i - 1] + x[i] - 1 : pref[i - 1];

        // for (int i = 0; i < N; i++) {
        //     if (type[i] == 2) {
        //         auto it = upper_bound(pref.begin(), pref.end(), x[i]);
        //         if (it == pref.end() || it - pref.begin() > i) {
        //             cout << -1 << "\n";
        //             return;
        //         }
        //         cout << it - pref.begin() + 1 << "\n";
        //     }
        // }

        int sum = 1, ans = 0;
        priority_queue<int> q;
        
        for(int i = 0; i<N; i++){
            if(type[i] == 1){
                q.push(x[i]);
            }else if(type[i] == 2){
                while(!q.empty() && sum<=x[i]){
                    sum += q.top()-1;
                    q.pop();
                    ans++;
                }

                if(sum<=x[i] && q.empty()){
                    cout<<-1<<endl;
                    return;
                }
            }
        }
        cout<<ans<<endl;
    }
};

int main(){
    ios::sync_with_stdio(false);
    int t = 1;
    while(t--){
        Solution obj;
        obj.solve();
    }
}
