#include <bits/stdc++.h>

#define MP make_pair
#define EPS 1e-7

using namespace std;

typedef pair<int, int> PII;

int find(int x, vector<int> &p) {
	int l = 0, r = p.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (p[m] <= x) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return r + 1;
}

int main() {
	int t0 = time(0);
	int ttt;
	scanf("%d", &ttt);
	int NMAX = 1000000000;
	vector<int> a(NMAX + 1);
	vector<int> p(1, 1);
	for (int i = 1; i < a.size(); i++) {
		a[i] = i;
	}
	for (int i = 2; i < a.size(); i++) {
		if (a[i] == i) {
			p.push_back(i);
		}
		for (int j = 1; j < p.size(); j++) {
			if (NMAX / i < p[j]) {
				break;
			}
			a[i * p[j]] = p[j];
			if (i % p[j] == 0) {
				break;
			}
		}
	}
	cout << sizeof(int) * a.capacity() * 1.0 / 1024 / 1024 / 1024 << endl;
	cout << time(0) - t0 << endl;
	for (int tt = 1; tt <= ttt; tt++) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		int ans = r / 2 - l / 2;
		ans -= r / 4 - l / 4;
		ans += find(r / 4, p) - find(l / 4, p);
		ans += find(r, p) - find(l, p);
		if (2 > l && 2 <= r) {
			ans--;
		}

		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}