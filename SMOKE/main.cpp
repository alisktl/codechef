#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

void solve() {
    int N, X, Y;
    cin >> N >> X >> Y;

    float bus_cap = 100, car_cap = 4;

    int min_polution = INT_MAX;

    for(int a = 0; a <= N; a++) {
        int polution = ceil(a / car_cap) * Y + ceil((N-a) / bus_cap) * X;

        if(polution < min_polution) {
            min_polution = polution;
        }
    }

    cout << min_polution << "\n";
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