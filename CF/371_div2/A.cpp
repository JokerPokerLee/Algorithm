#include <bits/stdc++.h>

using namespace std;

int main() {
    long long l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    long long l, r;
    l = max(l1, l2);
    r = min(r1, r2);
    if (l <= r) {
        if (k >= l && k <= r) {
            cout << r - l << endl;
        } else {
            cout << r - l + 1 << endl;
        }
    } else {
        cout << 0 << endl;
    }
    return 0;
}