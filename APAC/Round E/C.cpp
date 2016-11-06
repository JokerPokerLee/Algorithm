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
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	// freopen("C-small-attempt2.in", "r", stdin);
	// freopen("C-small-attempt2.out", "w", stdout);
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
				int res = n - fir * i;
				if (res == 0) {
					ans++;
					// cout << ans << endl;
					continue;
				}
				int a = fir + 1, b = fir + 2;
				int x, y;
				int g = ex_gcd(a, b, x, y);
				x *= res / g, y *= res / g;
				// cout << g << " " << x << " " << y << endl;
				if (res % g) {
					continue;
				}
				LL t;
				if (x < 0) {
					t = (-x + b / g - 1) / (b / g);
					x += (b / g) * t;
					y -= (a / g) * t;
				}
				// cout << x << " " << y << endl;
				if (y < 0) {
					t = (-y + a / g - 1) / (a / g);
					x -= (b / g) * t;
					y += (a / g) * t;
				}
				// cout << x << " " << y << endl;
				if (x < 0 || y < 0) {
					continue;
				}
				t = x / (b / g) + y / (a / g) + 1;
				ans += t;
				// cout << ans << endl;
			}
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}