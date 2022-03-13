#include <iostream>

using namespace std;

void solve() {
    int D;
    cin >> D;

    if(D%2 == 1) {
        cout << -1 << "\n";
        return;
    }

    cout << 0 << " " << D/2 << "\n";
    cout << D/2 << " " << 0 << "\n";
    cout << D/2 << " " << D << "\n";
    cout << D << " " << D/2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}