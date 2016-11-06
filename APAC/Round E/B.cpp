#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("1.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	// freopen("B-small-attempt1.in", "r", stdin);
	// freopen("B-small-attempt1.out", "w", stdout);
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
			// cout << "<" << maxi << ">" << endl;
			long long l = 2, r = n;
			bool exi = false;
			while (l <= r) {
				long long m = (l + r) / 2;
				// cout << "===" << m << "===" << endl;
				long long now = 0;
				bool flag = true;
				for (int i = maxi - 1; i >= 0; i--) {
					long long cur = 1;
					long long res = n - now;
					for (int j = 0; j < i; j++) {
						if (res / cur < m) {
							flag = false;
							break;
						}
						cur *= m;
					}
					if (!flag) {
						break;
					}
					now += cur;
					// cout << now << endl;
				}
				if (!flag) {
					r = m - 1;
				} else {
					l = m + 1;
				}
				if (flag && now == n) {
					exi = true;
					break;
				}
			}
			if (exi) {
				cout << "Case #" << tt << ": " << l - 1 << endl;
				break;
			}
			maxi--;
			// break;
		}
	}
	return 0;
}