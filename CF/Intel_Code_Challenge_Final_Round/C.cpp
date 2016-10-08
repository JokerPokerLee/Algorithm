#include <bits/stdc++.h>

#define INF 9999999999999

using namespace std;

long long ex_gcd(long long a, long long b, long long& x, long long& y) {
	// cout << a << " " << b << endl;
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	long long gcd = ex_gcd(b, a % b, x, y);
	long long t = a / b;
	long long tx = x;
	x = y, y = tx - t * y;
	return gcd;
}

int main() {
	freopen("1.in", "r", stdin);
	long long n, m, k;
	scanf("%lld %lld %lld", &n, &m, &k);
	long long tx, ty;
	long long G = ex_gcd(n, m, tx, ty);
	// cout << G << endl;
	// return 0;
	while (k--) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		if (x == y) {
			printf("%lld\n", x);
			continue;
		}
		long long x1, y1;
		long long res = INF;
		if ((x + y) % G == 0) {
			long long k = (x + y) / G;
			ex_gcd(n, m, x1, y1);
			x1 *= k, y1 *= k;
			long long t = x1 / (m / G);
			x1 -= t * (m / G);
			y1 += t * (n / G);
			for (long long k = -5; k <= 5; k++) {
				long long x2 = x1 + k * (m / G);
				long long y2 = y1 - k * (n / G);
				if (x2 % 2 == 0 && y2 % 2 == 0) {
					res = min(res, abs(x2 * n - x));
				}
			}
		}
		if ((x - y) % G == 0) {
			long long k = (x - y) / G;
			ex_gcd(n, m, x1, y1);
			x1 *= k, y1 *= k;
			long long t = x1 / (m / G);
			x1 -= t * (m / G);
			y1 += t * (n / G);
			for (long long k = -5; k <= 5; k++) {
				long long x2 = x1 + k * (m / G);
				long long y2 = y1 - k * (n / G);
				if (x2 <= 0 && y2 >= 0 && x2 % 2 ==0 && y2 % 2 == 0) {
					res = min(res, abs(x2 * n - x));
				}
				if (x2 > 0 && y2 < 0 && x2 % 2 ==0 && y2 % 2 == 0) {
					res = min(res, abs(x2 * n - x));
				}
			}
		}
		if (res == INF) {
			printf("-1\n");
		} else {
			printf("%lld\n", res);
		}
	}
	return 0;
}