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
    
    int t=1;
    while(t--)
    {
        int n,m,k;cin>>n>>m>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];

        if(k>=n){
            cout << n << endl;
            continue;
        }
        sort(v.begin(),v.end());
        long long ans=1LL*n;

        multimap<ll,pair<int,int>> segs;

        for(int i=1;i<n;i++){
            segs.insert({1LL*v[i]-v[i-1], {v[i], v[i-1]}});
        }
        set<int> st;
        for(auto seg:segs){
            ll len=seg.first;
            int p=seg.second.first;
            int u=seg.second.second;
            if(st.find(u)==st.end() && st.find(p)==st.end()){
                ans-=2LL;
                ans+=1LL*(len+1);
            }
            else{
                ans--;
                ans+=1LL*len;
            }
            n--;
            if(n==k) break;
        }
        cout << ans << endl;
        
    }
    return 0;
}