#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N = 200003;
const int bits = 30;
int pref[N][bits];

ll max(ll a, ll b) { return ((a > b) ? a : b); }
ll min(ll a, ll b) { return ((a > b) ? b : a); }
void Buildprefix(int n, vector<int> &a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (a[i] & (1 << j))
            {
                pref[i + 1][j] = pref[i][j] + 1;
            }
            else
            {
                pref[i + 1][j] = pref[i][j];
            }
        }
    }
}

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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int q;
        cin >> q;
        Buildprefix(n, a);
        while (q--)
        {
            int l, k;
            cin >> l >> k;
            if (a[l - 1] < k)
            {
                cout << -1 << " ";
                continue;
            }
            int low = l - 1;
            int high = n - 1;
            int ans = -1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                int num = 0;
                for (int j = 0; j < bits; j++)
                {
                    if (pref[mid + 1][j] - pref[l - 1][j] == mid - (l - 1) + 1)
                    {
                        num += (1 << j);
                    }
                }

                if (num >= k)
                {
                    low = mid + 1;
                    ans = max(ans, mid + 1);
                }
                else
                {
                    high = mid - 1;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}