#include <bits/stdc++.h>

#define LL long long

using namespace std;

int ex_gcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int g = ex_gcd(b, a % b, x, y);
	int t = x;
	x = y, y = t - (a / b) * y;
	return g;
}

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	// freopen("A-large.in", "r", stdin);
	// freopen("A-large.out", "w", stdout);
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-baoli.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		int n, t;
		cin >> n >> t;
		LL ans = 0;
		for (int fir = t; fir <= n; fir += t) {
			// cout << "<" << fir << ">" << endl;
			for (int i = n / fir; i >= 1; i--) {
				// cout << i << ": " << endl;
				int res = n - i * fir;
				for (int j = res / (fir + 1); j >= 0; j--) {
					int tmp = res - j * (fir + 1);
					if (tmp % (fir + 2)) {
						continue;
					}
					ans++;
				}
			}
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}