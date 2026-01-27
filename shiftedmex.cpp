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
        vector<ll> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        long long mex=0;
        int cur=0;
        for(int i=0;i<a.size();i++)
        {
            if(i>0 && a[i]==a[i-1]+1)
            {
                cur++;
            }
            else cur=1;
            mex=max(mex,(ll)cur);
        }
        cout << mex << endl;
    }
    return 0;
}