#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> col_masks(n, 0);

    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            col_masks[j] |= (1 << (s[j] - 'a'));
        }
    }

    vector<int> divisors;
    for (int d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            divisors.push_back(d);
            if (d * d != n) {
                divisors.push_back(n / d);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    for (int d : divisors) {
        string pattern = "";
        bool possible = true;

        for (int i = 0; i < d; ++i) {
            int current_mask = (1 << 26) - 1;
            
            for (int j = i; j < n; j += d) {
                current_mask &= col_masks[j];
                
                // Optimization: If mask becomes 0, no character works for this position
                if (current_mask == 0) break;
            }

            if (current_mask > 0) {
                // Find the first set bit (smallest character)
                // __builtin_ctz returns the number of trailing zeros
                int char_idx = __builtin_ctz(current_mask); 
                pattern += (char)('a' + char_idx);
            } else {
                possible = false;
                break;
            }
        }

        if (possible) {
            string result = "";
            for (int i = 0; i < n / d; ++i) {
                result += pattern;
            }
            cout << result << endl;
            return; // Found the minimal informativity, we are done
        }
    }
}

int main() {
    // Optimize I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}