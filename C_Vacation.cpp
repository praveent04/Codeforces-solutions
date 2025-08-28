#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100001][3];
int dp[100001][4];
int rec(int ind, int taken){
    if(ind == n) return 0;
    if(dp[ind][taken] !=-1) return dp[ind][taken];
    int ans = 0 ;
    if(taken ==0){
        ans = max(ans,arr[ind][1] + rec(ind+1,1));
        ans = max(ans,arr[ind][2] + rec(ind+1,2));
    }
    else if (taken == 1){
        ans = max(ans,arr[ind][0] + rec(ind+1,0));
        ans = max(ans,arr[ind][2] + rec(ind+1,2));
    }
    else if(taken ==2){
        ans = max(ans,arr[ind][1] + rec(ind+1,1));
        ans = max(ans,arr[ind][0] + rec(ind+1,0));
    }
    else{
        ans = max(ans,arr[ind][1] + rec(ind+1,1));
        ans = max(ans,arr[ind][0] + rec(ind+1,0));
        ans = max(ans,arr[ind][2] + rec(ind+1,2));
    }
    return dp[ind][taken] = ans;
}
int main(){
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
        cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,3)<<endl;
    return 0;
}