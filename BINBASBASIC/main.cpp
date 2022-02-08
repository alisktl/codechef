#include <iostream>
#include <string>

using namespace std;

void solve() {
    int N, K;
    string S;

    cin >> N >> K;
    cin >> S;

    int l, r;

    l = N/2-1;
    r = (N+1)/2;

    int count_flip = 0;
    int i = l;
    while(i >= 0) {
        if(S[l] != S[r])
            ++count_flip;

        --l;
        ++r;
        --i;
    }

    if(count_flip == K) {
        cout << "YES\n";
        return;
    }

    if(K > count_flip && N%2 == 1) {
        cout << "YES\n";
        return;
    }

    if(K > count_flip && (K-count_flip)%2 == 0) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";    
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