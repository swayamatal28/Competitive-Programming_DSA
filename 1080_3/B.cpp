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

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n+1);
        sz.resize(n+1, 1);
        for(int i=1;i<=n;i++) parent[i]=i;
    }

    int find(int x) {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a,int b) {
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
    bool samecomp(int a,int b){
        return find(a)==find(b);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];

        DSU dsu(n);

        for(int i=1; 2*i <= n; i++) {
            dsu.unite(i, 2*i);
        }
        unordered_map<int, vector<int>> comp;
        for(int i=1;i<=n;i++) {
            comp[dsu.find(i)].push_back(i);
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(!dsu.samecomp(i,a[i])) flag=false;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}