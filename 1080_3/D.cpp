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
        vector<long long> v(n,0);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> v[i];
            sum+=v[i];
        }
        vector<long long> ans(n);

        for(int i=n-2;i>0;i--)
        {
            ans[i]=(v[i-1]-2*v[i]+v[i+1])/2LL;
        }
        long long summ=accumulate(ans.begin(),ans.end(),0LL);
        ans[0]=((v[n-1]-v[n-2])+((v[n-1]+v[0])/(n-1))-2*summ)/2;
        ans[n-1]=((v[n-1]-v[n-2])-(v[0]+v[n-1])/(n-1))/-2;

        for(auto an:ans) cout << an <<" ";
        cout << endl;

    }
    return 0;
}