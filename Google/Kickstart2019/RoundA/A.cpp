#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		int n, p, x;
		scanf("%d %d", &n, &p);
		vector<int> a;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		int sum = 0, ans = 1e9;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (i >= p) {
				sum -= a[i - p];
			}
			if (i >= p - 1) {
				ans = min(ans, a[i] * p - sum);
			}
		}
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}