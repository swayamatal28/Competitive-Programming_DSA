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
        ll k, x;
        cin >> k >> x;
        ll maxMessages = (2 * k) - 1;
        ll high = maxMessages, low = 1;
        ll mid;
        if (x >= k * k)
        {
            cout << 2 * k - 1 << "\n";
            continue;
        }

        while (low <= high)
        {
            mid = low + ((high - low) / 2);
            ll spams;
            if (mid <= k)
            {
                spams = mid * (mid + 1) / 2;
            }
            else
            {
                ll missing = (2 * k - 1) - mid;
                spams = k * k - missing * (missing + 1) / 2;
            }
            if (spams >= x)
                high = mid - 1;
            else
                low = mid + 1;
        }

        cout << low << endl;
    }
    return 0;
}

/* mess*(mess/2)+mess/2
1 1
2
3
4
5
6
7
*/