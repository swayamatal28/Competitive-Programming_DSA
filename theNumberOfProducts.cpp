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
    
    int t;
    t=1;
    while(t--)
    {
        int n;cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        long long ans=0;
        int cnt1=1;
        int cnt2=0;
        int negs=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<0) negs++;
            if(negs%2==0) ans+=cnt1;
            else ans+=cnt2;
            if(negs%2==0) cnt1++;
            else cnt2++;

        }
        long long ans2=(1LL*n*(n+1))/2-ans;
        cout << ans2 << " " << ans << endl;
        
    }
    return 0;
}