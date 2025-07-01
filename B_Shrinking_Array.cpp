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


bool sp(vector<int>& arr) {
    if (arr.size() < 2) return false;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (abs(arr[i] - arr[i + 1]) <= 1) {
            return true;
        }
    }
    return false;
}

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    if (sp(a)) {
        cout << 0 << endl;
        return;
    }
    
    if (n == 2) {
        cout << -1 << endl;
        return;
    }
    
    bool f = false;
    
    for (int i = 0; i < n-1 && !f; i++) {
        vector<int> temp;
        
        for (int j = 0; j < i; j++) {
            temp.push_back(a[j]);
        }
        
       
        set<int> st;
        st.insert(min(a[i], a[i + 1]));
        st.insert(max(a[i], a[i + 1]));
        
        if (i > 0) {
            int left = a[i-1];
            st.insert(left);
            st.insert(left + 1);
            st.insert(left - 1);
        }
        if (i + 2 < n) {
            int right = a[i+2];
            st.insert(right);
            st.insert(right + 1);
            st.insert(right - 1);
        }
        
        for (int x : st) {
            if (x >= min(a[i], a[i + 1]) && x <= max(a[i], a[i + 1])) {
                vector<int> arr = temp;
                arr.push_back(x);
                
                for (int j = i + 2; j < n; j++) {
                    arr.push_back(a[j]);
                }
                bool b = sp(arr);
                if (b) {
                    f = true;
                    break;
                }
            }
        }
    }
    if(f)
    cout<<1;
    else
    cout<<-1;
    cout << endl;
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