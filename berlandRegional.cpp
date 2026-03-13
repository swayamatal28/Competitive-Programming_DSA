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
        int n;
        cin >> n;
        vector<int> u(n), s(n);

        map<int, vector<ll>> m;

        for (int i = 0; i < n; i++)
        {
            cin >> u[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++)
        {
            m[u[i]].push_back(s[i]);
        }
        for (auto &val : m)
        {
            sort(val.second.rbegin(), val.second.rend());
        }

        for (auto &val : m)
        {
            vector<ll> &what = val.second;
            vector<ll> temp;

            int sz = what.size();

            if (sz == 0)
                continue;

            ll sum = 0;

            for (int i = 0; i < sz; i++)
            {
                sum += what[i];
                temp.push_back(sum); 
            }
            val.second = temp;
        }

        vector<ll> ans(n + 1, 0);

        for (auto &mpp : m)
        {
            auto &check = mpp.second;
            int sz = check.size();

            for (int k = 1; k <= sz; k++)
            {
                int full = (sz / k) * k;
                if (full > 0)
                    ans[k] += check[full - 1];
            }
        }

        for (int k = 1; k <= n; k++)
            cout << ans[k] << " ";

            cout << endl;
    }
    return 0;
}