#include <iostream>

using namespace std;

void solve() {
    long long N, K;
    cin >> N >> K;

    long long L = K - N;

    long long L_start = 0, L_end = 0;
    long long l_start = 0, l_end = 0;
    long long l_prev_end = 0;
    long long M = 1;

    for(long long m = 2; m < L+2; m++) {
        l_start = l_prev_end+1;
        l_end = m*(m+1)/2 - 1;

        if(l_start <= L && L <= l_end) {
            L_start = l_start;
            L_end = l_end;
            M = m;

            break;
        }

        l_prev_end = l_end;
    }

//    cout << "L_start: " << L_start << "\n";
//    cout << "L_end: " << L_end << "\n";
//    cout << "M: " << M << "\n";

    for(long long i = 0; i < M; i++) {
        cout << (i+1) << " ";
    }

    long long final_digit = M - (L - L_start);

    for(long long i = M; i < N; i++) {
        cout << final_digit << " ";
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

