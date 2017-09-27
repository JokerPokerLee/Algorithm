#include <bits/stdc++.h>

using namespace std;

int p[1000010], a[1000010];
int idx[1000010];
bool ex[1000010];
int tot;

int main() {
	freopen("1.in", "r", stdin);
	int ti0, ti1, ti2, ti3;
	ti0 = clock();
	for (int i = 1; i <= 1000000; i++) {
		a[i] = i;
	}
	for (int i = 2; i <= 1000000; i++) {
		if (a[i] == i) {
			idx[i] = tot;
			p[tot++] = i;
		}
		for (int j = 0; j < tot; j++) {
			if (1LL * p[j] * i > 1000000) {
				break;
			}
			a[p[j] * i] = p[j];
			if (i % p[j] == 0) {
				break;
			}
		}
	}
	ti1 = clock();
	cout << "Time consumed: " << setprecision(3) << 1.0 * (ti1 - ti0) / CLOCKS_PER_SEC << "s" << endl;
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	vector<int> num;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		num.push_back(x);
		while (x > 1) {
			int t = a[x];
			while (a[x] == t) {
				x /= t;
			}
			ex[idx[t]] = true;
		}
	}
	ti2 = clock();
	cout << "Time consumed: " << setprecision(3) << 1.0 * (ti2 - ti1) / CLOCKS_PER_SEC << "s" << endl;
	long long ans = 1LL * n * min(x, y);
	for (int i = 0; i < tot; i++) {
		if (!ex[i]) {
			continue;
		}
		int f = p[i];
		long long cost = 0;
		for (int j = 0; j < n; j++) {
			int m = num[j] % f;
			if (m == 0) {
				continue;
			}
			cost += min(1LL * y * (f - m), 1LL * x);
			if (cost > ans) {
				break;
			}
		}
		ans = min(ans, cost);
	}
	cout << ans << endl;
	ti3 = clock();
	cout << "Time consumed: " << setprecision(3) << 1.0 * (ti3 - ti2) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}