#include <iostream>
#include <map>

using namespace std;

void solve() {
    int N;
    cin >> N;

    map<int, bool> X;
    map<int, bool> Y;

    int count = 0;

    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        if(X[x] == false) {
            X[x] = true;
            count++;
        }

        if(Y[y] == false) {
            Y[y] = true;
            count++;
        }
    }

    cout << count << "\n";
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