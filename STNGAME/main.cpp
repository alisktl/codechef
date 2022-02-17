#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;

    string str_alice, str_bob;
    cin >> str_alice >> str_bob;

    vector<char> arr_A(N);
    vector<char> arr_B(N);

    for(int i = 0; i < N; i++) {
        arr_A[i] = str_alice[i];
        arr_B[i] = str_bob[i];
    }

    sort(arr_A.begin(), arr_A.end());
    sort(arr_B.begin(), arr_B.end(), greater<char>());

    vector<char> ans(2*N);

    int l = 0, r = 2*N-1;
    int start_A = 0, end_A = N-1;
    int start_B = 0, end_B = N-1;

    for(int i = 0; i < 2*N; i++) {
        if(i%2 == 0) { // Alice's step
            if(arr_A[start_A] >= arr_B[start_B]) {
                ans[r--] = arr_A[end_A--];
            } else {
                ans[l++] = arr_A[start_A++];
            }
        }
        else { // Bob's step
            if(arr_A[start_A] >= arr_B[start_B]) {
                ans[r--] = arr_B[end_B--];
            } else {
                ans[l++] = arr_B[start_B++];
            }
        }
    }

    for(int i = 0; i < 2*N; i++) {
        cout << ans[i];
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