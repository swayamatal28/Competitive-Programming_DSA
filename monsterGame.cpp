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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sort(a.begin(), a.end());
        vector<ll> pref_b(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            pref_b[i + 1] = pref_b[i] + b[i];
        }

        ll maxi = -1e9;
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            int av=n-i;
            auto it=upper_bound(pref_b.begin(),pref_b.end(),(ll)av);
            int lvs=distance(pref_b.begin(),it)-1;
            maxi=max(maxi,(ll)x*lvs);
        }
        cout << maxi << endl;
    }
    return 0;
}