#include <iostream>

using namespace std;

void solve() {
    int N;
    cin >> N;

    long long *A = new long long[N+1];

    int i_start = N+2;

    for(int i = 1; i <= N; i++) {
        cin >> A[i];

        if(i_start == N+2 && A[i] == i) {
            i_start = i;
        }
    }

    int count = 0;
    int j = i_start;

    for(int i = i_start; i <= N; i++) {
        if(A[i] == j) {
            j++;
            count++;
        }

        j++;
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