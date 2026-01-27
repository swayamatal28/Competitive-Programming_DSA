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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t;cin>>t;
    while(t--)
    {
        int n;cin >> n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        cin >> a[i];

        set<int> s;
        for(int i=0;i<n;i++)
        s.insert(a[i]);
        queue<int>q;
        vector<int> dist(n+1,-1);
        for(auto v:s)
        {
            if(dist[v]==-1)
            {
                dist[v]=1;
                q.push(v);
            }
        }
        vector<int> vl(s.begin(),s.end());

        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto x:vl)
            {
                ll v=(ll)u*x;
                if(v>n) break;
                if(dist[v]==-1)
                {
                    dist[v]=1+dist[u];
                    q.push(v);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout << dist[i] << " ";
        }
        cout << endl;

    }
    return 0;
}