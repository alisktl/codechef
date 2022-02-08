#include <iostream>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    cout << N * M << "\n";
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