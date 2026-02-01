#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N = 1e5 + 11, mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        multiset<ll> difs;
        sort(a.begin(), a.end());
        for (ll i = 0; i < n - 1; i++)
        {
            ll dif = a[i + 1] - a[i];
            difs.insert(dif);
        }
        if (k == 1)
        {
            ll cif = *(difs.begin());
            cout << min(cif, a[0]) << endl;
        }
        else if (k == 2)
        {
            ll ans = min(a[0], *(difs.begin()));

            for (ll i = 0; i < n; i++)
            {
                for (ll j = 0; j < i; j++)
                {
                    ll v = a[i] - a[j];

                    ans = min(ans, v); 
                    ll p = lower_bound(a.begin(), a.end(), v) - a.begin();

                    if (p < n)
                        ans = min(ans, abs(a[p] - v));
                    if (p > 0)
                        ans = min(ans, abs(v - a[p - 1]));
                }
            }

            cout << ans << endl;
        }
        else if (k >= 3)
        {
            // cout << "printing for k=" << k << ",and n= " << n << "," <<  0 << endl;
            cout << 0 << endl;
            continue;
        }
    }
    return 0;
}