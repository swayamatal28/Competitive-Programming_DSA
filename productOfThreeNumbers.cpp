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
        bool found = false;
        if (n % 2 == 0)
        {

            n = n / 2;
            for (int i = 3; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    if (n / i != i && n / i != 2)
                    {
                        cout << "YES" << endl
                             << 2 << " " << i << " " << n / i << endl;
                        found = true;
                        break;
                    }
                }
            }
        }
        else
        {
            int a = -1, b = -1, c = -1;
            for (int i = 3; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    a = i;
                    break;
                }
            }
            if (a != -1)
            {
                n = n / a;
                for (int i = a + 2; i * i <= n; i++)
                {
                    if (n % i == 0)
                    {
                        b=i;
                        c=(n/(i));
                        if(c!=a && c!=b)
                        {
                            break;
                        }
                        else{
                            b=c=-1;
                        }
                    }
                }
            }
            if (a!=-1 && b!=-1 && c != 1 && c>1)
            {
                cout << "YES" << endl
                     << a << " " << b << " " << c << endl;
                found = true;
            }
        }
        if (!found)
            cout << "NO" << endl;
    }
    return 0;
}