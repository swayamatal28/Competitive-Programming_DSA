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

int f(vector<vector<int>> &dp, vector<int> &s, int n, int prev)
{
    if (n < 0)
        return 0;
    if (prev != -1 && dp[n][prev] != -1)
        return dp[n][prev];
    int take = 0;
    if (prev == -1 || (s[prev] > s[n] && (prev + 1) % (n + 1) == 0))
    {
        take = 1 + f(dp, s, n - 1, n);
    }
    int ntake = f(dp, s, n - 1, prev);
    if (prev == -1)
        return max(take, ntake);
    else
        return dp[n][prev] = max(take, ntake);
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

        // 1.Solve this question using rec dp, this will give mle as well as tle

        //     2.Now while converting to iterative dp,
        //     we get to know that we do not require 2d dp in iteration, hence you'll learn a lot. 
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        vector<int> dp(n + 1, 1);
        int ans = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                if (s[j] > s[i])
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
