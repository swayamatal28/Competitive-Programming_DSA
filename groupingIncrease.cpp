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
    
    int t;cin>>t;
    while(t--)
    {
        int n;cin >> n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        int a1_le=1e9,a2_le=1e9;
        int pen=0;
        for(int i=0;i<n;i++)
        {
            if(a1_le>a2_le) swap(a1_le,a2_le);
            if(a[i]<=a1_le) a1_le=a[i];
            else if(a[i]<=a2_le){
                a2_le=a[i];
            }
            else{
                a1_le=a[i];
                pen++;
            }
        }
        cout << pen << endl;

    }
    return 0;
}
// 2
//8 2 3 1 1
//inf