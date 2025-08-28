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
constexpr int INF = 1 << 30 ;
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
 
static const int MOD = 998244353;
static const int LIM = 200000;

static int FAC[LIM+1], IFAC[LIM+1];

static inline int addm(int a, int b){ int s=a+b; if(s>=MOD) s-=MOD; return s; }
static inline int mulm(long long a, long long b){ return int((a*b)%MOD); }

static inline int mex(long long a, long long e){
    long long r = 1;
    while(e !=0){
        if(e&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        e >>= 1;
    }
    return int(r);
}

static inline void pre(){
    static bool done=false;
    if(done) return;
    done=true;

    FAC[0]=1;
    for(int i=1;i<=LIM;i++) FAC[i]=mulm(FAC[i-1], i);
    IFAC[LIM] = mex(FAC[LIM], MOD-2);
    for(int i=LIM;i>=1;i--) IFAC[i-1] = mulm(IFAC[i], i);
}

static inline int nCk(int n, int k){
    if(n<0 || k<0 || k>n) return 0;
    return mulm(mulm(FAC[n], IFAC[k]), IFAC[n-k]);
}
 
static inline int so(int N){
    
    const int a = N/3;
    const int b = (N+2)/3;
    const int c = (N+1)/3;

    if(b + c == 0) return 0;
 
    auto add_block = [&](int r)->int{
        if(r < 1) return 0;
        int rem = a - (r - 1);
        if(rem < 0 || rem > 2) return 0;

        const int edge = nCk(2, rem);
        const int lo = max(0, r - c);
        const int hi = min(r, b);

        long long acc = 0;
 
        auto waysB = [&](int x)->int{
            if(x==0) return (b==0)?1:0;
            return nCk(b-1, x-1);
        };
        auto waysC = [&](int y)->int{
            if(y==0) return (c==0)?1:0;
            return nCk(c-1, y-1);
        };

        for(int x=lo; x<=hi; ++x){
            int y = r - x;
            int comb = nCk(r, x);
            int wb = waysB(x);
            int wc = waysC(y);
            acc += 1LL * comb * wb % MOD * wc % MOD;
            if(acc >= (1LL<<62)) acc %= MOD;  
        }
        acc %= MOD;

        return mulm(int(acc), edge);
    };

    long long sum = 0;
    sum = addm(sum, add_block(a-1));
    sum = addm(sum, add_block(a));
    sum = addm(sum, add_block(a+1));

    // final multiplication part
    long long ans = sum;
    ans = ans * FAC[a] % MOD;
    ans = ans * FAC[b] % MOD;
    ans = ans * FAC[c] % MOD;
    return int(ans);
}

void Solve(){
    
        int N, s;
        cin >> N >> s;     
        cout << so(N) << '\n';
     
    
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    pre();
    int test_cases = 1;
    cin>>test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
