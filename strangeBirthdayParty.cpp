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
        int n,m;cin >> n >> m;
        ll cost=0;
        vector<ll> k(n);
        vector<ll> c(m);
        for(int i=0;i<n;i++) cin >> k[i];
        for(int j=0;j<m;j++)
        {
            int x;cin >> x;
            c[j]=(x);
        }
        sort(k.rbegin(),k.rend());
        int pnt=0;
        for(int i=0;i<n;i++)
        {
            if(pnt>=m)
            {
                cost+=c[k[i]-1];
                continue;
            }
            else{
            int dlr=c[k[i]-1];
            int gift=c[pnt];
            if(dlr<=gift)
            {
                cost+=dlr;
                continue;
            }
            else{
                cost+=gift;
                pnt++;
            }
            }
            
        }
        cout << cost << endl;
    }
    return 0;
}