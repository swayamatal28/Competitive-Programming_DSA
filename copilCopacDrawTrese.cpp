#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N=1e5+11,mod=1e9+7;
ll max(ll a,ll b) {return ((a>b)?a:b);}
ll min(ll a,ll b) {return ((a>b)?b:a);}

void dfs(int node,vector<int> &dp,vector<vector<pair<int,int>>>& adj,vector<int>& pos){
    for(auto nd:adj[node]){
        if(dp[nd.first]==0){
            dp[nd.first]=dp[node]+(nd.second<=pos[node]);
            pos[nd.first]=nd.second;
            dfs(nd.first,dp,adj,pos);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t;cin>>t;
    while(t--)
    {
        int n;cin >>n;
        map<pair<int,int>,int> idx;
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> pos(n+1,0);
        for(int i=1;i<=n-1;i++){
            int u,v;cin >> u >> v;
            idx[{u,v}]=i;
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
        }
        vector<int> dp(n+1,0);
        dp[1]=1;

        dfs(1,dp,adj,pos);
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        cout << ans << endl;

    }
    return 0;
}