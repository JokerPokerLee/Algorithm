#include <bits/stdc++.h>

using namespace std;

void dfs(int u) {
	for (int i = 0; out[u] == deg[u] / 2 && i < link[u].size(); i++) {
		int k = link[u][i].second;
		if (used[k] || ) {
			continue;
		}
		int v = link[u][i].first;
		if (edge[k].first != u) {
			rev[k] = true;
		}
		used[k] = true;
		out[u]++;
		in[v]++;
		if (mark[v]) {
			dfs(v);
		}
	}
}

int main() {
	freopen("1.in", "r", stdin);
	int ttt;
	scanf("%d", &ttt);
	while (ttt--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			in[i] = out[i] = 0;
			link[i].clear();
			mark[i] = false;
			deg[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			edge.push_back(MP(x, y));
			used[i] = false;
			rev[i] = false;
			link[x].push_back(MP(y, i));
			link[y].push_back(MP(x, i));
			deg[x]++, deg[y]++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!(deg[i] & 1)) {
				mark[i] = true;
				ans++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (mark[i]) {
				dfs(i);
			}
		}
	}
	return 0;
}