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

int next(int x)
{
    return (x+(x%10));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t;cin>>t;
    while(t--)
    {
        int n;cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        bool hf=false,hz=false;
        sort(a.begin(),a.end());
        bool flag=false;
        for(int i=0;i<n;i++){
            if(a[i]%10==5 || a[i]%10==0) {
                flag=true;
                a[i]=next(a[i]);
            }
        }
        if(flag){
            int maxi=*max_element(a.begin(),a.end());
            int mini=*min_element(a.begin(),a.end());
            if(maxi==mini){
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;

            continue;
        }
        bool flag12=false;
        bool flag2=false;
        for(int i=0;i<n;i++){
            while(a[i]%10!=2){
                a[i]=next(a[i]);
            }
                if(a[i]%20==2) flag2=true;
                else flag12=true;
        }

        if(flag12 && flag2) {
            cout << "No" << endl;
        }
        else cout << "Yes" << endl;

    }
    return 0;
}