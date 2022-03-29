#include <iostream>

using namespace std;

void solve() {
    int N;
    cin >> N;

    if(N == 2) {
        cout << -1 << "\n";
        return;
    }

    if(N % 2 != 0) {
        for(int i = 1; i <= N; i++)
            cout << i << " ";
        cout << "\n";

        return;
    }

    cout << 2 << " " << 3 << " " << 1 << " ";

    for(int i = 4; i <= N; i++)
        cout << i << " ";

    cout << "\n";
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