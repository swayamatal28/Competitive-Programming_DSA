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
        int n;cin >> n;
        unordered_map<int,int> respect;
        unordered_map<int,vector<int>> maping;
        for(int i=0;i<n;i++){
            int p,c;cin >> p  >> c;
            if(p==-1) continue;
            respect[i+1]=c;
            maping[p].push_back(i+1);
        }
        vector<int> ans;
        for(auto mp:maping){
            int parent=mp.first;
            vector<int> childs=mp.second;

            if(respect[parent]==0) continue;
            bool add=true;
            for(auto child:childs){
                if(respect[child]==0) add=false;
            }
            if(add) ans.push_back(parent);
        }
        for(int i=1;i<=n;i++){
            if(maping.find(i)==maping.end()) {
                if(respect[i]==1) ans.push_back(i);
            }
        }
        if(ans.size()==0){
            cout << -1;
            cout << endl;
            continue;
        }
        sort(ans.begin(),ans.end());
        for(auto an:ans) cout << an << " ";
        cout << endl;
    }
    return 0;
}