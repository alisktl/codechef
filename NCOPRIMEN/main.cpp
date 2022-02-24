#include <iostream>

using namespace std;

void solve() {
    int N;
    cin >> N;

    int *A = new int[N];

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        if(i%3 == 0) {
            continue;
        }
        else if(i%3 == 1) {
            A[i] = A[i-1]*2;
        } else {
            if(i+1 < N)
                A[i] = A[i+1]*2;
            else
                A[i] = A[i-1];
        }
    }

    for(int i = 0; i < N; i++) {
        cout << A[i] << " "; 
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