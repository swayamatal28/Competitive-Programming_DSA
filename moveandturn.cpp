#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N=1e5+11,mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t=1;
    while(t--)
    {
        long long n;cin >> n;
        if(n%2==0)
        {
            ll k=(n/2);
            cout << 1LL* ((n/2)+1)*((n/2)+1) << endl;
        }
        else{
            cout << 2LL *((n/2)+1)*((n/2)+2) << endl;
        }
    }
    return 0;
}