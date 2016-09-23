#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int ti;
		scanf("%d", &ti);
		t[ti]++;
	}
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		int mach = 1;
		while (t[mach] == 0) {
			mach++;
		}
		c.clear();
		c.insert(make_pair(t[mach], 1));
		int copy = 0;
		while (copy < x) {
			c.begin()
		}
	}
	return 0;
}