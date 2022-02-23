#include <iostream>

using namespace std;

void solve() {
    long long N, M;
    cin >> N >> M;

    long long sum = 0;
    long long A;
    for(int i = 0; i < N; i++) {
        cin >> A;
        sum += A;
    }

    long long active_edges_count = M;
    long long missed_edges_count = N*(N-1)/2 - M;

    int waste;
    for(int m = 0; m < M; m++) {
        cin >> waste >> waste;
    }

    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++) {
        char sign;
        cin >> sign;

        if(sign == '?') {
            cout << (sum + active_edges_count - missed_edges_count) << "\n";
        } else if(sign == '+') {
            cin >> waste >> waste;
            active_edges_count++;
            missed_edges_count--;
        } else {
            cin >> waste >> waste;
            active_edges_count--;
            missed_edges_count++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}