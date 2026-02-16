#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int digits = 0;
        int temp = n;
        while (temp > 0) {
            digits++;
            temp /= 10;
        }
        int count = (digits - 1) * 9;
        int leading = n;
        while (leading >= 10) {
            leading /= 10;
        }
        count += leading;
        cout << count << "\n";
    }
    return 0;
}