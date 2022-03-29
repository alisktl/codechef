#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;

    int cnt = 0;

    for(int day = 1; day <= 30; day++)
        if((day+1)%7 == 0 || day%7 == 0) {
            cnt++;
        }

    int A;
    for(int i = 0; i < N; i++) {
        cin >> A;

        if((A+1)%7 != 0 && A%7 != 0) {
            cnt++;
        }
    }

    cout << cnt << "\n";
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