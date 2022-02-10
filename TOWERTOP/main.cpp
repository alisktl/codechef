#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    long long X, M;

    cin >> X >> M;

    int steps_to_build = 0;
    bool build = false;

    for(int step = 1; step <= M; step++) {
        if(X > pow(2, step-1)) {
            ++steps_to_build;
        } else {
            build = true;
            break;
        }
    }

    if(!build) {
        cout << "0\n";
    } else {
        cout << (M-steps_to_build) << "\n";
    }
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