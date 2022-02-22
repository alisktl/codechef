#include <iostream>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    int *A = new int[N];

    for(int i = 0; i < N; i++)
        A[i] = i+1;

    if(K == N) {
        for(int i = 0; i < N; i++)
            cout << A[i] << " ";
    } else if(K == N-1) {
        cout << A[N-1] << " ";

        for(int i = 1; i < N-1; i++)
            cout << A[i] << " ";

        cout << A[0] << " ";
    } else {
        for(int i = 0; i < K; i++)
            cout << A[i] << " ";

        for(int i = K+1; i < N; i++)
            cout << A[i] << " ";

        cout << A[K] << " ";
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