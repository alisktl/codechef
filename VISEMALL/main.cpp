#include <iostream>
#include <string>
#include <set>

using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    set<int> set_{N};

    for(int i = 1; i < N; i++) {
        if(S[i] != S[i-1])
            set_.insert(i);
    }

    while(Q--) {
        int type, L, R;
        cin >> type >> L >> R;
        L--; R--;

        if(type == 2) {
            int X;
            cin >> X;
            X--;

            int count = 0;
            auto it = set_.upper_bound(L);
            while(*it <= R && count < 2) {
                it = next(it);
                count++;
            }

            if(count == 0 && X == L)
                cout << "YES\n";
            else if(count == 1 && X != L && X == *prev(it))
                cout << "YES\n";
            else if(count > 1)
                cout << "YES\n";
            else
                cout << "NO\n";
            
        } else {
            for(int i: {L, R+1}) {
                if(i > 0 && i < N) {
                    if(set_.count(i))
                        set_.erase(i);
                    else
                        set_.insert(i);
                }
            }
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