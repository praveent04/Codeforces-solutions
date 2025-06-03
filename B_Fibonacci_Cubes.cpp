#include <bits/stdc++.h>

using namespace std;

#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
constexpr ll LINF = 1LL << 62;
#define PI acos(-1)
template < typename T = int > using Pair = pair < T, T >;


vector<vector<vector<vector<int>>>> blt;
const int maxn = 10;
const int maxd = 150;
int arr[10];

bool pack(const vector<int>& bl, int bw, int bh) {
    int usedH = 0;
    int rowW = 0;
    int rowH = 0;
    int i=0;
    while(i<bl.size()) {
        if (bl[i]> bw || bl[i] > bh) {
            return false;
        }
        if (rowW + bl[i] > bw) {
           // usedH += rowH;
            if (usedH +rowH + bl[i] > bh) {
                return false;
            }
            usedH = usedH + rowH;
            rowW = bl[i];
            rowH = bl[i];
            
        } else {
            rowW += bl[i];
            rowH = max(rowH, bl[i]);
        }
        i++;
    }
    usedH += rowH;
    if(usedH > bh)
    return false;
    else
    return
    true;
}

void pre() {
    blt.assign(maxn + 1, vector<vector<vector<int>>>(maxd + 1));
    for (int n = 2; n <= maxn; ++n) {
        arr[0] = 1;
        arr[1] = 2;
        for (int i = 2; i < n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        int full_mask = (1 << n) - 1;
        int fmax = arr[n - 1];

        vector<int> sum_mask(1 << n);
        for (int mask = 1; mask <= full_mask; ++mask) {
            int lsb = mask & -mask;
            int idx = __builtin_ctz(lsb);
            sum_mask[mask] = sum_mask[mask ^ lsb] + arr[idx];
        }

        vector<int> dp(1 << n);
        for (int H = 1; H <= maxd; ++H) {
            if (H < fmax) continue;
            dp[0] = 0;
            for (int mask = 1; mask <= full_mask; ++mask) {
                if (sum_mask[mask] <= H) {
                    dp[mask] = 1;
                } else {
                    int best = n + 1;
                    for (int s = (mask - 1) & mask; s; s = (s - 1) & mask) {
                        if (sum_mask[s] <= H) {
                            best = min(best, dp[mask ^ s] + 1);
                        }
                    }
                    dp[mask] = best;
                }
            }

            int S = dp[full_mask];
            if (S > n) continue;

            vector<vector<int>> valid_subsets(1 << n);
            for (int mask = 1; mask <= full_mask; ++mask) {
                int lsb = mask & -mask;
                int i = __builtin_ctz(lsb);
                int rem = mask ^ (1 << i);
                for (int s = rem;; s = (s - 1) & rem) {
                    int s_full = s | (1 << i);
                    if (sum_mask[s_full] <= H) {
                        valid_subsets[mask].push_back(s_full);
                    }
                    if (!s) break;
                }
            }

            set<vector<int>> bottom_sets;
            vector<int> bottoms;
            function<void(int, int)> dfs = [&](int rem_mask, int bins_left) {
                if (bins_left == 1) {
                    if (sum_mask[rem_mask] <= H) {
                        int idx = 31 - __builtin_clz(rem_mask);
                        bottoms.push_back(arr[idx]);
                        vector<int> bl = bottoms;
                        sort(bl.begin(), bl.end(), greater<int>());
                        bottom_sets.insert(bl);
                        bottoms.pop_back();
                    }
                    return;
                }
                for (int s : valid_subsets[rem_mask]) {
                    int idx = 31 - __builtin_clz(s);
                    bottoms.push_back(arr[idx]);
                    dfs(rem_mask ^ s, bins_left - 1);
                    bottoms.pop_back();
                }
            };
            dfs(full_mask, S);
            auto &out_list = blt[n][H];
            out_list.assign(bottom_sets.begin(), bottom_sets.end());
        }
    }
}

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> boxes(m);
    for (int i = 0; i < m; i++) {
        cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2];
    }
    vector<int> fib_n(n);
    fib_n[0] = 1;
    if (n >= 2) fib_n[1] = 2;
    for (int i = 2; i < n; i++) {
        fib_n[i] = fib_n[i - 1] + fib_n[i - 2];
    }
    int fmax = fib_n[n - 1];

    string ans;
    ans.reserve(m);
    for (int i = 0; i < m; i++) {
        bool ok = false;
        int a[3] = { boxes[i][0], boxes[i][1], boxes[i][2] };
        for (int j = 0; j < 3 && !ok; j++) {
            int H = a[j];
            if (H < fmax) {continue;}
            int b1 = a[(j + 1) % 3], b2 = a[(j + 2) % 3];
            auto &bottom_lists = blt[n][H];
            if (bottom_lists.empty()) {continue;}
            for (auto &bl : bottom_lists) {
                if (pack(bl, b1, b2) || pack(bl, b2, b1)) {
                    ok = true;
                    break;
                }
            }
        }
        if(ok){
            ans.push_back('1');
        }
        else{
            ans.push_back('0');
        }
    }
    cout << ans;
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();

    int test_cases;
    cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        Solve();
    }
    return 0;
}
