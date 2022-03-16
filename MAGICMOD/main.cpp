#include <iostream>
#include <vector>

using namespace std;

#define ll long long

bool isCorrect(vector<ll> A, ll x, ll N) {
    vector<int> count(N+1, 0);

    for(int i = 0; i < N; i++) {
        A[i] %= x;

        if(A[i] > N) {
            return false;
        } else {
            if(A[i] == 0) {
                return false;
            }

            count[A[i]]++;

            if(count[A[i]] > 1) {
                return false;
            }
        }
    }

    return true;
}

void solve() {
    ll N;
    cin >> N;

    ll sum = 0l;
    ll sum_q = 0l;
    ll sum_r = N * (N + 1) / 2;

    vector<ll> A(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    sum_q = sum - sum_r;

    if(sum_q < 0) {
        cout << "NO" << "\n";
        return;
    }

    if(sum_q == 0) {
        if(isCorrect(A, N+1, N)) {
            cout << "YES " << (N + 1) << "\n";
        } else {
            cout << "NO" << "\n";
        }

        return;
    }

    for(ll x = 1; x*x <= sum_q; x++) {
        if(sum_q % x == 0) {
            if(x <= 2e7 && isCorrect(A, x, N)) {
                cout << "YES " << x << "\n";
                return;
            }

            if(sum_q/x <= 2e7 && isCorrect(A, sum_q/x, N)) {
                cout << "YES " << (sum_q/x) << "\n";
                return;
            }
        }
    }

    cout << "NO" << "\n";
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