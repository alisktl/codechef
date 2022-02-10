#include <iostream>
#include <vector>

using namespace std;

int MAX_N = 1e5 + 1;

void solve() {
    int N;
    cin >> N;

    vector<int> A(MAX_N, 0);

    for(int i = 0; i < 2*N; i++) {
        int a;
        cin >> a;

        ++A[a];
    }

    if(A[0] == 0) {
        cout << "YES\n";
        return;
    }

    if(A[0] == 1) {
        cout << "NO\n";
        return;
    }

    int min = -1;

    for(int i = 1; i < MAX_N; i++) {
        if(A[i] == 1) {
            min = i;
            break;
        }
    }

    if(min == -1) {
        cout << "YES\n";
        return;
    }

    for(int i = 0; i < min; i++) {
        if(A[i] == 0) {
            cout << "YES\n";
            return;
        }
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