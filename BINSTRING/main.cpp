#include <iostream>
#include <string>

using namespace std;

void solve() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    int ans = 1;

    for(int i = 1; i < N; i++) {
        if(S[i-1] != S[i])
            ans++;
    }

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