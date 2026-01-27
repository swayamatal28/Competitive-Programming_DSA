#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while (q--) {
            long long x;
            cin >> x;

            long long ans = 0;
            int bs=0;
            for(int i=0;i<n;i++) if(s[i]=='B')bs++;
            if(bs==0){
                cout << x << endl;
                continue;
            }
            else{
                int i=0;
                while(x!=0)
                {
                    if(s[i]=='A') x--;
                    else x=x/2;
                    i=(i+1)%n;
                    ans++;
                }
                cout << ans << '\n';
            }

        }
    }

    return 0;
}
