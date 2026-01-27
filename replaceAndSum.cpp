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
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<int> m(n);
        int try_me = -1e9;
        for (int i = n - 1; i >= 0; i--)
        {
            try_me = max(try_me, max(a[i], b[i]));
            m[i] = try_me;
        }
        vector<long long> pref(n);
        pref[0] = m[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + m[i];
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int sum = pref[r] - (l > 0 ? pref[l-1] : 0);

            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}