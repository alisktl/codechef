#include <iostream>
#include <string>

using namespace std;

void solve() {
    int N;
    string S;

    cin >> N;
    cin >> S;

    int *count = new int[2];
    count[0] = 0;
    count[1] = 0;

    for(int i = 0; i < N; i++) {
        count[((int)S[i] - 48)]++;
    }

    if(count[0] == count[1]) {
        cout << "YES\n";
        return;
    }

    if(N%2 == 0 && count[0]%2 == count[1]%2 && count[0]%2 == 0) {
        cout << "YES\n";
        return;
    }

    if(N%2 == 1) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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