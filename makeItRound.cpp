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
        long long n,m;cin >> n >> m;
        //O(N)  NOT ALLOWED.
        long long check=n;
        int cnt2=0,cnt5=0;
        long long k=1;
        while(n>0 && n%2==0){
            cnt2++;
            n=n/2;
        }
        while( n>0 && n%5==0){
            cnt5++;
            n=n/5;
        }
        while(cnt2<cnt5 && 2*k<=m){
            cnt2++;
            k=k*2;
        }
        while(cnt5<cnt2 && 5*k<=m){
            cnt5++;
            k=k*5;
        }
        while(k*10LL<=m){
            k*=10;
        }
        if(k==1) cout << 1LL*check*m << endl;
        else{
            k=k*(m/k);
            cout << check*k      << endl;
        }


    }

    return 0;
}