#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> line(n + 1);
    for (int i = 0; i < c; i++) {
        int start, end;
        cin >> start >> end;
        line[start] += 1;
        line[end + 1] -= 1;
    }
    for (int i = 1; i <= n; i++) {
        line[i] += line[i - 1];
    }

    int ans = 0, current = 0;
    for (int i = 0; i < n - 1; i++) {
        if (line[i] != 0) {
            ans = max(ans, current);
            current = 0;
        } else {
            current++;
        }
    }

    cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}


