#include <iostream>

using namespace std;

void solve() {
    int X, A, B, C;
    cin >> X >> A >> B >> C;

    int min = A;
    int median = B;

    if(B < min)
        min = B;

    if(C < min)
        min = C;

    if(min == A) {
        if(B <= C)
            median = B;
        else
            median = C;
    } else if(min == B) {
        if(A <= C)
            median = A;
        else
            median = C;
    } else if(min == C) {
        if(A <= B)
            median = A;
        else
            median = B;
    }

    cout << (X - 1) * min + median << "\n";
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