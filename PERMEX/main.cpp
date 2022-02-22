#include <iostream>
#include <string>

using namespace std;

void solve() {
    int N;
    cin >> N;

    int *A = new int[N+1];

    string S;
    cin >> S;

    for(int i = 0; i < N+1; i++) {
        A[i] = (int)S[i] - 48;
    }

    if(A[0] == 0 || A[1] == 0 || A[N] == 0) {
        cout << "NO\n";
        return;
    }

    int *P = new int[N];

    for(int i = 0; i < N; i++) {
        P[i] = i;
    }

    for(int i = 0; i < N+1; i++) {
        if(A[i] == 0) {
            swap(P[i-1], P[i]);
        }
    }

    cout << "YES\n";

    for(int i = 0; i < N; i++) {
        cout << P[i] << " ";
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