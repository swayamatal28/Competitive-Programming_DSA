#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N=1e5+11,mod=1e9+7;

class DSU{
    private:
    vector<int> parent;
    vector<int> sz;
    public:
    DSU(int n)
    {
        parent.resize(n+1);
        sz.resize(n+1,1);
        for(int i=1;i<n;i++) parent[i]=i;
    }
    int find(int x)
    {
        if(parent[x]==x) return x;
        else return parent[x]=find(parent[x]);
    }

    void unionBySize(int u,int v){
        int ulpu=find(u);
        int ulpv=find(v);

        if(ulpu==ulpv) return;

        if(sz[ulpu]>=sz[ulpv]){
            sz[ulpu]+=sz[ulpv];
            parent[ulpv]=ulpu;
        }
        else{
            sz[ulpv]+=sz[ulpu];
            parent[ulpu]=ulpv;
        }
    }

    vector<int> finda(int n){
        vector<int> temp;
        for(int i=1;i<=n;i++)
        {
            int x=find(i);
            temp.push_back(sz[x]);
        }
        return temp;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t=1;
    while(t--)
    {
        int n,m;cin >> n >> m ;
        DSU dsu(n);

        while(m--){
            int k;cin >> k;
            int curhead=-1;
            while(k--){
                int x;cin >> x;
                if(curhead==-1) curhead=x;
                else{
                    dsu.unionBySize(curhead,x);
                }
            }

        }
        vector<int> ans=dsu.finda(n);
        for(auto a:ans) cout << a << " ";
        cout << endl;
    }
    return 0;
}
