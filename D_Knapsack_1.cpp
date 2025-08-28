#include <bits/stdc++.h>
using namespace std;

long long n, w;
long long arr[101][2];
long long dp[101][100001];

long long rec(long long ind, long long wei){
    // Base case: no more items
    if(ind == n) return 0;
    
    // Memoization check
    if(dp[ind][wei] != -1) return dp[ind][wei];
    
    // Option 1: Don't take current item
    long long ans = rec(ind + 1, wei);
    
    // Option 2: Take current item (if weight allows)
    if(arr[ind][0] <= wei){
        ans = max(ans, arr[ind][1] + rec(ind + 1, wei - arr[ind][0]));
    }
    
    return dp[ind][wei] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> w;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];  // weight, value
    }
    
    memset(dp, -1, sizeof(dp));
    cout << rec(0, w) << endl;
    return 0;
}
