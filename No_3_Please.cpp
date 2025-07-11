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
vector < string > RET = {"NO", "YES"};

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}
bool isGood(const vector<int>& A) {
    int sum = 0;
    for (int x : A) {
        sum += x;
        if (sum % 3 == 0) return false;
    }
    return true;
}

void Solve() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int &x : A) cin >> x;

        // Already good?
        if (isGood(A)) {
            cout << "Yes\n";
            continue;
        }

        // Try reversing prefix: maintain a reversed prefix and test once
        int prefixSum = 0;
        vector<int> revPrefix;
        bool found = false;
        for (int i = 0; i < N; ++i) {
            revPrefix.insert(revPrefix.begin(), A[i]); // simulate reverse build
            int sum = 0;
            bool good = true;
            // compute prefix sum of simulated new array
            for (int j = 0; j <= i; ++j) {
                sum += revPrefix[j];
                if (sum % 3 == 0) {
                    good = false;
                    break;
                }
            }
            if (!good) continue;
            for (int j = i + 1; j < N; ++j) {
                sum += A[j];
                if (sum % 3 == 0) {
                    good = false;
                    break;
                }
            }
            if (good) {
                found = true;
                break;
            }
        }

        cout << (found ? "Yes\n" : "No\n");
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
     cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}