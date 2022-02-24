#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string S, S_rev;
    cin >> S;

    S_rev = S;

    reverse(S_rev.begin(), S_rev.end());

    int cnt = 0;
    int n = S.size();

    for(int i = 0; i < n; i++) {
        if(S[i] == S_rev[cnt])
            cnt++;
    }

    int ans = n - cnt;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;

    while(T --> 0)
        solve();

    return 0;
}