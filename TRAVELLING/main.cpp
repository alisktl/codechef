#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    if(M == 0) {
        cout << N-1 << "\n";
        return;
    }

    map<pair<int, int>, int> l;
    vector<vector<int>> adj(N+1);

    int u, v;
    for(int i = 0; i < M; i++) {
        cin >> u >> v;

        l[{u, v}] = 0;
        l[{v, u}] = 0;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(N+1, INT_MAX);
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({dist[1], 1});
    
    while(!q.empty()) {
        pair<int, int> top = q.top();
        q.pop();

        int u = top.second;
        int dist_ = top.first;
        int d = dist[u];

        if (d < dist_)
            continue;

        bool found_lower = false, found_higher = false;

        for(auto v: adj[u]) {
            if(v == u-1)
                found_lower = true;

            if(v == u+1)
                found_higher = true;

            int len = l[{u, v}];

            if(dist[v] > d + len) {
                int dist_new = d + len;

                q.push({dist_new, v});

                dist[v] = dist_new;
            }
        }

        if(u > 1 && !found_lower) {
            int len = 1;
            int v = u-1;

            if(dist[v] > d + len) {
                int dist_new = d + len;

                q.push({dist_new, v});

                dist[v] = dist_new;
            }
        }

        if(u < N && !found_higher) {
            int len = 1;
            int v = u+1;

            if(dist[v] > d + len) {
                int dist_new = d + len;

                q.push({dist_new, v});

                dist[v] = dist_new;
            }
        }
    }

    cout << dist[N] << "\n";
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