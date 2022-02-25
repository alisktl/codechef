#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define end "\n"

const ll MOD = 1e9 + 7;

vector<vector<ll>> dp;

ll power(ll x, ll y) {
    ll res = 1;
    x = x % MOD;

    while(y > 0) {
        if(y & 1)
            res = (res * x) % MOD;

        y = y >> 1;
        x = (x*x) % MOD;
    }

    return res;
}

void preprocess(int N, int M) {
    dp.assign(N+1, vector<ll>(2, 0LL));
    dp[1][1] = M;

    for(int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i-1][1] * (M-1)) % MOD + (dp[i-1][0] * (M-2)) % MOD;
        dp[i][0] %= MOD;
        dp[i][1] = dp[i-1][0];
    }
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector<ll> A(N);

    preprocess(N, M);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    ll ans = 1LL;
    vector<int> visited(N, 0);

    for(int i = 0; i < N; i++) {
        if(visited[i] == 0) {
            int curr = i, count = 0;

            while(visited[curr] == 0) {
                count++;
                visited[curr] = 1;
                curr = A[curr];
            }

            if(visited[curr] == 2) {
                ans = (ans * power(M-1, count)) % MOD;
            } else {
                int cycle_len = 1;
                for(int j = A[curr]; j != curr; j = A[j]) {
                    cycle_len++;
                }
                ans = (ans * dp[cycle_len][0]) % MOD;
                ans = (ans * power(M-1, count - cycle_len)) % MOD;
            }

            curr = i;

            while(visited[curr] != 2) {
                visited[curr] = 2;
                curr = A[curr];
            }
        }
    }

    ans %= MOD;
    cout << ans << end;
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