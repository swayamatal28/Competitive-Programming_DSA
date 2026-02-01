#include <bits/stdc++.h>
using namespace std;

// Use long long for values to handle potential intermediate sums > 2^31
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x_in, y_in;
        cin >> x_in >> y_in;
        ll x = x_in;
        ll y = y_in;

        // Find the highest bit where both x and y have a 1 (collision)
        int k = -1;
        for (int i = 29; i >= 0; i--) {
            if ((x & (1 << i)) && (y & (1 << i))) {
                k = i;
                break;
            }
        }

        // If no collision, the original numbers are the answer
        if (k == -1) {
            cout << x << " " << y << "\n";
            continue;
        }

        ll best_ans = -1;
        ll ans_p = -1, ans_q = -1;

        auto update = [&](ll p, ll q) {
            ll cost = abs(x - p) + abs(y - q);
            if (best_ans == -1 || cost < best_ans) {
                best_ans = cost;
                ans_p = p;
                ans_q = q;
            }
        };

        // --- Strategy 1: Split at K ---
        // Option A: p keeps bit K, q clears bit K.
        // p tries to look exactly like x (keeps K).
        // q looks like y above K, clears K, and fills all bits < K with 1s (where allowed).
        // Mask for bits lower than K: (1LL << k) - 1
        // Mask for bits higher than K: ~((1LL << (k + 1)) - 1)
        ll mask_low = (1LL << k) - 1;
        ll mask_high = ~((1LL << (k + 1)) - 1);

        ll p1 = x; 
        // q1 keeps high bits of y, and takes all low bits NOT used by p1
        ll q1 = (y & mask_high) | (mask_low & ~p1); 
        update(p1, q1);

        // Option B: q keeps bit K, p clears bit K.
        ll q2 = y;
        ll p2 = (x & mask_high) | (mask_low & ~q2);
        update(p2, q2);


        // --- Strategy 2: Round Up (Flip 0 to 1 above K) ---
        // Find the first bit i > K where both x and y are 0.
        // We can set this bit in p (or q) to 1, and clear all bits < i.
        // This makes the number disjoint from the other (which is 0 at i)
        // and resolves the collision at K implicitly.
        for (int i = k + 1; i <= 30; i++) {
            if (!((x >> i) & 1) && !((y >> i) & 1)) {
                ll mask_keep_high = ~((1LL << i) - 1);
                
                // Try rounding up p
                ll p3 = (x & mask_keep_high) | (1LL << i);
                ll q3 = y; // q can stay y because p has cleared the collision bits
                update(p3, q3);

                // Try rounding up q
                ll q4 = (y & mask_keep_high) | (1LL << i);
                ll p4 = x;
                update(p4, q4);

                // Because cost increases exponentially with i, the first valid i 
                // is the optimal "Round Up" candidate. We can break.
                break;
            }
        }

        cout << ans_p << " " << ans_q << "\n";
    }
    return 0;
}