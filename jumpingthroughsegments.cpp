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

bool check(int k,vector<pair<int,int>> &segs,int n)
{
   int l=0,r=0;
   for(int i=0;i<n;i++)
   {
    l=max(l-k,segs[i].first);
    r=min(r+k,segs[i].second);
    if(l>r) return false;
   }
   return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t;cin>>t;
    while(t--)
    {
        int n;cin >> n;
        vector<pair<int,int>> segs;
        for(int i=0;i<n;i++)
        {
            int l,r;cin >> l >> r;
            segs.push_back({l,r});
        }
        int low=0;
        int ans=0;
        int high=1e9;
        while(low<=high)
        {
            int mid=(high+low)/2;
            bool is_pos=check(mid,segs,n);
            if(is_pos)
            {
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}