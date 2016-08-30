#include <bits/stdc++.h>

#define MOD 1000000007
#define N 200200

using namespace std;

int a[N], vis[N], fa[N];

int main() {
	freopen("1.in", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> fa[i];
	}
	a[0] = 1;
	for (int i = 1; i <= n; i++) {
		a[i] = 2LL * a[i - 1] % MOD;
	}
	int tot = 0;
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			continue;
		}
		int now = i;
		while (!vis[now]) {
			vis[now] = i;
			now = fa[now];
		}
		if (vis[now] == i) {
			int len = 1;
			int tmp = fa[now];
			while (tmp != now) {
				len++;
				tmp = fa[tmp];
			}
			tot += len;
			ans = 1LL * ans * (a[len] + MOD - 2) % MOD;
		}
	}
	ans = 1LL * ans * a[n - tot];
	cout << ans << endl;
	return 0;
}