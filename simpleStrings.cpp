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
    
    string s;cin >> s;
    int n=s.size();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(i>0 && s[i]==s[i-1])
        {
            char check=char((s[i]-'a'+1)%26 + 'a');
            char bck=char((s[i]-'a'+25)%26 + 'a');

            if(i+1<n && s[i+1]==check) s[i]=bck;
            else s[i]=check;
        }
    }
    // cout << cnt << endl;
    cout << s<< endl;
    
    return 0;
}