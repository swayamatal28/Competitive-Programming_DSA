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
        int a,b,c,d;
        cout << "? " << 1 << " " << 2 << endl;
        cin >> a;
        fflush;
        cout << "? " << 2 << " " << 3 << endl;
        cin >> b;
        fflush;
        cout << "? " << 4 << " " << 5 << endl;
        cin >> c;
        fflush;
        cout << "? " << 5 << " " << 6 << endl;
        cin >> d;
        fflush;

        vector<int> temp;
    
        temp={4,8,15,16,23,42};
        map<int,pair<int,int>>mpp;
    
        for(int i=0;i<6;i++){
            for(int j=i+1;j<6;j++){
                mpp[temp[i]*temp[j]]={temp[i],temp[j]};
            }
        }
                                    
        vector<int> ans(6);
    
        int x = mpp[a].first;
        int y = mpp[a].second;
        int z = mpp[b].first;
        int z2= mpp[b].second;

        if(x==z){
            ans[1]=x;
            ans[0]=y;
            ans[2]=z2;
        }
        else if(x==z2){
            ans[1]=x;
            ans[0]=y;
            ans[2]=z;
        }
        else if(y==z){
            ans[1]=y;
            ans[0]=x;
            ans[2]=z2;
        }
        else if(y==z2){
            ans[1]=y;
            ans[0]=x;
            ans[2]=z;
        }

        x=mpp[c].first;
        y=mpp[c].second;
        z=mpp[d].first;
        z2=mpp[d].second;

        if(x==z){
            ans[4]=x;
            ans[3]=y;
            ans[5]=z2;
        }
        else if(x==z2){
            ans[4]=x;
            ans[3]=y;
            ans[5]=z;
        }
        else if(y==z){
            ans[4]=y;   
            ans[3]=x;
            ans[5]=z2;
        }
        else if(y==z2){
            ans[4]=y;
            ans[3]=x;
            ans[5]=z;
        }

        cout << "! ";
        for(auto a:ans) cout << a << " ";
        cout << endl;
    }
    return 0;
}

