#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N=1e5+11,mod=1e9+7;   

// int f(vector<vector<int>> &dp,vector<int> &a,int n, int prev,int k){
//     if(k==0) return 1;
//     if(n<0) return 0;
//     if(prev!=-1 && dp[n][prev]!=-1) return dp[n][prev];
//     int ntake=f(dp,a,n-1,prev,k);
//     int take=0;
//     if(prev==-1 || a[prev]%a[n]==0){
//         take=f(dp,a,n,n,k-1);
//     }
//     if(prev==-1) return take+ntake;
//     return dp[n][prev]=take+ntake;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t=1;
    while(t--)
    {
        int n;cin >> n;int k;cin >> k;
        vector<int> a;
        int mode=1e9+7;
        for(int i=1;i<n+1;i++) a.push_back(i);
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=1;i<=n;i++) dp[i][1]=1;

        for(int i=2;i<=k;i++){
            for(int j1=1;j1<=n;j1++){
                for(int j2=j1;j2<=n;j2+=j1){
                    dp[j2][i]=(dp[j2][i]+dp[j1][i-1])%mode; 
                }
            }
        }

        
        int ans=0;

        for(int i=1;i<=n;i++)ans=(ans+dp[i][k])%mode;
        cout << ans << endl;
    }
    return 0;
}

// 1 2 3
/* while converting from rec dp to itre dp , keep one thing in mind , you have to think of states and do not think on nottake condition*/
//   0 1 2
// 0
// 1
// 2


//practice++;