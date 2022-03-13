#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    vector<long long> A(N, 0);

    long long sum_1 = 0l, sum_2 = 0l;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum_2 += A[i];
    }

    sum_1 = A[0];
    sum_2 -= A[0];

    long long max = std::max(sum_1, sum_2);

    for(int i = 1; i < N; i++) {
        sum_1 += A[i];
        sum_2 -= A[i];

        long long max_ = std::max(sum_1, sum_2);

        if(max_ < max) {
            max = max_;
        } else {
            break;
        }
    }

    cout << max << "\n";
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