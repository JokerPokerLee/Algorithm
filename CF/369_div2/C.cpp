#include <bits/stdc++.h>

#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

long long dp[2][110][110];
long long p[110][110];
int c[110];

int main() {
	freopen("1.in", "r", stdin);
	int n, m, K;
	cin >> n >> m >> K;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> p[i][j];
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	int now = 0, pre = 1;
	dp[now][0][0] = 0;
	for (int k = 1; k <= n; k++) {
		now = pre, pre ^= 1;
		for (int i = 1; i <= m; i++) {
			long long cost = c[k] ? 0 : p[k][i];
			for (int j = 1; j <= k; j++) {
				dp[now][i][j] = INF;
				if (c[k] && c[k] != i) {
					continue;
				}
				dp[now][i][j] = min(dp[now][i][j], dp[pre][i][j] + cost);
				for (int g = 0; g <= m; g++) {
					if (i == g) {
						continue;
					}
					dp[now][i][j] = min(dp[now][i][j], dp[pre][g][j - 1] + cost);
				}
			}
		}
		dp[now][0][0] = INF;
	}
	long long ans = INF;
	for (int i = 1; i <= m; i++) {
		ans = min(ans, dp[now][i][K]);
	}
	if (ans == INF) {
		cout << "-1" << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}