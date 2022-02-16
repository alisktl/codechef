#include <iostream>
#include <climits>

using namespace std;

const int B_MAX = 1e5 + 10;

void solve() {
    int N;
    cin >> N;

    int sum = 0;
    int B;

    for(int i = 0; i < 2*N; i++) {
        cin >> B;
        sum += B;

        if(sum > INT_MAX - B_MAX || sum < INT_MIN + B_MAX) {
            sum %= 2;
        }
    }

    if(sum%2 == 0) {
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