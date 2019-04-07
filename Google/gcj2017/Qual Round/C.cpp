#include <bits/stdc++.h>

using namespace std;

long long ex_gcd(long long a, long long b, long long& x, long long& y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	long long g = ex_gcd(b, a % b, x, y);
	long long t = x;
	x = y, y = t - (a / b) * y;
	return g;
}

long long solve(long long a, long long b, long long c, long long l, long long& x, long long& y) {
	// cout << a << " " << b << " " << c << " " << l << endl;
	x = b * l - c;
	y = l - x;
	if (x < 0) {
		x += b;
		y -= b;
	}
}

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	// freopen("C-small-practice-2.in", "r", stdin);
	// freopen("C-small-practice-2.out", "w", stdout);
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		printf("Case #%d: ", tt);
		long long n, k;
		cin >> n >> k;

		// cout << endl;
		// bool pos[n + 1];
		// memset(pos, 0, sizeof(pos));
		// pos[0] = pos[n + 1] = true;
		// for (int i = 1; i <= k; i++) {
		// 	int res = -1;
		// 	int ma = 0, mi = 0;
		// 	for (int j = 1; j <= n; j++) {
		// 		if (pos[j]) {
		// 			continue;
		// 		}
		// 		int l = j - 1, r = j + 1;
		// 		while (!pos[l]) l--;
		// 		while (!pos[r]) r++;
		// 		l = j - l - 1;
		// 		r = r - j - 1;
		// 		if (l > r) {
		// 			continue;
		// 		}
		// 		if (l > mi || (l == mi && r > ma)) {
		// 			ma = r;
		// 			mi = l;
		// 			res = j;
		// 		}
		// 	}
		// 	// cout << ma << " " << mi << endl;
		// 	pos[res] = true;
		// 	if (i == k) {
		// 		cout << endl;
		// 		cout << ma << " " << mi << endl;
		// 	}
		// }

		long long l = 1;
		int m = 0;
		while ((l << 1) <= k) {
			l <<= 1;
			m++;
		}
		long long rem = k - l + 1;
		long long a = n, b;
		for (int i = 0; i < m; i++) {
			a = (a - 1) >> 1;
		}
		b = a + 1;
		long long c = n - l + 1;
		long long x, y;
		// ex_gcd(a, b, x, y);
		// x *= c, y *= c;
		// if (x < 0) {
		// 	long long t = (-x + b - 1) / b;
		// 	x += t * b, y -= t * a;
		// }
		// y += a * (x / b);
		// x %= b;

		// cout << endl;
		// cout << a << " " << b << " " << c << endl;
		// cout << x << " " << y << endl;
		// cout << rem << endl;

		solve(a, b, c, l, x, y);
		// cout << x << " " << y << endl;

		long long t = rem <= y ? b : a;
		// cout << t << endl;
		b = (t - 1) / 2;
		a = t - 1 - b;
		cout << a << " " << b << endl;
	}
	return 0;
}