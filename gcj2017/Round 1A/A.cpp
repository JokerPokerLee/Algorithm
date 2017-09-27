#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("1.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		printf("Case #%d:\n", tt);
		int n, m;
		scanf("%d %d", &n, &m);
		char c[n + 1][m + 1];
		for (int i = 1; i <= n; i++) {
			scanf("%s", c[i] + 1);
		}
		char pre = '*';
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (c[i][j] != '?' && c[i][j] != pre) {
					int l = j - 1, r = j + 1, u = i - 1;
					while (l > 0 && c[i][l] == '?') l--;
					while (r <= m && c[i][r] == '?') r++;
					while (u > 0 && c[u][j] == '?') u--;
					for (int g = u + 1; g <= i; g++) {
						for (int h = l + 1; h < r; h++) {
							c[g][h] = c[i][j];
						}
					}
					pre = c[i][j];
				}
			}
			int t = m;
			while (c[i][t] == '?') t--;
			if (t > 0) {
				for (int j = t + 1; j <= m; j++) {
					c[i][j] = c[i][t];
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			int b = n;
			while (c[b][i] == '?') b--;
			for (int j = b + 1; j <= n; j++) {
				c[j][i] = c[b][i];
			}
		}
		for (int i = 1; i <= n; i++) {
			printf("%s\n", c[i] + 1);
		}
	}
	return 0;
}