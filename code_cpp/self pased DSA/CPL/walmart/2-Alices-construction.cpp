/*
Alice's construction
Alice has a warehouse with  boxes and the  box has number . All box numbers are different and range from  to . Alice wants to rearrange the boxes in the following way:

First, she chooses some interval of boxes, starting from the  to the  inclusive, as well as some number .
Then arbitrarily chooses a pair of indices  and  from the interval  such that  and ,  and changes the boxes at positions  and . That is, an arbitrary number of times swaps a pair of adjacent boxes in which the numbers do not exceed .
You are given  triplets . For each of them, Alice asks you to tell how many different sequences of boxes she can get by selecting the following values.
Since these numbers can be very large, you need to subtract the remainder of their division by the prime number .

Sample Input
5 4
1 3 5 2 4
2 5 4
2 3 2
3 5 4
3 5 5

sample output
2
1
2
6
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N = 1e5 + 10;

struct my{
    int cntPref,cntSuff;
    int cntAll;
    int val;
    my(){
     cntPref = 0;
     cntSuff = 0;
     cntAll = 1;
     val = 1;
    }
};

int f[MAX_N];
my t[4 * MAX_N];
int md = 1e9 + 7;
int p[MAX_N],pos[MAX_N];
vector<pair<pair<int,int>,int>> q[MAX_N];
int answer[MAX_N];
int rf[MAX_N];

int BinPow(int a,int b){
    int ans = 1;
    while(b){
        if(b & 1)ans = ans * a % md;
        a = a * a % md;
        b >>= 1;
    }
    return ans;
}

my combine(my a,my b){
    my c = my();
    c.cntAll = a.cntAll + b.cntAll;
    if(b.cntPref > 0 && a.cntSuff > 0){
        if(a.cntAll == a.cntSuff && b.cntAll == b.cntPref){
            c.cntPref = c.cntAll;
            c.cntSuff = c.cntAll;
            c.val = a.val * b.val % md * rf[a.cntSuff]%md * rf[b.cntPref]%md*f[a.cntSuff + b.cntPref] % md;
        }else
        if(a.cntAll == a.cntSuff){
            c.cntPref = a.cntAll + b.cntPref;
            c.cntSuff = b.cntSuff;
            c.val = a.val * b.val % md * rf[a.cntSuff]%md * rf[b.cntPref]%md*f[a.cntSuff + b.cntPref] % md;
        }else
        if(b.cntAll == b.cntPref){
            c.cntPref = a.cntPref;
            c.cntSuff = b.cntAll + a.cntSuff;
            c.val = a.val * b.val % md * rf[a.cntSuff]%md * rf[b.cntPref]%md*f[a.cntSuff + b.cntPref] % md;
        }else{
            c.cntPref = a.cntPref;
            c.cntSuff = b.cntSuff;
            c.val = a.val * b.val % md * rf[a.cntSuff]%md * rf[b.cntPref]%md*f[a.cntSuff + b.cntPref] % md;
        }
    }else{
        c.cntPref = a.cntPref;
        c.cntSuff = b.cntSuff;
        c.val = (a.val * b.val) % md;
    }
    return c;
}

void upd(int v,int tl,int tr,int pos){
    if(tl > pos || tr < pos)return;
    if(tl == tr){
        t[v].cntPref = t[v].cntSuff = t[v].cntAll = t[v].val = 1;
        return;
    }
    int tm = (tl + tr) >> 1,
        L = v << 1,
        R = L | 1;
    upd(L, tl, tm, pos);
    upd(R, tm + 1, tr, pos);
    t[v] = combine(t[L], t[R]);
}

my get(int v,int tl,int tr,int l,int r){
    if(tl >= l && tr <= r){
        return t[v];
    }
    int tm = (tl + tr) >> 1,
        L = v << 1,
        R = L | 1;
    if(r <= tm)return get(L, tl, tm, l, r);
    if(l > tm)return get(R, tm + 1, tr, l, r);
    my a1 = get(L, tl, tm, l, r),
        a2 = get(R, tm + 1, tr, l, r);
    my a3 = combine(a1, a2);
        return combine(a1, a2);
}

 main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    f[0] = 1;
    rf[0] = 1;
    for(int i = 1; i <= n; ++i){
        f[i] = f[i - 1] * i % md;
        rf[i] = BinPow(f[i], md - 2);
    }

    for(int i = 1; i <= 4 * n; ++i)
        t[i] = my();

    for(int i = 1; i <= n; ++i){
        cin >> p[i];
        pos[p[i]] = i;
    }

    for(int i = 1; i <= m; ++i){
        int l, r, x;
        cin >> l >> r >> x;
        q[x].push_back({{l, r},i});
    }

    for(int i = 1; i <= n; ++i){
        upd(1, 1, n, pos[i]);
        for(int j = 0; j < (int)q[i].size(); ++j){
            answer[q[i][j].second] = get(1, 1, n, q[i][j].first.first, q[i][j].first.second).val;
        }
    }

    for(int i = 1; i <= m; ++i)
        cout << answer[i] << '\n';

    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 1e5 + 14, MOD = 1e9 + 7;

int n, q, p[MAX_N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        --l;
        int ans = 1;
        for (int j = l, c = 0; j < r; ++j)
            if (p[j] <= x)
                ans = (ll) ans * ++c % MOD;
            else
                c = 0;
        cout << ans << '\n';
    }
}

*/