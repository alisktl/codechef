#include <iostream>
#include <vector>
#include <cstring>

#define ll long long

using namespace std;

const int N_MAX = 1000;

int gcd(int a, int b) {
    if(a > b)
        swap(a, b);

    if(a == 0)
        return b;

    return gcd(b%a, a);
}

vector<vector<int>> all_gcd() {
    int N = N_MAX;

    vector<vector<int>> gcd_(N+1, vector<int>(N+1));

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            gcd_[i][j] = gcd(i, j);
        }
    }

    return gcd_;
}

void solve(vector<vector<int>> all_gcd_) {
    int N;
    cin >> N;

    ll f[N + 1][N + 1];
    memset(f, 0, sizeof(f));

    for(int num = 1; num <= N; num++) {
        for(int den = 1; den <= N; den++) {
            int g = all_gcd_[num][den];

            int num_ = num/g;
            int den_ = den/g;

            f[num_ % den_][den_]++;
        }
    }

    ll ans = 0;

    for(int den = 1; den <= N; den++) {
        for(int num = 0; num < den; num++) {
            ans += f[num][den] * f[(den - num) % den][den];
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> all_gcd_ = all_gcd();

    int T; cin >> T;

    while(T --> 0)
        solve(all_gcd_);

    return 0;
}