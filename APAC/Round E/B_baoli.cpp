#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	// freopen("A-large.in", "r", stdin);
	// freopen("A-large.out", "w", stdout);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("baoli.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		long long n;
		cin >> n;
		int maxi = 0;
		long long tmp = n;
		while (tmp) {
			tmp >>= 1;
			maxi++;
		}
		// maxi = 3;
		while (maxi) {
			long long l = 2, r = n;
			bool exi = false;
			while (l <= r) {
				long long m = (l + r) / 2;
				// cout << "===" << m << "===" << endl;
				long long now = 0;
				for (int i = maxi - 1; i >= 0; i--) {
					long long cur = 1;
					long long res = n - now;
					for (int j = 0; j < i; j++) {
						cur *= m;
					}
					now += cur;
				}
				if (now > n) {
					r = m - 1;
				} else {
					l = m + 1;
				}
				// cout << now << endl;
				if (now == n) {
					exi = true;
					break;
				}
			}
			if (exi) {
				cout << "Case #" << tt << ": " << l - 1 << endl;
				break;
			}
			maxi--;
		}
	}
	return 0;
}