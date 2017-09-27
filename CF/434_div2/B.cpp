#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	int ans = -1;
	vector<int> d, f;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		d.push_back(x);
		f.push_back(y);
		if (n == x) {
			printf("%d\n", y);
			return 0;
		}
	}
	for (int i = 1; i <= 100; i++) {
		bool flag = true;
		for (int j = 0; j < m; j++) {
			if ((d[j] + i - 1) / i != f[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			int tmp = (n + i - 1) / i;
			if (ans != -1 && ans != tmp) {
				printf("-1\n");
				return 0;
			}
			ans = tmp;
		}
	}
	printf("%d\n", ans);
	// int l = 1, u = 1000;
	// int lar = 0;
	// for (int i = 0; i < m; i++) {
	// 	int d, f;
	// 	scanf("%d %d", &d, &f);
	// 	lar = max(lar, d);
	// 	// cout << (d / f) + (d % f ? 1 : 0) << " ";
	// 	// cout << (f == 1 ? u : ((d - 1) / (f - 1))) << endl;
	// 	if (n == d) {
	// 		printf("%d\n", f);
	// 		return 0;
	// 	}
	// 	l = max(l, (d + f - 1) / f);
	// 	u = (f == 1) ? u : min(u, (d - 1) / (f - 1));
	// }
	// if (u == 1000) {
	// 	if (n <= lar) {
	// 		printf("1\n");
	// 		return 0;
	// 	} else {
	// 		printf("-1\n");
	// 		return 0;
	// 	}
	// }
	// if (n / l + ((n % l) ? 1 : 0) == n / u + ((n % u) ? 1 : 0)) {
	// 	printf("%d\n", n / l + ((n % l) ? 1 : 0));
	// } else {
	// 	printf("-1\n");
	// }
	return 0;
}