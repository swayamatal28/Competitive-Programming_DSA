#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N=1e5+11,mod=1e9+7;

vector<long long> clr(2,0);
void dfs(vector<int> adj[],int node,int pnode,int color)
{
    clr[color]++;
    
    for(auto val:adj[node])
    {
        if(pnode!=val)
        {
            dfs(adj,val,node,!color);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t=1;
    while(t--)
    {
        long long n;cin >> n;
        vector<int> adj[n+1];
        for(int i=0;i<n-1;i++)
        {
            int u,v;cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        clr[0]=clr[1]=0;
        dfs(adj,1,-1,0);

        cout << clr[0]*clr[1] - (n-1) << endl;
        
    }
    return 0;
}