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

const int maxi = 500005;
int cnt[maxi];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        cnt[val]++;
    }
    bool yes=false; 
    for (int i = 1; i < x; i++)
    {
        if (cnt[i] % (i + 1) != 0)
        {
            cout << "No" << endl;
            yes=true;
        }
        cnt[i + 1] += cnt[i] / (i + 1);
        if(yes) break;
    }
    if(!yes)
    cout << "Yes" << endl;
    
    return 0;
}
