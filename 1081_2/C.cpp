#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N = 1e5 + 11, mod = 1e9 + 7;
ll max(ll a, ll b) { return ((a > b) ? a : b); }
ll min(ll a, ll b) { return ((a > b) ? b : a); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        long long n, h, k;
        cin >> n >> h >> k;
        vector<long long> a(n);
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        long long  full=(h-1)/sum;
        long long ans=full*(n+k);

        ll target=h-full*sum;
        if (target <= 0)
        {
            cout << ans-k << endl;
            continue;
        }

        ll maxi = a[n - 1];
        vector<ll> maxim(n);
        maxim[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            maxim[i]=max(a[i],maxim[i+1]);
        }
        ll temp_sum=0;
        ll mini=2e18;

        for(int i=0;i<n;i++)
        {
            temp_sum+=a[i];
            mini=min(mini,a[i]);
            ll check=temp_sum;
            if(i+1<n)
            {
                check=max(check,temp_sum-mini+maxim[i+1]);
            }
            if(check>=target)
            {
                ans+=(i+1);
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}