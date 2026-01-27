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
    
    
    int n;cin >> n;
    double nr=0;
    double dr=0;
    for(int i=0;i<n;i++)
    {
        int cred,obt;
        cin >> cred >> obt;
        nr+=(cred*obt);
        dr+=cred;
    }
    cout << nr/dr << endl;
}