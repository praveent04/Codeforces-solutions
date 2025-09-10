#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        string A;
        cin >> N >> A;

        vector<int> pref(N+1, 0);
        for (int i = 0; i < N; i++) {
            pref[i+1] = pref[i] + (A[i]-'0');
        }

        long long ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += pref[i];
        }
        cout << ans << "\n";
    }
    return 0;
}
