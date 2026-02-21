#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N=1e5+11,mod=1e9+7;
ll max(ll a,ll b) {return ((a>b)?a:b);}
ll min(ll a,ll b) {return ((a>b)?b:a);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t=1;
    while(t--)
    {
        vector<int> chk={4,7,47,74,444,777,477,447,744,774};
        int n;cin >> n;
        bool hmum=false;
        for(int i=0;i<10;i++)
        {
            if(n%chk[i]==0 && !hmum)
            {
                cout << "YES" << endl;
                hmum=true;
            }
        }
        if(!hmum) cout << "NO" << endl;
    }
    return 0;
}