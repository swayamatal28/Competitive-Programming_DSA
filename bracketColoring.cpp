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

bool change(string s, vector<int> &ans,bool &clr1,bool &clr2)   
{
    int open = 0;
    int close = 0;
    int i = 0;
    for (auto bracket : s)
    {
        if (bracket == '(')
        {
            open++;
            if (open == close)
            {
                ans[i] = 2;
                clr2 = true;
            }
        }
        else if (bracket == ')')
        {
            close++;
            if (close == open)
            {
                ans[i] = 1;
                clr1 = true;
            }
        }
        if (open > close)
        {
            ans[i] = 1;
                clr1 = true;

        }
        else if (close > open)
        {
            ans[i] = 2;
                clr2 = true;
        }
        i++;
        if (i == s.size())
        {
            if (close != open)
                return false;
        }
    }
    return true;
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
        string s;
        cin >> s;
        vector<int> ans(n, 0);
        bool clr1 = false;
        bool clr2 = false;
        bool hey = change(s, ans,clr1,clr2);
        if (!hey)
        {
            cout << -1 << endl;
        }
        else
        {
            if(clr1&&clr2) cout << 2 << endl;
            else cout << 1 << endl;
            for (auto hibaby : ans)
            {
                if((!clr1 || !clr2)) cout << 1 << " ";
                else
                cout << hibaby << " " ;
            }
            cout << endl;
        }
    }
    return 0;
}