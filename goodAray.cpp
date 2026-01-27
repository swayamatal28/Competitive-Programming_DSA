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

    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        map<long long,int> m;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];m[a[i]]++;
        }
        
        long long sum = accumulate(a.begin(), a.end(), 0LL);

        for (int i = 0; i < n; i++)
        {
            sum=sum-a[i];
            m[a[i]]--;

            if(sum%2==0 && m[sum/2]>0)
            ans.pb(i+1);

            sum=sum+a[i];
            m[a[i]]++;
        }
        cout << ans.size() << endl;
        for (auto val : ans)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}