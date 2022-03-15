#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<long long> A(N, 0);
    vector<long long> A_sorted(N, 0);

    string polarity;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A_sorted[i] = A[i];
    }

    cin >> polarity;

    sort(A_sorted.begin(), A_sorted.end());

    int l = -1, r = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] != A_sorted[i] && l == -1) {
            l = i;
            break;
        }
    }

    for(int i = N-1; i >= 0; i--) {
        if(A[i] != A_sorted[i] && r == -1) {
            r = i;
            break;
        }
    }

    if(l == -1 && r == -1) {
        cout << 0 << "\n";
        return;
    }

    if(polarity[l] != polarity[r]) {
        cout << 1 << "\n";
        return;
    }

    for(int i = 0; i < l; i++) {
        if(polarity[i] != polarity[r]) {
            cout << 1 << "\n";
            return;
        }
    }

    for(int i = r+1; i < N; i++) {
        if(polarity[i] != polarity[l]) {
            cout << 1 << "\n";
            return;
        }
    }

    int count_S_1 = 0, count_N_1 = 0;
    for(int i = 0; i < l; i++) {
        if(count_S_1 >= 1 && count_N_1 >= 1)
            break;

        if(polarity[i] == 'N') {
            count_N_1++;
        } else if(polarity[i] == 'S') {
            count_S_1++;
        }
    }

    if(count_S_1 >= 1 && count_N_1 >= 1) {
        cout << 2 << "\n";
        return;
    }

    int count_S_2 = 0, count_N_2 = 0;
    for(int i = r+1; i < N; i++) {
        if(count_S_2 >= 1 && count_N_2 >= 1)
            break;

        if(polarity[i] == 'N') {
            count_N_2++;
        } else if(polarity[i] == 'S') {
            count_S_2++;
        }
    }

    if(count_S_2 >= 1 && count_N_2 >= 1) {
        cout << 2 << "\n";
        return;
    }

    int count_S_3 = 0, count_N_3 = 0;
    for(int i = l; i <= r; i++) {
        if(count_S_3 >= 1 && count_N_3 >= 1)
            break;

        if(polarity[i] == 'N') {
            count_N_3++;
        } else if(polarity[i] == 'S') {
            count_S_3++;
        }
    }

    if(count_S_3 >= 1 && count_N_3 >= 1) {
        cout << 2 << "\n";
        return;
    }

    cout << -1 << "\n";
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