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
        int n, k;
        cin >> n >> k;
        vector<int> divs;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                divs.push_back(i);
                if (i * i != n)
                {
                    divs.push_back(n / i);
                }
            }
        }
        vector<vector<bool>> has(n, vector<bool>(26, false));

        for (int i = 0; i < k; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++)
            {
                has[j][s[j] - 'a'] = true;
            }
        }
        // cout << "divs: " << endl;
        // for(auto d:divs) cout << d << " ";
        sort(divs.begin(), divs.end());
        string ans = "";
        int d = divs.size();
        for (int i = 0; i < d; i++)
        {
            int divisor = divs[i]; // 1
            string pattern = "";
            bool possible=true;
            for (int h = 0; h < divisor; h++)
            {
                char fc = 0;
                for (int c = 0; c < 26; c++)
                {
                    bool chok = true;
                    for (int j = h; j < n; j += divisor)
                    {
                        if (!has[j][c])
                        {
                            chok = false;
                            break;
                        }
                    }
                    if (chok)
                    {
                        fc = (char)('a' + c);
                        break;
                    }
                }
                if (fc != 0)
                    pattern += fc;
                else
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
            {
                string ans = "";
                for (int z = 0; z < n / divisor; z++)
                    ans += pattern;
                cout << ans << endl;
                break;
            }
        }
    }
    return 0;
}