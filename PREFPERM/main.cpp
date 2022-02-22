#include <iostream>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    int *A = new int[K];

    for(int i = 0; i < K; i++) {
        cin >> A[i];
    }

    int last_A = 1;
    for(int i = 0; i < K; i++) {
        for(int j = A[i]; j >= last_A; j--) {
            cout << j << " ";
        }

        last_A = A[i]+1;
    }

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