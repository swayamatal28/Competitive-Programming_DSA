#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N=1e5+11,mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t=1;
    while(t--)
    {
        long long n,h;cin >> n >> h;
        vector<long long>a(n);
        for(long long i=0;i<n;i++) cin >> a[i];
        long long ans=-1;

        for(long long i=0;i<n;i++)
        {
           vector<long long> perform(a.begin(),a.begin()+i+1);
           sort(perform.begin(),perform.end());
           long long height_needed=0;
           for(long long j=i;j>=0;j-=2)
           {
            height_needed+=perform[j];
           }
           if(height_needed<=h)
           ans=max(ans,i+1);
        }
        cout << ans << endl;
        
    }
    return 0;
}