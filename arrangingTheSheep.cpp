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
        // cout << ceil(5/2.0) << endl;
        // continue;
        int n;cin >> n;
        string s;cin >> s;
        int nos=0;
        for(auto ch:s) if(ch=='*') nos++;
        
        int fstr=-1,lstr=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*'){
                fstr=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='*'){
                lstr=i;
                break;
            }
        }
        int strs=0;
        for(int i=0;i<n;i++) if(s[i]=='*')strs++;

        n=(lstr-fstr+1);

        if(n==nos || (fstr==lstr) )
        {
            cout << 0 << endl;
            continue;
        }


        int tgt=ceil(strs/2.0);
        if(strs%2==0) tgt++;
        int idx=-1;
        int check=0;
        for(int i=fstr;i<=lstr;i++)
        {
            if(s[i]=='*') check++;
            if(check==tgt)
            {
                idx=i;
                break;
            }
        }
        long long cnt=0;
        int stn=0;
        idx--;
        for(int i=idx;i>=0;i--)
        {
            if(s[i]=='*'){
                stn++;
                cnt+=(idx-i)-(stn-1);
            }
        }
        idx+=2;
        stn=0;
        for(int i=idx;i<=lstr;i++)
        {
            if(s[i]=='*'){
                stn++;
                cnt+=(i-idx)-(stn-1);
            }
        }
        cout << cnt << endl;

    }
    
    return 0;
}