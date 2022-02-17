#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;

    int *A = new int[N+1];

    for(int i = 1; i < N+1; i++) {
        cin >> A[i];
    }

    long long ans = 0;

    vector<vector<long long>> dp(N+1, vector<long long>(N+1, 0));

    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            int k = max(i, j) + 1;

            if(i == j || k > N)
                continue;

            if(i == 0)
                dp[k][j] = max(dp[k][j], dp[i][j]);
            else
                dp[k][j] = max(dp[k][j], dp[i][j] + abs(A[k] - A[i]));

            if(j == 0)
                dp[i][k] = max(dp[i][k], dp[i][j]);
            else
                dp[i][k] = max(dp[i][k], dp[i][j] + abs(A[k] - A[j]));

            ans = max(ans, max(dp[k][j], dp[i][k]));
        }
    }

    cout << ans << "\n";
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