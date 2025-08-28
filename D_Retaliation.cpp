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
template <typename T = int> using Pair = pair<T, T>;
vector<string> RET = {"NO", "YES"};

template <typename T = int>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x : v) in >> x;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v) {
    for (const T &x : v) out << x << ' ';
    return out;
}

bool check(const deque<int> &dl, int x) {
    if (dl.size() >= 4) {
    if (dl[0] > dl[1] && dl[1] > dl[2] && dl[2] > dl[3] && dl[3] > x) return false;
    if (dl[0] < dl[1] && dl[1] < dl[2] && dl[2] < dl[3] && dl[3] < x) return false;}
    
    return true;
}

void Solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    cin >> p;

    int l = 0, r = n - 1;
    deque<int> dq;
    string ans;
    ans.reserve(n);
    int i=0;
    while(i<n) {
        i++; 
        char pick = '?';
        bool okR = check(dq, p[r]);
        bool okL = check(dq, p[l]);
        

        if (okL && okR) {
            deque<int> Dl = dq;
            if (Dl.size() == 4) Dl.pop_front();
            Dl.push_back(p[l]);
            bool f = false;
            if (l + 1 >r ) 
            f= true;
            else 
            if (check(Dl, p[l + 1]) || check(Dl, p[r])) f = true;
            
            

            deque<int> Dr = dq;
            if (Dr.size() == 4) Dr.pop_front();
            Dr.push_back(p[r]);
            bool ff = false;
            if (l > r - 1) 
            ff = true;
            else 
            if (check(Dr, p[l]) || check(Dr, p[r - 1])) ff = true;
                
            

            if (f && !ff) pick = 'L';
            else if (ff && !f) pick = 'R';
            else pick = 'L';  
        } 
        else if (okR && !okL) {
            pick = 'R';
        }
        else if (okL && !okR) {
            pick = 'L';
        } 
        else {
            pick = 'L';  
        }

        if (pick != 'L') {
            ans.push_back('R');
            if (dq.size() == 4) dq.pop_front();
            dq.push_back(p[r]);
            r--;
            
            
        } else {
            ans.push_back('L');
            if (dq.size() == 4) dq.pop_front();
            
            dq.push_back(p[l]);
            l++;
        }
    }
    cout << ans <<endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        Solve();
    }
    return 0;
}
