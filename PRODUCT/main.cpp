#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(a > b)
        swap(a, b);

    if(a == 0)
        return b;

    // a is less than b
    return gcd(b%a, a);
}

void solve() {
    int B, C;
    cin >> B >> C;

    int d = gcd(B, C);

    int A = C / d;

    cout << A << "\n";
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