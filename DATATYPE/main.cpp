#include <iostream>

using namespace std;

void solve() {
    int N, X;
    cin >> N >> X;

    cout << X%(N+1) << "\n";
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