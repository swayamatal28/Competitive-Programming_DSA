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
        int n, x, y;
        cin >> n >> x >> y;
        x--;y--;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];
        vector<int> ans1;
        int mini = n + 1;
        int idx = -1;
        for (int i = x + 1; i <= y; i++)
        {
            if (p[i] < mini)
            {
                mini = p[i];
                idx = i;
            }
        }
        
        for (int i = idx; i <= y; i++)
        {
            ans1.push_back(p[i]);
        }
        for (int i = x + 1; i < idx; i++)
            ans1.push_back(p[i]);

        vector<int> ans0, ans2;

        for (int i = 0; i <= x; i++)
        {
            if (p[i] < mini && ans2.size()==0)
                ans0.push_back(p[i]);
            else 
                ans2.push_back(p[i]);
        }

        for (int i = y + 1; i < n; i++)
        {
            if (ans2.size() > 0)
            {
                ans2.push_back(p[i]);
            }
            else
            {
                if (p[i] < mini)
                {
                    ans0.push_back(p[i]);
                }
                else
                {
                    ans2.push_back(p[i]);
                }
            }
        }
        vector<int> ans;

        int n0 = ans0.size();
        for (int i = 0; i < n0; i++)
            ans.push_back(ans0[i]);
        int n1 = ans1.size();
        for (int i = 0; i < n1; i++)
            ans.push_back(ans1[i]);
        int n2 = ans2.size();
        for (int i = 0; i < n2; i++)
            ans.push_back(ans2[i]);

        for(auto an:ans) cout << an << " ";
        cout << endl;
    }
    return 0;
}