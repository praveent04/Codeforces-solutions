#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        int n; 
        cin >> n;
        vector<vector<int>> g(n+1);
        vector<int> deg(n+1, 0);
        for (int i = 0; i < n-1; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++; deg[v]++;
        }

        bool path = true;
        for (int i = 1; i <= n; ++i) if (deg[i] > 2) { path = false; break; }
        if (path) {
            cout << -1 << '\n';
            continue;
        }

        int b = -1;
        for (int i = 1; i <= n; ++i) if (deg[i] >= 3) { b = i; break; }

        int c = -1, a = -1;

        for (int v : g[b]) if (deg[v] >= 3) { c = v; break; }
        if (c != -1) {
            for (int v : g[b]) if (v != c && deg[v] == 1) { a = v; break; }
            if (a == -1) {
                for (int v : g[b]) if (v != c) { a = v; break; }
            }
            cout << a << ' ' << b << ' ' << c << '\n';
            continue;
        }

        for (int v : g[b]) if (deg[v] == 1) { c = v; break; }
        if (c == -1) c = g[b][0];

        for (int v : g[b]) if (v != c) { a = v; break; }

        cout << a << ' ' << b << ' ' << c << '\n';
    }
    return 0;
}
bool path = true;
        for (int i = 1; i <= n; ++i) if (deg[i] > 2) { path = false; break; }
        if (path) {
            cout << -1 << '\n';
            continue;
        }

        int b = -1;
        for (int i = 1; i <= n; ++i) if (deg[i] >= 3) { b = i; break; }

        int c = -1, a = -1;

        for (int v : g[b]) if (deg[v] >= 3) { c = v; break; }
        if (c != -1) {
            for (int v : g[b]) if (v != c && deg[v] == 1) { a = v; break; }
            if (a == -1) {
                for (int v : g[b]) if (v != c) { a = v; break; }
            }
            cout << a << ' ' << b << ' ' << c << '\n';
            continue;
        }
    }