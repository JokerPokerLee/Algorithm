#include <bits/stdc++.h>

using namespace std;

vector<int> link[100100];
bool vis[100100];
double ans = 0.0;

void dfs(int now, int len, double p) {
	vis[now] = true;
	int cnt = 0;
	for (int i = 0; i < link[now].size(); i++) {
		if (!vis[link[now][i]]) {
			cnt++;
		}
	}
	if (cnt == 0) {
		ans += len * p;
		return;
	}
	for (int i = 0; i < link[now].size(); i++) {
		if (!vis[link[now][i]]) {
			dfs(link[now][i], len + 1, p / cnt);
		}
	}
}

int main() {
	freopen("1.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		link[x].push_back(y);
		link[y].push_back(x);
	}
	dfs(1, 0, 1.0);
	printf("%.10f\n", ans);
	return 0;
}