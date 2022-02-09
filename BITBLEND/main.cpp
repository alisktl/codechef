#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N; cin >> N;

    vector<long long> A(N);
    vector<int> first_odd_row(N);
    vector<int> first_even_row(N);

    bool bit = true;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        first_odd_row[i] = bit;
        first_even_row[i] = !bit;

        bit = !bit;
    }

    int start_odd = 0;
    int start_even = 0;

    bool any_odd = false;
    int odd_count = 0;
    int odd_first_index = -1, odd_second_index = -1;
    int even_first_index = -1, even_second_index = -1;

    for(int i = 0; i < N; i++){
        if(!any_odd && A[i]%2 == 1)
            any_odd = true;

        if(A[i]%2 == 1) {
            ++odd_count;

            if(i%2 == 0) {
                if(odd_first_index == -1) {
                    odd_first_index = i;
                } else if(odd_second_index == -1) {
                    odd_second_index = i;
                }
            } else if(i%2 == 1) {
                if(even_first_index == -1) {
                    even_first_index = i;
                } else if(even_second_index == -1) {
                    even_second_index = i;
                }
            }
        }

        if(A[i]%2 == first_odd_row[i]) {
            start_odd++;
        }

        if(A[i]%2 == first_even_row[i]) {
            start_even++;
        }
    }

    if(!any_odd) {
        cout << "-1\n";
        return;
    }

    int odd_edit_count = 0, even_edit_count = 0;
    bool odd_break = false, even_break = false;

    for(int i = 0; i < N; i++) {
        if(A[i]%2 != first_odd_row[i]) {
            ++odd_edit_count;
            
            if(odd_first_index == i && (odd_second_index == -1 || odd_second_index == i)) {
                odd_break = true;
                break;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        if(A[i]%2 != first_even_row[i]) {
            ++even_edit_count;
            
            if(even_first_index == i && (even_second_index == -1 || even_second_index == i)) {
                even_break = true;
                break;
            }
        }
    }

    if(!odd_break && odd_edit_count <= even_edit_count) {
        cout << N - start_odd << "\n";

        for(int i = 0; i < N; i++) {
            if(A[i]%2 != first_odd_row[i]) {
                cout << (i+1) << " ";
                
                if(odd_first_index != i) {
                    cout << (odd_first_index+1) << "\n";
                } else if(odd_second_index != -1 && odd_second_index != i) {
                    cout << (odd_second_index+1) << "\n";
                }
            }
        }

        return;
    } else if(!even_break) {
        cout << N - start_even << "\n";

        for(int i = 0; i < N; i++) {
            if(A[i]%2 != first_even_row[i]) {
                cout << (i+1) << " ";
                
                if(even_first_index != i) {
                    cout << (even_first_index+1) << "\n";
                } else if(even_second_index != -1 && even_second_index != i) {
                    cout << (even_second_index+1) << "\n";
                }
            }
        }

        return;
    }

    cout << "-1\n";
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